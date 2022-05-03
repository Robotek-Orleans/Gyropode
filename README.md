# Gyropode

compile and run the main code 
```sh
g++ ~/Gyropode/main.cpp -O3 -o main.out -l bcm2835 -pthread && sudo ./main.out
```


compile and run the gyro code 
```sh
 g++ ~/Gyropode/gyro.cpp -I ~/Gyropode/i2cdevlib/RaspberryPi_bcm2835/I2Cdev ~/Gyropode/i2cdevlib/RaspberryPi_bcm2835/I2Cdev/I2Cdev.cpp -I ~/Gyropode/i2cdevlib/RaspberryPi_bcm2835/MPU6050/ ~/Gyropode/i2cdevlib/RaspberryPi_bcm2835/MPU6050/MPU6050.cpp -l bcm2835 -o gyro.out
```