#ifndef SOLENOID_DRIVER_H
#define SOLENOID_DRIVER_H

#include <Arduino.h>
#include <elapsedMillis.h>

class SolenoidDriver
{
public:
    elapsedMillis pTime;

    byte holdpower;
    bool state = 0;
    byte sPin;
    uint16_t energizetime;
    SolenoidDriver(byte pin, byte holdPower, uint16_t energizeTime);

    void on();
    void off();
    void setPower(byte holdPower);
    bool now();
    void alive();
};

#endif // SOLENOID_DRIVER_H
