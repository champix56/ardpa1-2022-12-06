#include "config.h"
#ifdef BMP180
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;
bool pressureSetup() {
  return bmp.begin();
}
void pressureRead(struct S_Pressure *pressure) {
  //  *(pressure).hectoPascal=
  pressure->hectoPascal = (uint16_t)(bmp.readPressure() / 100);
  pressure->alt = bmp.readAltitude();
}
#endif