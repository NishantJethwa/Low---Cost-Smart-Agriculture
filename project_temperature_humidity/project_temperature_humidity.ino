#include <WiFi.h>                                                 
#include <IOXhop_FirebaseESP32.h>
// Set these to run example.

#define FIREBASE_HOST "https://iot-pune.firebaseio.com/"
#define FIREBASE_AUTH "avjSiyJZs868zXapXmIScf0wCPKjuwlLrIyZsj8y"
#define WIFI_SSID "Realme"
#define WIFI_PASSWORD "12345678"
#define LED 2

#include "DHT.h"
#define DHTPIN 25             // this was changed from 33 to 34
#define DHTTYPE DHT11    
DHT dht(DHTPIN, DHTTYPE);
const int ledPin = 13;
const int ldrPin = 33;

const int watermeterPin = 15;   //15 was working

volatile int  pulse_frequency;
unsigned int  literperhour;
unsigned long currentTime, loopTime;
byte sensorInterrupt = 12;            // this is for soil

int relayPin = 23;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
  Serial.begin(9600);

  pinMode(relayPin, OUTPUT);

WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

Serial.print("connecting");

while (WiFi.status() != WL_CONNECTED) {

Serial.print(".");

delay(500);

pinMode(watermeterPin, INPUT);
   Serial.begin(9600); 
   attachInterrupt(sensorInterrupt, getFlow, FALLING);
                                     
   currentTime = millis();
   loopTime = currentTime;
}

Serial.println();

Serial.print("connected: ");

Serial.println(WiFi.localIP());

Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
//Firebase.setInt("temp",0);
//Firebase.setInt("hum",0);
//Firebase.setInt("literperhour",0);
}


void loop() {
  // put your main code here, to run repeatedly:
  delay(2000);
  
  float ldrStatus = analogRead(ldrPin);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float sensorValue = analogRead(35);
  
  if(sensorValue == 4095)
  {
    digitalWrite(relayPin,HIGH);
    }
    else
    {
      delay(1000);
      digitalWrite(relayPin,LOW);
      }
  
   currentTime = millis();
   if(currentTime >= (loopTime + 1000))
   {
      loopTime = currentTime;
      literperhour = (pulse_frequency * 60 / 7.5);
      pulse_frequency = 0;
      Serial.print(literperhour, DEC);
      Serial.println(" Liter/hour");
   }

 
  Serial.print("Humidity ");
  Serial.println(h);
  Serial.print("Temperature: ");
  Serial.println(t);
  Serial.print("LDR Status: ");
  Serial.println(ldrStatus);
  Serial.print("Soil Mositure: ");
  Serial.println(sensorValue);
  Serial.print("Water Sensor: ");
  Serial.println(literperhour);

  
  
  Firebase.setFloat("iot-punr-test/temp",t);
Serial.println(t);

  Firebase.setFloat("iot-punr-test/hum",h);
Serial.println(h);

  Firebase.setFloat("iot-punr-test/LDR",ldrStatus);
Serial.println(ldrStatus);

Firebase.setFloat("iot-punr-test/Soil Moisture",sensorValue);
Serial.println(sensorValue);

Firebase.setFloat("iot-punr-test/Water Sensor",literperhour);
Serial.println(literperhour);

}


void getFlow ()
{ 
   pulse_frequency++;
} 
