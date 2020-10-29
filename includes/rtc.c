RTC_DS3231 rtc;

int pegarTimeStamp(){
    DateTime now = rtc.now();
    int x = now.unixtime();
    return x;
}