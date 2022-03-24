/*
    Grand Unified Robot Kontroler (GURK)
    Created by Bud Patterson, March 23, 2022.
    Copyright Bud Patterson
    All Rights Reserved.
*/


/*
Drive by time be aware of batt voltage
*/


/* 
Motor Goals:

Red on 1 // Outer
Black on 2 // Inner

Forward
Backword
Left / CCW Is Forward
Right / CW Is Forward
Coast
Short Stop

Drive Speed
*/

/*
Each Motor has object

INIT:
    Tell if left or right

Propertys:
    POWER: INT [0-255]
    STATE: [FORWARD | BACKWARD | COAST | STOP]

Methods:
    stateChange: Pass a state and it will update the property and update the motor
    speedChange: Pass a Power and it will update the property and update the motor
*/


#include "Arduino.h"
#include "gurk.h"

Gurk::Gurk(int componsation, int in1, int in2, int pwm) {

    _componsation = componsation; // True = Left, False = Right

    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(pwm, OUTPUT);

    _in1 = in1;
    _in2 = in2;
    _pwm = pwm;

    /*
    state
    0 = Stop
    1 = Coast
    2 = Forward
    3 = Backward
    */

    state = 0;
    power = 0; //127 is middle

}

void Gurk::forward() {
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, HIGH);
}

void Gurk::backward() {
    digitalWrite(_in1, HIGH);
    digitalWrite(_in2, LOW);
}

void Gurk::sstop() {
    digitalWrite(_in1, HIGH);
    digitalWrite(_in2, HIGH);
}

void Gurk::coast() {
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, LOW);
}

void Gurk::speedChange(int ii_power){
    power = ii_power;
    analogWrite(_pwm, ii_power);
}