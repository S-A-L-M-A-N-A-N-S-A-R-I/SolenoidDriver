#ifndef SOLENOID_DRIVER_H
#define SOLENOID_DRIVER_H

#include <Arduino.h>
#include <elapsedMillis.h>

// SolenoidDriver class to manage the state and power of a solenoid
class SolenoidDriver
{
public:
    elapsedMillis pTime; // Timer to track elapsed time

    byte holdpower;      // Power level to hold the solenoid
    bool state = 0;      // Current state of the solenoid (on or off)
    byte sPin;           // Pin connected to the solenoid
    uint16_t energizetime; // Time to fully energize the solenoid

    // Constructor
    SolenoidDriver(byte pin, byte holdPower, uint16_t energizeTime);

    // Method to turn the solenoid on
    void on();

    // Method to turn the solenoid off
    void off();

    // Method to set the holding power level
    void setPower(byte holdPower);

    // Method to get the current state of the solenoid
    bool now();

    // Method to manage the solenoid state and power
    void alive();
};

#endif // SOLENOID_DRIVER_H
