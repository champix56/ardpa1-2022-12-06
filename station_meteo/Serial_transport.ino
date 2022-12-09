#include "config.h"
//protection en cas de definition multiple des 2 types diff. en meme temps (2 define concurent actif)
#if defined(SERIAL_TRANSPORT_TRANSMITER) && defined(SERIAL_TRANSPORT_RECIEVER)
//desactivation d'un des deux
  #undef SERIAL_TRANSPORT_RECIEVER
#endif
#if defined(SERIAL_TRANSPORT_TRANSMITER)||defined(SERIAL_TRANSPORT_RECIEVER)
  #include "structs.h"
  #define SERIAL_TRANSPORT
  #define SERIAL_TRANSPORT_SPEED 9600
  #include <SoftwareSerial.h>
  SoftwareSerial mySerial(5, 6); // RX, TX
  void serialTransportSetup(){
    mySerial.begin(SERIAL_TRANSPORT_SPEED);
  }
  void serialTransportLoop(S_Datas *datas){
    union U_Datas udatas;
    udatas.datas=*datas;
      #ifdef SERIAL_TRANSPORT_TRANSMITER
        //code emit
        for(int i=0;i<sizeof(struct S_Datas);i++){
          mySerial.write(udatas.bytesTab[i]);
        }
        delay(100);
      #endif
      #ifdef SERIAL_TRANSPORT_RECIEVER
      //code recept.
        Serial.flush();
        while(!mySerial.available()){;}
        delay(50);
        int i=0;
        while(mySerial.available()){
          udatas.bytesTab[i]= mySerial.read();
          i++;
        }
        *datas=udatas.datas;
      #endif
  }
#endif