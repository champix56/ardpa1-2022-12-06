#define GREEN_PIN 6
#define YELLOW_PIN 5
#define RED_PIN 4
#define PAS_CAN 5.0F / 1024.0F
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  digitalWrite(RED_PIN, TRUE);
}

void loop() {
  bool isPushed = digitalRead(7);
  if (isPushed) {
    uint16_t canValue = analogRead(A0);
    float tensionEnAo = canValue * PAS_CAN;

    Serial.print(canValue);
    Serial.print("\ttension en A0 : ");
    Serial.print(tensionEnAo);
    Serial.println("Volts");
    uint16_t tempsDelay = (3000.0F / 1024.0F) * canValue;
    // put your main code here, to run repeatedly:
    sequencePietons(tempsDelay);
  }
  delay(5000);
}
void sequencePietons(uint16_t tempsDelay) {
  delay(800);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(RED_PIN, LOW);
  delay(800);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  delay(tempsDelay);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  delay(800);
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
}
