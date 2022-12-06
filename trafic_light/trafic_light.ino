#define GREEN_PIN 6
#define YELLOW_PIN 5
#define RED_PIN 4
#define PAS_CAN 5.0F/1024.0F
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
}

void loop() {
  uint16_t canValue=analogRead(A0);
  float tensionEnAo=canValue*PAS_CAN;
  
  Serial.print(canValue);
  Serial.print("\ttension en A0 : ");
  Serial.print(tensionEnAo);
  Serial.println("Volts");
  
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
