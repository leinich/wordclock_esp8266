#include "timeNTP.h"

static WiFiUDP wifiUdp;
static NTP ntp(wifiUdp);

void TimeInit(){
    ntp.ntpServer("pool.ntp.org"); //TODO aus config
    ntp.updateInterval(60000); //TODO aus config
    ntp.ruleDST("CEST", Last, Sun, Mar, 2, 120); // last sunday in march 2:00, timetone +120min (+1 GMT + 1h summertime offset)
    ntp.ruleSTD("CET", Last, Sun, Oct, 3, 60); // last sunday in october 3:00, timezone +60min (+1 GMT)  
    ntp.begin();
}

void TimeTick(){
    ntp.update();
}

uint8 TimeSeconds(){
    return ntp.seconds();
}

uint8 TimeMinutes(){
    return ntp.minutes();
}

uint8 TimeHours(){
    return ntp.hours();
}

uint8 TimeDay(){
    return ntp.day();
}

uint8 TimeMonth(){
    return ntp.month();
}

uint16 TimeYear(){
    return ntp.year();
}