#include "config.h"
#ifdef DS1307
#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>

void timeSetup() {
}
/**
  * fonction de lecture du composant de temps
  * @return int8_t read state 
  * -1 si pas de puce a l'adresse du composant\n
  *  0 si puce pas mis a l'heure
  *  1  si OK
  */
int8_t timeLoop(tmElements_t *tm) {
  if (RTC.read(*tm)) {
    return 1;
  } else {
    if (RTC.chipPresent()) {
      return 0;
    } else {
      return -1;
    }
  }
}
#endif