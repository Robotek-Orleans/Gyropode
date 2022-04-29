#include <bcm2835.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_LEN 16
//Definition des adresses I2C
#define ACCEL_XOUT0 0x3B
#define ACCEL_YOUT0 0x3D
#define ACCEL_ZOUT0 0x3F
#define GYRO_XOUT0 0x43
#define GYRO_YOUT0 0x45
#define GYRO_ZOUT0 0x47
#define ACCEL_CONFIG 0x1C
#define GYRO_CONFIG 0x1B
#define PWR_MGMT_1 0x6B
#define PWR_MGMT_2 0x6C
#define clk_div BCM2835_I2C_CLOCK_DIVIDER_148
uint8_t data =0;
uint32_t len = 16;
char buf[MAX_LEN];

int Ax,Ay,Az,Gx,Gy,Gz =0;

uint32_t Read()
{
    for (int i=0; i<MAX_LEN; i++) buf[i] = ' ';
    data = bcm2835_i2c_read(buf, len); 
    return(data);
}

int main()
{ 
    
    printf("\r");
    bcm2835_init();
    bcm2835_i2c_begin();
    bcm2835_i2c_setSlaveAddress(ACCEL_XOUT0);
    bcm2835_i2c_setClockDivider(BCM2835_I2C_CLOCK_DIVIDER_148);
    bcm2835_i2c_read(buf,len);
    printf("Ax = ");
    printf("%i",Read());
    
    bcm2835_i2c_setSlaveAddress(ACCEL_YOUT0);
    printf("    Ay = ");
    printf("%i",Read());
    //bcm2835_i2c_setSlaveAddress(ACCEL_ZOUT0);
    //printf("Az= ",Read());
    //bcm2835_i2c_setSlaveAddress(GYRO_XOUT0);
    //printf("Gx= ",Read());
    //bcm2835_i2c_setSlaveAddress(GYRO_YOUT0);
    //printf("Gy= ",Read());
    //bcm2835_i2c_setSlaveAddress(GYRO_ZOUT0);
    //printf("Gz=",Read(),"\n\r");
    bcm2835_close();
}
