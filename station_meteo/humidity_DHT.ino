/*librairies inclues*/
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

/*instance composant manipulables*/
DHT dht(DHTPIN, DHTTYPE);

void humiditySetup(){
  /*initialisation du composant DHT11*/
  dht.begin();
}
void humidityLoop()
{
   // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
}