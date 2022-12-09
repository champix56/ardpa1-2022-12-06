#ifndef _STRUCTS_H_
#define _STRUCTS_H_
#include <TimeLib.h>

struct S_Humidity {
  float temp;
  float rhumidity;
};
struct S_Pressure {
  int16_t alt;
  uint16_t hectoPascal;
};
typedef struct S_Datas {
  struct S_Humidity humidity;
  struct S_Pressure pressure;
  tmElements_t time;
};

//typedef struct S_Data tmData;
//si usage de tmData datas pour la decla
#endif