#include "motor.h"
#include <bcm2835.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <chrono>

#define DEBUG TRUE
void Motor::init()
{
    // Set the pin to be an output
    bcm2835_gpio_fsel(STEP_M1, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(DIR_M1, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(ENABLE, BCM2835_GPIO_FSEL_OUTP);
    //enable motor
    bcm2835_gpio_write(ENABLE, LOW);
}


void Motor1::run()       //steps is only return variable for the main loop
{
    bcm2835_gpio_write(ENABLE, LOW);
    valid=true;
    while (valid) 
    {
        // set the dir pin to the right value
        bcm2835_gpio_write_multi(DIR_PIN_M1, dir);
        // set the step pin to high
        bcm2835_gpio_set_multi(STEP_PIN_M1);
        bcm2835_delayMicroseconds(delay);
        // clear the step pin to LOW
        bcm2835_gpio_clr_multi(STEP_PIN_M1); 
        bcm2835_delayMicroseconds(delay);
        dir ? steps++ : steps--; // if dir is true, steps++, else steps--
    }
}

void Motor2::run()       //steps is only return variable for the main loop
{
    bcm2835_gpio_write(ENABLE, LOW);
    valid=true;
    while (valid) 
    {   
        // set the dir pin to the right value
        bcm2835_gpio_write_multi(DIR_PIN_M2, dir);
        // set the step pin to high
        bcm2835_gpio_set_multi(STEP_PIN_M2);
        bcm2835_delayMicroseconds(delay);
        // clear the step pin to LOW
        bcm2835_gpio_clr_multi(STEP_PIN_M2);
        bcm2835_delayMicroseconds(delay);
        dir ? steps++ : steps--; // if dir is true, steps++, else steps-- 
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

