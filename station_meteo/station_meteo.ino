/*librairies inclues*/
#include "DHT.h"
#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <SPI.h>
/*config de pin et de materiel DHT*/
#define TFT_CS 10
#define TFT_RST 9  // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 8
#define DHTPIN 2
#define DHTTYPE DHT11

/*instance composant manipulables*/
DHT dht(DHTPIN, DHTTYPE);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  /*initialisation de l'ecran*/
  tft.initR(INITR_BLACKTAB);  // Init ST7735S chip, black tab
  tft.fillScreen(ST77XX_BLACK);
  tft.setRotation(0);
  tft.setCursor(20, 30);
  tft.setTextSize(3);
  tft.setTextColor(ST77XX_CYAN);
  tft.println("METEO");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(20, 60);
  tft.println("station");
  /*initialisation du composant DHT11*/
  dht.begin();
  tft.setTextSize(1);
  tft.setCursor(35,100);
  tft.setTextColor(ST77XX_RED);

  tft.println("DHT ready");
  Serial.println(F("METEO STATION"));
  delay(2000);  
}

void loop() {
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
