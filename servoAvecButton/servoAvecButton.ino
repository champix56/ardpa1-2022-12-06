#define BUTTON_PIN 2
#define PAS_SERVO 10
// include the Servo library
#include <Servo.h>

Servo myServo;  // create a servo object

volatile bool buttonState = false;
bool sensHoraire = true;
void interruptionButton() {
  noInterrupts();
  buttonState = true;
}
void setup() {
  // put your setup code here, to run once:
  myServo.attach(13);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), interruptionButton, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (buttonState) {
    uint8_t angle = myServo.read();
    if (angle + PAS_SERVO <= 180 && sensHoraire) {
      angle += PAS_SERVO;
    } 
    else if (angle + PAS_SERVO > 180 && sensHoraire == true) {
      sensHoraire = false;
      angle -= PAS_SERVO;
    }
    else if(angle - PAS_SERVO >=0 && !sensHoraire )
    {
      angle -= PAS_SERVO;
    }
     else if (angle - PAS_SERVO <0 && sensHoraire == false) {
      sensHoraire = true;
      angle += PAS_SERVO;
    }
    myServo.write(angle);
    interrupts();
    delay(200);
  }
}
