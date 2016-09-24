#include <Servo.h>
#include <SoftwareSerial.h>
//This is vars for Sensor
#define TRIG 2 
#define ECHO 3
#define MT 2000
//This is const for bluetooth
#define BT 5
//We will use mortor to 4pin

Servo servo;
int who=0,cnt=0;
//8 is green 9 is red
int ledpin[2] = {8,9}; 
boolean isNear = false;
//bluetooth var
String myString = "";
int blueTx = 5;
int blueRx = 6;
SoftwareSerial mySerial(blueTx,blueRx);

void setup() {
  // put your setup code here, to run once:
  //LED ON
  pinMode(ledpin[0],OUTPUT);
  pinMode(ledpin[1],OUTPUT);
  digitalWrite(ledpin[0], HIGH);
  //This is for sensor 
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO,INPUT);
  //This is for motor control pin number
  servo.attach(4);
  servo.write(180);
  //This is code for random maker
  who = 1+random(10);
  cnt = 0;

  //bluethooh
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   //conrol the sensor 
  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIG,LOW); 
  digitalWrite(ledpin[0], HIGH);
  long distance = pulseIn(ECHO,HIGH)/58;

  //control the bluetooth
  char my;
  while(Serial.available()){
    my = (char)Serial.read();
    myString += my;
    delay(BT);
  }
  if(!myString.equals("e")){
    Serial.println("Input Value : "myString);
    myString = "";
  }
  
  //Check the man is near and main function
  /*if(myString.equals("s")){
    if(distance<5 && isNear){
      if(cnt == who){
        servo.write(0);
        digitalWrite(ledpin[0],LOW);
        digitalWrite(ledpin[1],HIGH);
        //who = random(10);
        //cnt=0;
      } else if(isNear){
        ++cnt;
        isNear = false;
      }
    } else{
      if(!isNear && distance>5){
        isNear = true;
      }
    }
  }*/
}
