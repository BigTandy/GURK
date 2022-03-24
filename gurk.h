/*
    Grand Unified Robot Kontroler (GURK)
    Created by Bud Patterson, March 23, 2022.
    Copyright Bud Patterson
    All Rights Reserved.
*/

#ifndef gurk_h
#define gurk_h

#include "Arduino.h"

class Gurk {
    public:
        Gurk(int componsation, int in1, int in2, int pwm);

        void forward();
        void backward();
        void sstop();
        void coast();
    
        void speedChange(int power);

        int state;
        int power;
    private:
        int _componsation;
        int _in1;
        int _in2;
        int _pwm;
};

#endif