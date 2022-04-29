#include <bcm2835.h>

#define ENABLE 26 // ENABLE HIGH <=> motor disabled 
#define STEP_M1 6
#define DIR_M1 5
#define STEP_M2 19
#define DIR_M2 13
#define ENABLE 26

#define DEBUG TRUE

// créer une classe abstraite
class Motor
{
    public:
        Motor();
        ~Motor();
        bool valid = true;
        //void run(bool &isvalid, unsigned int &delay, int &steps);

    private:
        // déclaration des méthodes abstraites
        //virtual const int &StepPin() const = 0;
        //virtual const int &DirPin() const = 0;
    protected:
        inline void init(){
            // Set the pin to be an output
            //bcm2835_gpio_fsel(StepPin(), BCM2835_GPIO_FSEL_OUTP);
            //bcm2835_gpio_fsel(DirPin(), BCM2835_GPIO_FSEL_OUTP);
            bcm2835_gpio_fsel(STEP_M1, BCM2835_GPIO_FSEL_OUTP);
            bcm2835_gpio_fsel(DIR_M1, BCM2835_GPIO_FSEL_OUTP);
            bcm2835_gpio_fsel(STEP_M2, BCM2835_GPIO_FSEL_OUTP);
            bcm2835_gpio_fsel(DIR_M2, BCM2835_GPIO_FSEL_OUTP);
            
            bcm2835_gpio_fsel(ENABLE, BCM2835_GPIO_FSEL_OUTP);
            //enable motor
            bcm2835_gpio_write(ENABLE, LOW);
        }
};

class Motor1 : public Motor
{
    public:
        inline Motor1(){
            init();
        }
    
    void run(bool &isvalid, unsigned int &delay, int &steps);
    
    protected:
        // définition des méthodes abstraites pour appeler StepPin et DirPin
        //const int &StepPin() const { return STEP_M1; }
        //const int &DirPin() const { return DIR_M1; }
};

class Motor2 : public Motor
{
    public:
        inline Motor2(){
            init();
        }

        void run(bool &isvalid, unsigned int &delay, int &steps);

    protected:
        // définition des méthodes abstraites pour appeler StepPin et DirPin
        //const int &StepPin() const { return STEP_M2; }
        //const int &DirPin() const { return DIR_M2; }
};