# Wordclock based on an ESP8266 / WS2812
![front_an](img/front_an.jpg)

## Hardware:
- LDR with voltagedevider on A0 
- WS2812 via levelshifter on RXD0 

![wiring1](img/schematics.JPG)

## Supported Layouts:
#Ikeahacker caschoff.de (page gone):
ES_IST_FÜNF
ZEHNZWANZIG
DREIVIERTEL
NACHFUNKVOR  
HALB_ELFÜNF
EINS___ZWEI
DREI___VIER
SECHS__ACHT
SIEBENZWÖLF
ZEHNNEUNUHR

#ulrichradig.de (project gone):
ES_IST_FÜNF
ZEHNZWANZIG
DREIVIERTEL
__NACHVOR__  
HALB_ZWÖLF_
ZWEINSIEBEN
_DREI__FÜNF
ELFNEUNVIER
_ACHTZEHN__
_SECHS_UHR_

#mikrocontroller.net:
ES_IST_FÜNF
ZEHNZWANZIG
DREIVIERTEL
__NACHVOR__  
HALB_ZWÖLF_
ZWEINSIEBEN
_DREI__FÜNF
ELFNEUNVIER
_ACHTZEHN__
_SECHS__UHR

## Features:
- defineable hardware layout (leds.h)
- word fading
- display hour and minutes
- display seconds
- display temperature
- 8 different color modes with HUE rotate
- wifimanger
- Webserver http://deviceip:80 ( inspired by Tasmota and tzapu/wifimanager )
- OTA
- mdns
- Websocket Webconsole
- NTP time client
- MQTT Sub: ON/OFF && BRIGHTNESS && COLORMODE && DISPLAYMODE (Non persistent)
- MQTT Pub: current config as JSON to broker
- LDR driven brightness

### planned improvements
- tempsensor implementation


## Images
![front_blank](img/front_blank.jpg)
![front](img/front.jpg)
![menu1](img/menu1.JPG)
![menu21](img/menu2_1.JPG)
![menu22](img/menu2_2.JPG)
![menu3](img/menu3.JPG)
![menu4](img/menu4.JPG)
![menu5](img/menu5.JPG)
![wiring2](img/drahtverhau.jpg)





