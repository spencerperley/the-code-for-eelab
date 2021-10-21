#include "commonDecProject.h"

// Definitions for the digital pin class
DigitalPin::DigitalPin(int pinNumC) // Constructor that sets the pin number
{
    pinNum = pinNumC;
    // sets the rest of the values so that they are predictible
    blinkTimer = 0;
    blinkOscillator = false;
    pinCount++;
    isOn = false;
}

void DigitalPin::setPinNum(int n) { pinNum = n; } // Sets pin number

int DigitalPin::getPinNum() { return (pinNum); } // Returns pin number

void DigitalPin::turnOn() // Turns light on
{
    digitalWrite(pinNum, HIGH);
    isOn = true; // sets the state of the light to on 
}

void DigitalPin::turnOff() // Turns light off
{
    digitalWrite(pinNum, LOW);
    isOn = false; // sets the state of the light to off 
}

bool DigitalPin::getState() { return (isOn); } // Returns wether or not the light is on

//Blinks light with an equivelent on and off period
void DigitalPin::blinkLight(int blinkLength)
{
    //This code is important so that no delay() function is required
    // witch makes it able to run synchronously with other functions and methods.

    if (blinkTimer < (blinkLength / 2) && !blinkOscillator)
    {
        blinkTimer = blinkTimer + loopTime;
        this->turnOn();
    }
    else if (blinkTimer < (blinkLength / 2) && blinkOscillator)
    {
        blinkTimer = blinkTimer + loopTime;
        this->turnOff();
    }
    else
    {
        blinkTimer = 0;
        blinkOscillator = !blinkOscillator;
    }
}
// Same code as the blinkLight coe but overloaded to include a duty cycle
void DigitalPin::blinkLight(int onTime, int offTime){

    if (blinkTimer < (onTime) && !blinkOscillator)
    {
        blinkTimer = blinkTimer + loopTime;
        this->turnOn();
    }
    else if (blinkTimer < (offTime) && blinkOscillator)
    {
        blinkTimer = blinkTimer + loopTime;
        this->turnOff();
    }
    else
    {
        blinkTimer = 0;
        blinkOscillator = !blinkOscillator;
    }
}

void DigitalPin::allocatePin() // Initializes a digital pin
{
    pinMode(pinNum, OUTPUT);
}

int DigitalPin::getPinCount()
{
    return pinCount;
}
