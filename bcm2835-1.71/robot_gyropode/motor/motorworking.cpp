// blink.c
//
// Example program for bcm2835 library
// Blinks a pin on an off every 0.5 secs
//
// After installing bcm2835, you can build this 
// with something like:
// gcc -o blink blink.c -l bcm2835
// sudo ./blink
//
// Or you can test it before installing with:
// gcc -o blink -I ../../src ../../src/bcm2835.c blink.c
// sudo ./blink
//
// Author: Mike McCauley
// Copyright (C) 2011 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $
#include "motor.h"
#include <bcm2835.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <chrono>
// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
// GPI_P1_X correspond to physical pins in the order of the GPIO header (incrementing)
#define STEP_M1 19  
#define DIR_M1 13 
//#define STEP_M1 6  
//#define DIR_M1 5 
#define ENABLE RPI_V2_GPIO_P1_37 // ENABLE HIGH <=> motor disabled 
void run (bool &isvalid, unsigned int &delay, int &steps)       //steps is only return variable for the main loop
{
    while (isvalid) 
    {
        bcm2835_gpio_write(DIR_M1, steps>0);

        bcm2835_gpio_write(STEP_M1, HIGH);
        bcm2835_delayMicroseconds(delay);
        bcm2835_gpio_write(STEP_M1, LOW);
        bcm2835_delayMicroseconds(delay);
    }
}
int main(int argc, char **argv)
{
    if (!bcm2835_init())
      return 1;

    // Set the pin to be an output
    bcm2835_gpio_fsel(STEP_M1, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(DIR_M1, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(ENABLE, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_write(ENABLE, LOW);
    // Blin
    bool isvalid=true;
    unsigned int delay=500;
    int steps=-1;
    
    while (true)
    {
        run(isvalid,delay,steps);
    }
    bcm2835_close();
    return 0;
}

