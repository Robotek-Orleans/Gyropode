#include <stdio.h>
#include <bcm2835.h>
#include "I2Cdev.h"
#include "MPU6050.h"
#include <thread>
#include <time.h>
#include <math.h>
int main(int argc, char **argv)
{
  MPU6050 gyro;
  I2Cdev::initialize();
  gyro.initialize();

  gyro.setRate(0);
  gyro.setClockSource(0);
  gyro.setWakeFrequency(3);
  gyro.setAccelerometerPowerOnDelay(3);
  // set sample divider to 7

  gyro.setSleepEnabled(false);
  gyro.setWakeCycleEnabled(false);
  //gyro.setRate(255);

  int16_t ax, ay, az;
  int16_t x_old = 0, y_old = 0, z_old = 0;

  // measure time between two events
  uint64_t start = bcm2835_st_read();
  printf("start: %llu\n", start);
  int i = 0;
  int j = 0;
  while (bcm2835_st_read() - start < 10000000)
  {
    gyro.getAcceleration(&ax, &ay, &az);

    if (ax != x_old || ay != y_old || az != z_old)
    {
      //printf("%d: ax: %d, ay: %d, az: %d\n", i, ax, ay, az);
      x_old = ax;
      y_old = ay;
      z_old = az;
      i++;
      // angle : atan(ax/az)
      //printf("ax: %d\t, ay: %d\t, az: %d\t, angle: %f\n",ax, ay, az, 180.0 / M_PI * atan((float)ay/(float)az));
    }
    j++;

    struct timespec t1;

    t1.tv_sec = 0;
    t1.tv_nsec = 400000;
    nanosleep(&t1, NULL);
    //bcm2835_delayMicroseconds(300);
  }
  printf("%d\n", i);
  printf("%d\n", j);
  
}
