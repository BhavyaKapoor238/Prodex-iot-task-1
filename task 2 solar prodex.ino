// C++ code
  #include <Servo.h>

Servo servoH;
Servo servoV;  

int pinTL = A0; 
int pinTR = A1; 
int pinBL = A2; 
int pinBR = A3; 

int angleH = 90; 
int angleV = 90; 

int diffLimit = 20; 

void setup() {
  Serial.begin(9600);
  
  servoH.attach(10);
  servoV.attach(9);
  
  servoH.write(angleH);
  servoV.write(angleV);
}

void loop() {
  int topL = analogRead(pinTL);
  int topR = analogRead(pinTR);
  int botL = analogRead(pinBL);
  int botR = analogRead(pinBR);
  
  int topAvg = (topL + topR) / 2;
  int botAvg = (botL + botR) / 2;
  int leftAvg = (topL + botL) / 2;
  int rightAvg = (topR + botR) / 2;

  int diffV = topAvg - botAvg;
  if (abs(diffV) > diffLimit) {
    if (topAvg > botAvg) {
      angleV++;
    } else {
      angleV--;
    }
    servoV.write(angleV);
  }

  int diffH = leftAvg - rightAvg;
  if (abs(diffH) > diffLimit) {
    if (leftAvg > rightAvg) {
      angleH--; 
    } else {
      angleH++;
    }
    servoH.write(angleH);
  }

  delay(100);
}
