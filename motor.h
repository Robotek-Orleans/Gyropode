#include <bcm2835.h>
#include <limits.h>

// motor pins definitions
#define ENABLE 26 // ENABLE HIGH <=> motor disabled 
#define STEP_M1 6
#define DIR_M1 5
#define STEP_M2 19
#define DIR_M2 13

//definitions to speed up the code
#define STEP_PIN_M1 (1 << STEP_M1)
#define DIR_PIN_M1 (1 << DIR_M1)
#define PINS_M1 (1 << STEP_M1) | (1 << DIR_M1)
#define STEP_PIN_M2 (1 << STEP_M2)
#define DIR_PIN_M2 (1 << DIR_M2)
#define PINS_M2 (1 << STEP_M2) | (1 << DIR_M2)

// number of steps for one revolution
#define REVOLUTION 3200 // number of steps for one revolution

//debugging
#define DEBUG TRUE

// créer une classe abstraite
class Motor
{
    public:
        Motor();
        ~Motor();
        bool valid = false;
        unsigned int delay = 1<<16; // default delay to be near stop
        int steps = 0;
        bool dir;

        //void run(bool &isvalid, unsigned int &delay, int &steps);
        virtual void run() = 0;

    private:
        // déclaration des méthodes abstraites
        //virtual const int &StepPin() const = 0;
        //virtual const int &DirPin() const = 0;
    protected:
        void init();
};

class Motor1 : public Motor
{
    public:
        inline Motor1(){
            init();
        }
    
    void run();
    
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

        void run();

    protected:
        // définition des méthodes abstraites pour appeler StepPin et DirPin
        //const int &StepPin() const { return STEP_M2; }
        //const int &DirPin() const { return DIR_M2; }
};