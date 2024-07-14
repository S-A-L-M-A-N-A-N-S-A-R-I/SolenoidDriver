#include <SolenoidDriver.h>

// Define pin and parameters for the solenoid valve
const byte pressureValve = 6;     // Pin for the pressure valve solenoid // must be PWM
const byte SLHP = 150;            //Solenoid Holding power level for the pressure valve // set in between 0-255 as required
const uint16_t energizeTime = 500; // Energize time for the pressure valve // in ms

// Instantiate solenoid driver
SolenoidDriver solenoidCapValve(pressureValve, SLHP, energizeTime);

void setup() {
    // Turn the solenoid on
    solenoidCapValve.on();
}

void loop() {
    // Manage the solenoid in the main loop
    solenoidCapValve.alive();
}
