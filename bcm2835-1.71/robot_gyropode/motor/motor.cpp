#include "motor.h"
#include <bcm2835.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <chrono>


void Motor1::run(bool &isvalid, unsigned int &delay, int &steps)       //steps is only return variable for the main loop
{
    bcm2835_gpio_write(ENABLE, LOW);
    while (isvalid) 
    {
        bcm2835_gpio_write(DIR_M1, steps>0);
        bcm2835_gpio_write(STEP_M1, HIGH);
        bcm2835_delayMicroseconds(delay);
        bcm2835_gpio_write(STEP_M1, LOW);
        bcm2835_delayMicroseconds(delay);
    }
}

void Motor2::run(bool &isvalid, unsigned int &delay, int &steps)       //steps is only return variable for the main loop
{
    bcm2835_gpio_write(ENABLE, LOW);
    while (isvalid) 
    {
        bcm2835_gpio_write(DIR_M1, steps>0);
        bcm2835_gpio_write(STEP_M2, HIGH);
        bcm2835_delayMicroseconds(delay);
        bcm2835_gpio_write(STEP_M2, LOW);
        bcm2835_delayMicroseconds(delay);
    }
}

Motor::Motor():valid(true)
{
}
Motor::~Motor()
{
    valid=false;
    //disable motor
    bcm2835_gpio_write(ENABLE, HIGH);
    // print "the motor is disabled"
    std::cout << "the motor is disabled" << std::endl;
}

