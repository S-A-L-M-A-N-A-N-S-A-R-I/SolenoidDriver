#include "SolenoidDriver.h"

SolenoidDriver::SolenoidDriver(byte pin, byte holdPower, uint16_t energizeTime)
{
    energizetime = energizeTime;
    holdpower = holdPower;
    pinMode(pin, OUTPUT);
    sPin = pin;
}

void SolenoidDriver::on()
{
    if (state == 0)
    {
        pTime = 0;
        state = 1;
    }
}

void SolenoidDriver::off()
{
    state = 0;
}

void SolenoidDriver::setPower(byte holdPower)
{
    holdpower = holdPower;
}

bool SolenoidDriver::now()
{
    return state;
}

void SolenoidDriver::alive()
{
    if (state && pTime >= energizetime)
    {
        analogWrite(sPin, holdpower);
    }
    else if (state)
    {
        analogWrite(sPin, 255);
    }
    else
    {
        analogWrite(sPin, 0);
    }
}
