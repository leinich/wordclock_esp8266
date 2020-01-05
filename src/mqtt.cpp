#include "mqtt.h"

static Ticker MQTTTimer(MQTTUpdate, 60000);

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

uint32 lastChecksum = 0;

String cmdTopic, stateTopic;
char *mqtt_user = NULL;
char *mqtt_pass = NULL;

void MQTTUpdate(){    
    MQTTPublish(); 
}

boolean MQTTReconnect(){
    if(!mqttClient.connected()) {     
        WebLogInfo("Attempting MQTT connection...");        
        if (mqttClient.connect(settings.m_client_id, mqtt_user, mqtt_pass)) { 
            WebLogInfo("Connect succeeded");      
            mqttClient.subscribe(cmdTopic.c_str());
            WebLogDebug("subscribe to " + String(cmdTopic)); 
        } else {
            WebLogError("Connect failed, rc=" + String(mqttClient.state()));                  
        }        
    }  
    return mqttClient.connected();
}

String MQTTStatus(){    
    if(mqttClient.connected()){
        return F("Connected");
    }else{
        return "not Connected, rc=" + String(mqttClient.state());
    }    
}

void MQTTTick(){  
    MQTTTimer.update();
    mqttClient.loop();
    
    if(lastChecksum != SettingsGetChecksum()){
        MQTTPublish();  
        lastChecksum = SettingsGetChecksum();
    }    
}



void MQTTSubCallback(char* topic, byte* payload, unsigned int length) {
    uint8   validCmd = 0;
    uint8   validValue = 0;
    String  command = String(strrchr(topic, '/')).substring(1);

    payload[length] = '\0'; //terminate that nasty boy    
    String value = String((char *)payload);  
    
    uint8_t intValue = (uint8)value.toInt();
    if(command.equalsIgnoreCase(U_ONOFF_TAG)){
        validCmd = 1;
        if(length > 0 && intValue <= 1){                        
            validValue = 1;
        }        
    }

    if(command.equalsIgnoreCase(C_BRIGHTNESS_TAG)){
        validCmd = 1;
        if(length > 0 && intValue <= 31){                        
            validValue = 1;
        }        
    }

    if(command.equalsIgnoreCase(C_MODE_TAG)){
        validCmd = 1;
        if(length > 0 && intValue <= 6){                        
            validValue = 1;
        }        
    }

    if(command.equalsIgnoreCase(D_MODE_TAG)){
        validCmd = 1;
        if(length > 0 && intValue <= 3){                        
            validValue = 1;
        }        
    }

    if(command.equalsIgnoreCase(D_TEMP_TAG)){
        validCmd = 1;
        if(length > 0 && length <= 2){    
            SettingsSetValue(D_MODE_TAG,String(DRAW_MODE_TEMP));            
            validValue = 1;                    
        }
    }

    if(command.equalsIgnoreCase(D_TEXT_TAG)){
        validCmd = 1;
        if(length > 0 && length < 255){    
            SettingsSetValue(D_MODE_TAG,String(DRAW_MODE_TEXT));            
            validValue = 1;                    
        }
    }

    if(validCmd == 1 && validValue == 1){
        SettingsSetValue(command,value);
        WebLogInfo(String(topic) + " = " +  value);        
    }
    if(validCmd == 0){
        WebLogInfo("MQTT invalid Command " + command + " : " +  value + ".");
    }
    if(validValue == 0){
        WebLogInfo("MQTT invalid Value " + command + " : " +  value + ".");
    }
}

void MQTTPublish() {    
    if(MQTTReconnect()){        
        WebLogInfo(stateTopic + " = " + SettingsToJson());
        mqttClient.publish(stateTopic.c_str(),SettingsToJson().c_str());           
    }    
}

void MQTTInit(){
  if (strlen(settings.m_user) > 0) mqtt_user = settings.m_user;
    if (strlen(settings.m_pass) > 0) mqtt_pass = settings.m_pass;

    if(strlen(settings.m_topic) > 0 && strlen(settings.m_client_id) > 0 && strlen(settings.m_host) > 0 && settings.m_port > 0){
        cmdTopic = String(MQTT_TOPIC_PREFIX + String(settings.m_topic) + MQTT_CMD_TOPIC);
        stateTopic = String(MQTT_TOPIC_PREFIX + String(settings.m_topic) + MQTT_STATE_TOPIC);
                
        mqttClient.setServer(settings.m_host, settings.m_port);
        mqttClient.setCallback(MQTTSubCallback);
        MQTTTimer.start();

        MQTTPublish();
    }else{
        WebLogError("MQTT Missing Parameter"); 
    }
}


