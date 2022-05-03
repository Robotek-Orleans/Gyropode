#include <bcm2835.h>
class Gyro
{
    public:
        Gyro();
        ~Gyro();
        void runAcquisition();
        int16_t ax,ay,az;
        int16_t gx, gy, gz;

    private:
};



