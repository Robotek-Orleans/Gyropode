#include <stdio.h>
#include <bcm2835.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#include <math.h>
#include "gyro.h"
void Gyro::runAcquisition()
{
  I2Cdev::initialize();
  MPU6050 accelgyro ;
  accelgyro.initialize();
  accelgyro.getAccelerationXZ(&ax,&az);
  printf("  %d \t %d \r", ax, az);
  fflush(stdout);
  bcm2835_delay(1000);
}

Gyro::Gyro()
{
}
Gyro::~Gyro()
{

}

int main(int argc, char **argv) {
  Gyro gyro;
  gyro.runAcquisition();
  }




