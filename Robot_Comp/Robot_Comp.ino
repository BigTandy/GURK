/*
 * Bud Patterson, March 24, 2022
 * Robot Controller Script
*/

#include <gurk.h>


Gurk leftMotor(true, 10, 2, 5);
Gurk rightMotor(true, 9, 3, 6);
int STANDBY = 8;


void motorDrive(int state) {
  switch(state) {
    case 0:
        leftMotor.sstop();
        rightMotor.sstop();
        break;
    case 1:
        leftMotor.coast();
        rightMotor.coast();
        break;
     case 2:    
        leftMotor.forward();
        rightMotor.forward();
        break;      
      case 3:    
        leftMotor.backward();
        rightMotor.backward();
        break;
      default:
        leftMotor.sstop();
        rightMotor.sstop();   
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting...");
  leftMotor.speedChange(100);
  rightMotor.speedChange(100);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("Left Power: "); Serial.println(leftMotor.power);
  Serial.print("Right Power: "); Serial.println(rightMotor.power);
  Serial.println("-----------------");

  motorDrive(2);
  delay(4000);
  motorDrive(1);
  delay(4000);


  //leftMotor.speedChange(random(100,255));
  //rightMotor.speedChange(random(100,255));
  
}
