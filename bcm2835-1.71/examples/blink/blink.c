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

#include <bcm2835.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <chrono>
// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
#define STEP RPI_GPIO_P1_11
#define DIR RPI_GPIO_P1_13
int motor_inc (int steps, uint64_t tx_time)
{
    bcm2835_gpio_write(DIR, steps>0);//signbit(steps)=steps sign 
    unsigned int time =int(tx_time/(steps*2));
    for (int i=0;i<steps;i++)
        {
            bcm2835_gpio_write(STEP, HIGH);
            bcm2835_delayMicroseconds(time);
            bcm2835_gpio_write(STEP, LOW);
            bcm2835_delayMicroseconds(time);
        }
}
int main(int argc, char **argv)
{
    const struct timespec *steps, *tx_time;
    // If you call this, it will not actually access the GPIO
    // Use for testing
//    bcm2835_set_debug(1);

    if (!bcm2835_init())
      return 1;

    // Set the pin to be an output
    bcm2835_gpio_fsel(STEP, BCM2835_GPIO_FSEL_OUTP);

    // Blin

    while (true)
    {
        motor_inc(10,10000000);
	// Turn it on
	
	
	// wait a bit
	//bcm2835_delay(500);
	
	// turn it off
	
	
	// wait a bit
	//bcm2835_delay(500);
    }
    bcm2835_close();
    return 0;
}

