//This code will detect the Temperature of the ESP 32 Board.

#ifdef __cplusplus
extern "C"{
  #endif
  uint8_t temprature_sens_read();  // It written in library of esp 32 somewhere and we are calling it here 
  #ifdef __cplusplus
  }
#endif
uint8_t temprature_sens_read();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Convert raw temp in F to Celsius degrees
  Serial.print("emperature: ");
  Serial.print((temprature_sens_read() - 32)/1.8);
  Serial.println(" C");
  delay(5000);
}
