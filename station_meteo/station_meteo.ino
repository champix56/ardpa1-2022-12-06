

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  screenSetup();
  humiditySetup();
  screenShowStartupScreen();
  Serial.println(F("METEO STATION\nstarted"));
  delay(2000);
}

void loop() {
  float r,t;
  humidityLoop(&r,&t,false);
  Serial.print(F("humidity:"));
  Serial.print(r);
  Serial.print(F(",temp:"));
  Serial.println(t);

}
