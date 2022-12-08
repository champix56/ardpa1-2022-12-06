#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <SPI.h>
/*config de pin et de materiel DHT*/
#define TFT_CS 10
#define TFT_RST 9  // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 8

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
/**
* fonction setup de l'ecran ST7735
*/
void screenSetup() {
  /*initialisation de l'ecran*/
  tft.initR(INITR_BLACKTAB);  // Init ST7735S chip, black tab
  tft.fillScreen(ST77XX_BLACK);
  tft.setRotation(0);
}
void screenShowStartupScreen() {
  tft.setCursor(20, 30);
  tft.setTextSize(3);
  tft.setTextColor(ST77XX_CYAN);
  tft.println("METEO");
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(20, 60);
  tft.println("station");
  //dht text
  tft.setTextSize(1);
  tft.setCursor(35, 100);
  tft.setTextColor(ST77XX_RED);
  tft.println("DHT ready");
}