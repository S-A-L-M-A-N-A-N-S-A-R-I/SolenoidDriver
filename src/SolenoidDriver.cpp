#include "SolenoidDriver.h"

// Constructor implementation
SolenoidDriver::SolenoidDriver(byte pin, byte holdPower, uint16_t energizeTime)
{
    energizetime = energizeTime; // Set energize time
    holdpower = holdPower;       // Set holding power
    pinMode(pin, OUTPUT);        // Set the pin mode to OUTPUT
    sPin = pin;                  // Store the pin number
}

// Method to turn the solenoid on
void SolenoidDriver::on()
{
    if (state == 0) // Check if the solenoid is off
    {
        pTime = 0; // Reset the timer
        state = 1; // Set state to on
    }
}

// Method to turn the solenoid off
void SolenoidDriver::off()
{
    state = 0; // Set state to off
}

// Method to set the holding power level
void SolenoidDriver::setPower(byte holdPower)
{
    holdpower = holdPower; // Update the holding power level
}

// Method to get the current state of the solenoid
bool SolenoidDriver::now()
{
    return state; // Return the current state
}

// Method to manage the solenoid state and power
void SolenoidDriver::alive()
{
    if (state && pTime >= energizetime) // Check if the solenoid is on and energize time has passed
    {
        analogWrite(sPin, holdpower); // Set the solenoid to hold power
    }
    else if (state) // Check if the solenoid is on
    {
        analogWrite(sPin, 255); // Fully energize the solenoid
    }
    else // Solenoid is off
    {
        analogWrite(sPin, 0); // Turn off the solenoid
    }
}
