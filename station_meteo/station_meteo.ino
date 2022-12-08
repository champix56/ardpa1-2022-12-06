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
  humidityLoop(&datas.humidity.rhumidity,&datas.humidity.temp,false);
  timeLoop(&datas.time);
  Serial.print(F("humidity:"));
  Serial.print(datas.humidity.rhumidity);
  Serial.print(F(",temp:"));
  Serial.println(datas.humidity.temp);

}
