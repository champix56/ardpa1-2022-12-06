#include "config.h"
#include "structs.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  #ifdef ST7735
    screenSetup();
    screenShowStartupScreen();
  #endif
  #ifdef BMP180
    pressureSetup();
  #endif
  #ifdef SD_CSV
    sdSetup();
  #endif
  #ifdef S_DHT11
    humiditySetup();
  #endif
  #ifdef DS1307
    timeSetup();
  #endif
  
  Serial.println(F("METEO STATION\nstarted"));

  #ifdef ST7735
  delay(2000);
  screenShowMainScreen();
  #endif
}

void loop() {
  S_Datas datas;
  
  #ifdef S_DHT11
    humidityLoop(&datas.humidity.rhumidity, &datas.humidity.temp, false);
    #ifdef ST7735
      refreshHumidity(datas.humidity.rhumidity);
      refreshTemperature(datas.humidity.temp);
    #endif
  #endif
  #ifdef DS1307
    timeLoop(&datas.time);
    #ifdef ST7735
      refreshTime(datas.time);
    #endif
  #endif
  #ifdef BMP180
    pressureRead(&datas.pressure);
  #endif
  char str[33] = "";
  formatDatasStr(datas, str);
  Serial.print(str);

  #ifdef SD_CSV  
  char date[11]="";
  sprintf(date,"%4d-%02d-%02d", (datas.time.Year + 1970),
          datas.time.Month,
          datas.time.Day);
    sdWriteDatas(date,str);
  #endif
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