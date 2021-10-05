#include <WiFi.h>                                                 
#include <IOXhop_FirebaseESP32.h>
// Set these to run example.

#define FIREBASE_HOST "https://smart-agriculture-445ad.firebaseio.com/"
#define FIREBASE_AUTH "kt1dipfm1uosl1umKPUqWnTemmQHLy4WFrL5KuBE"
#define WIFI_SSID "AndroidA"
#define WIFI_PASSWORD "heyitmee"
#define LED 12

int IR1 = 33;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(LED,OUTPUT);

digitalWrite(LED,0);

WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

Serial.print("connecting");

while (WiFi.status() != WL_CONNECTED) {

Serial.print(".");

delay(500);
}
Serial.println();

Serial.print("connected: ");

Serial.println(WiFi.localIP());

Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

//Firebase.setInt("LEDStatus2",0);

}

void loop() {
  // put your main code here, to run repeatedly:
  String light2 = Firebase.getString("LEDStatus2");
  int val1 = analogRead(IR1);
  
  if(val1<500)
  {
    digitalWrite(LED,HIGH);
    Firebase.setString("LEDStatus2","ON");
  }
  else
  {
    digitalWrite(LED,LOW);
    Firebase.setString("LEDStatus2","OFF");
  }
    Serial.println(light2);
}

// Here IR sensor is send the wave(in unit of frequency) so when the value was in range '2000' that means that entire light is going whereas when there is obstacel at that time receiver is receiving some light emmited by IR senosor so the value ranges range of '0'
// LED will blink when there is an obstacel in betweenvoid setup() {
  // put your setup code here, to run once:
