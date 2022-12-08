#include "structs.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  screenSetup();
  humiditySetup();
  timeSetup();
  screenShowStartupScreen();
  Serial.println(F("METEO STATION\nstarted"));
  delay(2000);
}

void loop() {
  S_Datas datas;
  humidityLoop(&datas.humidity.rhumidity, &datas.humidity.temp, false);
  timeLoop(&datas.time);
  char str[33] = "";
  formatDatasStr(datas, str);
  Serial.print(str);
}
uint8_t formatDatasStr(S_Datas datas, char buffer[]) {
  //yyyy-mm-ddThh:mm:ss;rr.rr;tt.tt\n
  //ecriture du temps au format YYYY-MM-DDTHH:mm:ss;
  uint8_t length = sprintf(buffer, "%4d-%02d-%02dT%02d:%02d:%02d;",
                           (datas.time.Year + 1970),
                           datas.time.Month,
                           datas.time.Day,
                           datas.time.Hour,
                           datas.time.Minute,
                           datas.time.Second);
  
  return length;
}