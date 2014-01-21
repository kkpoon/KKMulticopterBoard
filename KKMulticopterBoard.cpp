#include "KKMulticopterBoard.h"

KKMulticopterBoard::KKMulticopterBoard(int a_pin,
                                       int e_pin,
                                       int t_pin,
                                       int r_pin)
{
    _controlMax = KKMulticopterBoard_CONTROL_MAX;
    _controlMin = KKMulticopterBoard_CONTROL_MIN;

    _ail.attach(a_pin, _controlMin, _controlMax);
    _ele.attach(e_pin, _controlMin, _controlMax);
    _thr.attach(t_pin, _controlMin, _controlMax);
    _rud.attach(r_pin, _controlMin, _controlMax);
    idle();
}

int KKMulticopterBoard::_getControlValue(float value)
{
    return map(value * 1000, 0, 1000, _controlMin, _controlMax);
}

void KKMulticopterBoard::idle()
{
    _ail.writeMicroseconds(_getControlValue(0.5));
    _ele.writeMicroseconds(_getControlValue(0.5));
    _thr.writeMicroseconds(_getControlValue(0.0));
    _rud.writeMicroseconds(_getControlValue(0.5));
}

void KKMulticopterBoard::level()
{
    _ail.writeMicroseconds(_getControlValue(0.5));
    _ele.writeMicroseconds(_getControlValue(0.5));
    _rud.writeMicroseconds(_getControlValue(0.5));
}

void KKMulticopterBoard::arm()
{
    idle();
    delay(5000);
    _ail.writeMicroseconds(_getControlValue(0.5));
    _ele.writeMicroseconds(_getControlValue(0.5));
    _thr.writeMicroseconds(_getControlValue(0.0));
    _rud.writeMicroseconds(_getControlValue(1.0));
    delay(5000);
    idle();
    delay(5000);
}

void KKMulticopterBoard::disarm()
{
    idle();
    delay(5000);
    _ail.writeMicroseconds(_getControlValue(0.5));
    _ele.writeMicroseconds(_getControlValue(0.5));
    _thr.writeMicroseconds(_getControlValue(0.0));
    _rud.writeMicroseconds(_getControlValue(0.0));
    delay(5000);
    idle();
    delay(5000);
}

void KKMulticopterBoard::setAileron(int value)
{
    _aileron = map(value, -100, 100, _controlMin, _controlMax);
    _aileron = constrain(_aileron, _controlMin, _controlMax);
    _ail.writeMicroseconds(_aileron);
}

int KKMulticopterBoard::getAileron()
{
    return map(_aileron, _controlMin, _controlMax, -100, 100);
}

void KKMulticopterBoard::setElevator(int value)
{
    _elevator = map(value, -100, 100, _controlMin, _controlMax);
    _elevator = constrain(_elevator, _controlMin, _controlMax);
    _ele.writeMicroseconds(_elevator);
}

int KKMulticopterBoard::getElevator()
{
    return map(_elevator, _controlMin, _controlMax, -100, 100);
}

void KKMulticopterBoard::setThrottle(int percentage)
{
    _throttle = map(percentage, 0, 100, _controlMin, _controlMax);
    _throttle = constrain(_throttle, _controlMin, _controlMax);
    _thr.writeMicroseconds(_throttle);
}

int KKMulticopterBoard::getThrottle()
{
    return map(_throttle, _controlMin, _controlMax, 0, 100);
}

void KKMulticopterBoard::setRudder(int value)
{
    _rudder = map(value, -100, 100, _controlMin, _controlMax);
    _rudder = constrain(_elevator, _controlMin, _controlMax);
    _rud.writeMicroseconds(_rudder);
}

int KKMulticopterBoard::getRudder()
{
    return map(_rudder, _controlMin, _controlMax, -100, 100);
}

