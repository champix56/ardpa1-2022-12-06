

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  screenSetup();
  humiditySetup();
  screenShowStartupScreen();
  Serial.println(F("METEO STATION\nstarted"));
  delay(2000);
}

void loop() {
  humidityLoop();
}
