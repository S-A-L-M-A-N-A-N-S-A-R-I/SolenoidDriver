#include <SolenoidDriver.h>

// Define pin and parameters for the brushless fan
const byte fanPin = 5;          // Pin for the brushless fan // must be PWM
const byte fanSpeed = 100;      // Holding power level for the fan (speed) // the Speed At Which you want to spin the fan // in betWeen 1-255
const uint16_t kickStartTime = 500; // Energize time for the fan to kickstart

// Instantiate solenoid driver for the fan
SolenoidDriver fanDriver(fanPin, fanSpeed, kickStartTime);

void setup() {
    // Turn the fan on
    fanDriver.on();
}

void loop() {
    // Manage the fan in the main loop
    fanDriver.alive();
}
