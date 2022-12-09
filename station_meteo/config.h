#ifndef __CONFIG_H__
#define __CONFIG_H__
  // Units model
  //#define SENSOR_TRANSMITTER
  #define SCREEN_RECIEVER

  #ifdef SENSOR_TRANSMITTER
    #undef SCREEN_RECIEVER
    #define BMP180
    #define DS1307
    #define S_DHT11
    #define SERIAL_TRANSPORT_TRANSMITER
  #endif
  #ifdef SCREEN_RECIEVER
    #undef SENSOR_TRANSMITTER
    #define ST7735
    #define SD_CSV
    #define SERIAL_TRANSPORT_RECIEVER
  #endif

/*force component to be add to project*/
  /*sensors*/
  //#define BMP180
  //#define DS1307
  //#define S_DHT11
  /*data*/
  //#define ST7735
  //#define SD_CSV
  /*communication*/
  //#define SERIAL_TRANSPORT_RECIEVER
  //#define SERIAL_TRANSPORT_TRANSMITER
#endif