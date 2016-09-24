#include <SoftwareSerial.h>
#define BT 5
//This is vars for Sensor

//bluetooth var
String myString = "";
int blueTx = 5;
int blueRx = 6;
SoftwareSerial mySerial(blueTx,blueRx);

void setup() {
  // put your setup code here, to run once:
  
  //bluethooh
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char my;
  while(Serial.available()){
    my = (char)Serial.read();
    myString += my;
    delay(BT);
  }
  if(!myString.equals("e")){
    Serial.printf("Input Value : %s", myString);
    myString = "";
  }
}
