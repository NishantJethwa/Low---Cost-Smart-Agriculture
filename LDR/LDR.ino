const int ledPin = 13;
const int ldrPin = 33;
void setup() {
 Serial.begin(9600);
}
void loop() {
int ldrStatus = analogRead(ldrPin);
delay(3000);
Serial.println(ldrStatus);
}
