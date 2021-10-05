void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  int measurement = 0;
measurement = hallRead();
  Serial.print("Hall sensor measure: ");
  Serial.println(measurement);
  
  delay(1000);
}

//baud rate is the speed at which data is transfered between ESP32 and laptop.
