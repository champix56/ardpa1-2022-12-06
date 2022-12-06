#define GREEN_PIN 6
#define YELLOW_PIN 5
#define RED_PIN 4
#define PAS_CAN 5.0F/1024.0F
void setup() {
  // put your setup code here, to run once:

  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
}

void loop() {
  uint8_t canValue=analogRead(A0);
  // put your main code here, to run repeatedly:
  digitalWrite(RED_PIN, HIGH);
  delay(500);
  digitalWrite(YELLOW_PIN, HIGH);
  delay(500);
  digitalWrite(GREEN_PIN, HIGH);
  delay(500);
  digitalWrite(RED_PIN, LOW);
  delay(500);
  digitalWrite(YELLOW_PIN, LOW);
  delay(500);
  digitalWrite(GREEN_PIN, LOW);
  delay(500);
}
