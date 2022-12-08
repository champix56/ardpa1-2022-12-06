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
  delay(930);
}
uint8_t formatDatasStr(S_Datas datas, char buffer[]) {
  char buffRh[6] = "";
  char buffTemp[6] = "";
  //yyyy-mm-ddThh:mm:ss;rr.rr;tt.tt\n
  //ecriture du temps au format YYYY-MM-DDTHH:mm:ss;
  sprintf(buffer, "%4d-%02d-%02dT%02d:%02d:%02d;%5s;%5s\n",
          (datas.time.Year + 1970),
          datas.time.Month,
          datas.time.Day,
          datas.time.Hour,
          datas.time.Minute,
          datas.time.Second,
          dtostrf(datas.humidity.rhumidity, 2, 2, buffRh),
          dtostrf(datas.humidity.temp, 2, 2, buffTemp));

  //format decimal to buffer string
  //dtostrf(datas.humidity.rhumidity, 2, 2, buffFloat);
  //concat buffFloat vers buffer
  //strcat(buffer,buffFloat);
  //taille (en nb de caracteres) d'une chaine
  return strlen(buffer);
}