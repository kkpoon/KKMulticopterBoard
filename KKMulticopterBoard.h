#ifndef kkmulticopter_h
#define kkmulticopter_h

#define KKMulticopterBoard_CONTROL_MIN 1000
#define KKMulticopterBoard_CONTROL_MAX 2000

#define KKMulticopterBoard_MODE_NORMAL 1
#define KKMulticopterBoard_MODE_ACRO   2
#define KKMulticopterBoard_MODE_UFO    3

#include <Arduino.h>
#include <Servo.h>

class KKMulticopterBoard
{
    public:
        KKMulticopterBoard(int, int, int, int);
        
        void arm();
        void disarm();
        void setMode(int);
        int  getMode();
        
        void idle();
        void level();

        void setAileron(int);
        int  getAileron();
        
        void setElevator(int);
        int  getElevator();

        void setThrottle(int);
        int  getThrottle();

        void setRudder(int);
        int  getRudder();
    private:
        Servo _ail;
        Servo _ele;
        Servo _thr;
        Servo _rud;

        int _controlMax;
        int _controlMin;

        int _aileron;
        int _elevator;
        int _throttle;
        int _rudder;
        
        boolean _isArmed;
        int _mode;

        int _getControlValue(float);
};

#endif
