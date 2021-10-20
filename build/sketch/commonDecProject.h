#line 1 "c:\\Users\\Spencer\\Documents\\GitHub\\code-for-ee-lab-fixed\\vscode files\\src\\object_testing\\commonDecProject.h"
#ifndef COMMON_DECLARATIONS_PROJECT //Header gaurd for this header file
#define COMMON_DECLARATIONS_PROJECT
#pragma once

//Global Variable Declarations
long curentTime = 0;
long previusTime = curentTime;
long loopTime = 0;
int currentKey = 10;

// Enumeration for State-Machine
enum programState
{
    START_UP = 0,
    SET_PASSWORD = 1,
    ENTER_PASSWORD = 2,
    PASSWORD_CORRECT = 3,
    PASSWORD_INCORECT = 4,
    OFF = 5
} state;

class DigitalPin
{
private:
    int pinNum;
    int blinkTimer;
    bool timerStarted;
    bool blinkOcilator;
    bool isOn;
    static int pinCount;

public:
    DigitalPin(int pinNumC);
    void setPinNum(int n);
    int getPinNum();
    void turnOn();
    void turnOff();
    bool getState();
    void blinkLight(int blinkLength);
    void blinkLight(int onTime, int offTime);
    void alocatePin();
    static int getPinCount();
};

class Password
{
private:
    int indexOfEntered;
    int enteredPassword[10] = {0};
    int currentPassword[10] = {0};

public:
    Password();

    void setIndexOfEntered(int numEntries);
    void setEnteredPassword(int imput);
    void setCurrentPassword(int imput);
    int getIndexOfEntered();
    void printEnteredPassword();
    void printCurrentPassword();
    bool passwordsMatch();
};

#include "projIR.hpp"

#endif