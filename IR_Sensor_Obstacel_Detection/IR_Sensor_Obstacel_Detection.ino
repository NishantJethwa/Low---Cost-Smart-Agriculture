int IR1 = 2;
int IR2 = 4 ;
int led=13;
int counter=0;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val1 = analogRead(IR1);
  int val2=  analogRead(IR2);
  if(val1<500)
  {
    digitalWrite(led,HIGH);
    counter+=1;
  }
  else
  {
    digitalWrite(led,LOW);
  }
  if(val2<500)
  {
    digitalWrite(led,HIGH);
    counter-=1;
  }
  else
  {
    digitalWrite(led,LOW);
  }
  
  Serial.println(counter);
  
}

// Here IR sensor is send the wave(in unit of frequency) so when the value was in range '2000' that means that entire light is going whereas when there is obstacel at that time receiver is receiving some light emmited by IR senosor so the value ranges range of '0'
// LED will blink when there is an obstacel in between
