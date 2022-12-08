#include "structs.h"
#include "screen_ST7735_positions.h"
#include <Adafruit_GFX.h>     // Core graphics library
#include <Adafruit_ST7735.h>  // Hardware-specific library for ST7735
#include <SPI.h>

/*config de pin et de materiel DHT*/
#define TFT_CS 10
#define TFT_RST 9  // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 8

#define ST77XX_DARKGREEN 0x02C9
#define ST77XX_DARKCYAN 0x06DF
#define ST77XX_DARKPINK 0xb850
#define BACKGROUND_COLOR ST77XX_DARKGREEN
#define FOREGROUND_COLOR ST77XX_WHITE
//RGB 565 color picker 86f9
//https://chrishewett.com/blog/true-rgb565-colour-picker/

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
/**
* fonction setup de l'ecran ST7735
*/
void screenSetup() {
  /*initialisation de l'ecran*/
  tft.initR(INITR_BLACKTAB);  // Init ST7735S chip, black tab
  tft.fillScreen(BACKGROUND_COLOR);
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
void screenShowMainScreen() {
  tft.fillScreen(BACKGROUND_COLOR);
  tft.fillRect(0, 0, tft.width(), 8, ST77XX_DARKPINK);
  tft.fillRect(SCREEN_POSITION_TIME_X, SCREEN_POSITION_TIME_Y, SCREEN_POSITION_TIME_W, SCREEN_POSITION_TIME_H, SCREEN_BACKCOLOR_TIME);
  placeHalfWidthCadre(SCREEN_POSITION_HUMIDITY_X,SCREEN_POSITION_HUMIDITY_Y, "RH%", "%");
  placeHalfWidthCadre(SCREEN_POSITION_TEMP_X,SCREEN_POSITION_TEMP_Y, "TEMP", "c");
}
void placeHalfWidthCadre(uint8_t x, uint8_t y, char* titre, char* unite) {
  uint8_t width = tft.width() / 2 - 4;
  uint8_t height = 45 - 2;
  tft.drawRect(x + 1, y + 2, width, height, FOREGROUND_COLOR);
  tft.setTextColor(FOREGROUND_COLOR);
  tft.setTextSize(1);
  tft.setCursor(x + 10, y + 5);
  tft.print(titre);
  tft.setTextSize(1);
  tft.setCursor(x + width - 10, y + height - 10);
  tft.print(unite);
}
void refreshValueInHalfWidthCadre(uint8_t x, uint8_t y, char* value, uint8_t width) {
  tft.fillRect(x + 5, y + 45 - 30, width, 20, BACKGROUND_COLOR);
  tft.setTextSize(2);
  tft.setTextColor(FOREGROUND_COLOR);
  tft.setCursor(x+5, y + 45 - 30);
  tft.print(value);
}
void refreshTime(tmElements_t tm) {

  tft.setTextSize(1);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(SCREEN_POSITION_TIME_X + 7, SCREEN_POSITION_TIME_Y + 2);
  char buff[6] = "";
  sprintf(buff, "%02d:%02d", tm.Hour, tm.Minute);
  tft.fillRect(SCREEN_POSITION_TIME_X, SCREEN_POSITION_TIME_Y, SCREEN_POSITION_TIME_W, SCREEN_POSITION_TIME_H, SCREEN_BACKCOLOR_TIME);

  tft.print(buff);
}
void refreshHumidity(float rh){
  char tmp[6]="";
  refreshValueInHalfWidthCadre(SCREEN_POSITION_HUMIDITY_X,SCREEN_POSITION_HUMIDITY_Y,dtostrf(rh,2,1,tmp),50);
}
void refreshTemperature(float temp){
  char tmp[6]="";
  refreshValueInHalfWidthCadre(SCREEN_POSITION_TEMP_X,SCREEN_POSITION_TEMP_Y,dtostrf(temp,2,1,tmp),50);
}
// void screenLoop(S_Datas datas) {
//   refreshTime(datas.time);
//   char buff[6] = "";
//   dtostrf(datas.humidity.rhumidity, 2, 2, buff);
//   refreshValueInHalfWidthCadre(0, 20, buff, 20);
//   dtostrf(datas.humidity.temp, 2, 2, buff);
//   refreshValueInHalfWidthCadre(tft.width() / 2 - 1, 20, buff, 20);
//}