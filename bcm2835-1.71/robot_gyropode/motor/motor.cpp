#include "motor.h"
#include <bcm2835.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <chrono>


void Motor::run(bool &isvalid, unsigned int &delay, int &steps)       //steps is only return variable for the main loop
{
    bcm2835_gpio_write(ENABLE, LOW);
    while (isvalid) 
    {
        //print the value of direction pin*
        printf("StepPin : ");
        printf("%d\n", &StepPin());
        printf("%d\n", StepPin());

        bcm2835_gpio_write(DirPin(), steps>0);

        bcm2835_gpio_write(StepPin(), HIGH);
        bcm2835_delayMicroseconds(delay);
        bcm2835_gpio_write(DirPin(), LOW);
        bcm2835_delayMicroseconds(delay);
    }
}
Motor::Motor():motorValid(true)
{
}
Motor::~Motor()
{
    motorValid=false;
    //disable motor
    bcm2835_gpio_write(ENABLE, HIGH);
}

int main(int argc, char **argv)
{
    if (!bcm2835_init())
      return (1);
    bool isvalid=true;
    unsigned int delay=50;
    int steps=-1;
    Motor1 motor;


    while (true)
    {
        motor.run(isvalid,delay,steps);
    }
    bcm2835_close();
    return 0;
}

