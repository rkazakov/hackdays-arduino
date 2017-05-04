#include <Servo.h>

Servo servoPan, servoTilt, servoFire;

int servoMin = 20;
int servoMax = 160;

void setup() {
  servoPan.attach(9); 
  servoTilt.attach(3);
  
//  servoFire.attach(11);
//  servoFire.write(90);
}

void loop() {
//  servoFire.write(30);
//  delay(1000);
//  servoFire.write(150);
//  delay(1000);
  
  for(int i = servoMin; i < servoMax; ++i) { 
    servoPan.write(i); 
    servoTilt.write(i); 
    delay(100);
  } 
  for(int i = servoMax; i > servoMin; --i) {
    servoPan.write(i);
    servoTilt.write(i);
    delay(100);
  }
}
