/*librairies inclues*/
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

/*instance composant manipulables*/
DHT dht(DHTPIN, DHTTYPE);

void humiditySetup() {
  /*initialisation du composant DHT11*/
  dht.begin();
}
void humidityLoop(float *rhumidity, float *temp, bool isFahrenheit ) {
  // put your main code here, to run repeatedly:
   *rhumidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
   *temp = dht.readTemperature(isFahrenheit);
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //pas utilisé ->float f = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again).
  if (isnan(*rhumidity) || isnan(*temp) ) {//pas utilisé ->|| isnan(f)
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
}