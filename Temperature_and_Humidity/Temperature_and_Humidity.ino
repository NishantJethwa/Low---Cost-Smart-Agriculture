#include "DHT.h"

#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Humidity ");
  Serial.println(h);
  Serial.print("Temperature: ");
  Serial.println(t);
}
