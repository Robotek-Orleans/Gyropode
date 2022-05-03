#include <stdio.h>
#include <bcm2835.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#include <math.h>
#include "gyro.h"
void Gyro::value()
{
  I2Cdev::initialize();
  MPU6050 accelgyro ;
  accelgyro.initialize();
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  printf("  %d \t %d \t %d \r", ax, ay, az);
  fflush(stdout);
  bcm2835_delay(1000);
}

Gyro::Gyro()
{
}
Gyro::~Gyro()
{
}

/*
int main(int argc, char **argv) {
  Gyro gyro;
  gyro.value();
  }
*/

