/*
EE151 - Janine Darto
Spencer Perley
Final Project
*/

#include "commonDecProject.h"
int DigitalPin::pinCount = 0;
// Instantiating the light objects
DigitalPin green(9), blue(7), red(8), white(6);

// Making a container for all of the DigitalPin objects
DigitalPin lightContainer[4] = {green, red, blue, white};

int pinCount = DigitalPin::getPinCount();

Password password;

/*___________________________________________________________________________________________________*/

void runLoopTime()
{
    previousTime = curentTime;
    curentTime = millis();
    loopTime = curentTime - previousTime;
}

//int state = 1;

/*___________________________________________________________________________________________________*/

void setup() // This is the function to settup the arduino
{
    for (int i = 0; i < (pinCount + 1); i++)
    {
        lightContainer[i].allocatePin();
    }
    irrecv.enableIRIn();
    Serial.begin(9600);

    state = START_UP;

} // End brackets indicate end of settup function

/*___________________________________________________________________________________________________*/

void loop() // Start the main loop
{
#if true //Preprosseser directive used for debuging

    if (state == OFF)
    {
        runLoopTime();
    }

    switch (state) //This is the state 
    {

/*___________________________________________________________________________________________________*/

    case START_UP: // if the program is in the START_UP state

        for (int i = 0; i < (pinCount + 1); i++)
        {
            lightContainer[i].turnOn();
            delay(100);
        }
        delay(500);
        for (int i = pinCount; i > -1; i--)
        {
            lightContainer[i].turnOff();
            delay(100);
        }
        password.setIndexOfEntered(0);

        blue.turnOn();

        state = SET_PASSWORD;

/*___________________________________________________________________________________________________*/

    case SET_PASSWORD: // if the program is in the SET_PASSWORD state

        currentKey = getKey();
        if (currentKey != 10) //Waiting for an acceptable key press
        {
            if (currentKey == 11)
            {
                state = OFF;
                white.turnOff();
                password.setIndexOfEntered(0);
                break;
            }
            password.setEnteredPassword(currentKey);
            password.printEnteredPassword();
            if (password.getIndexOfEntered() >= 10)
            {
                password.setIndexOfEntered(0);
                state = ENTER_PASSWORD;
                blue.turnOff();
                white.turnOn();
            }
        }
        break;

/*___________________________________________________________________________________________________*/

    case ENTER_PASSWORD: // if the program is in the ENTER_PASSWORD state

        currentKey = getKey();
        if (currentKey != 10) // If there is a keypress put it into the currentPassword list
        {
            if (currentKey == 11)
            {
                state = OFF;
                white.turnOff();
                password.setIndexOfEntered(0);
                break;
            }
            password.setCurrentPassword(currentKey);
            // if the list is filled up evaluate wether or not the two password lists match
            if (password.getIndexOfEntered() >= 10)
            {
                if (password.passwordsMatch())
                {
                    state = PASSWORD_CORRECT;
                }
                if (!(password.passwordsMatch()))
                {
                    state = PASSWORD_INCORRECT;
                }

                white.turnOff();
                password.setIndexOfEntered(0);
            }
        }
        break;

/*___________________________________________________________________________________________________*/

    case PASSWORD_CORRECT: // If the program is in the PASSWORD_CORRECT state

        green.turnOn();
        Serial.println("You are Correct");
        delay(2000);
        state = START_UP;
        green.turnOff();
        break;

/*___________________________________________________________________________________________________*/

    case PASSWORD_INCORRECT: // If the program is in the PASSWORD_INCORRECT state

        red.turnOn();
        Serial.println("You are not Correct    Try again");
        delay(2000);
        password.printEnteredPassword();
        white.turnOn();
        red.turnOff();

        state = ENTER_PASSWORD;
        break;

/*___________________________________________________________________________________________________*/

    case OFF:
        if (blue.getState() || red.getState() || green.getState()) // Checking if the pins are on
        {
            for (int i = 0; i < (pinCount + 1); i++) // Turn all of the pins off
            {
                lightContainer[i].turnOff();
            }
        }

        white.turnOff();
        //white.blinkLight(200, 10000);
        currentKey = getKey();
        if (currentKey == 11) // If there is a keypress put it into the currentPassword list
        {
            password.setIndexOfEntered(0);
            //white.turnOff();

            state = START_UP;
            break;
        }

/*___________________________________________________________________________________________________*/

    default: // Empty Default Case
        break;
    }

    //green.blinkLight(500); // Set pin 13 to HIGH (5v)
    //red.blinkLight(3000);
    //Serial.println(loopTime);
#endif

} // End the main loop