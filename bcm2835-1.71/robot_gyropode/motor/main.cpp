#include <bcm2835.h>
#include "motor.cpp"
#include <csignal>
#include <sys/types.h>
#include <unistd.h>

#define DEBUG TRUE

bool isvalid=true;

void signalHandler( int signum ) {
   #ifdef DEBUG
    std::cout << "signal" << signum << " triggered" <<std::endl;
   #endif
   bcm2835_gpio_write(ENABLE, HIGH);
   isvalid=false;
   #ifdef DEBUG
    std::cout << "Sigterm signal ended" <<std::endl;
   #endif
}




int main(int argc, char **argv)
{
    std::cout << "Started ...\n";
    // print the process id
    std::cout << "PID: " << getpid() << std::endl;

    if (!bcm2835_init())
      return (1);
    unsigned int delay=0;
    int steps=-1;
    //motor is a pointer to be deletable
    Motor1 *motor1 = new Motor1();
    Motor2 *motor2 = new Motor2();

    // set the signal handler
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);

    while (isvalid)
    {
        motor1->run(isvalid,delay,steps);
    }
    // print out of the loop
    std::cout << "out of the loop \n";
    isvalid=true;
    while (isvalid)
    {
        motor2->run(isvalid,delay,steps);
    }
    // print out of the loop
    std::cout << "out of the loop \n";

    delete motor1;
    bcm2835_close();
    return 0;
}
