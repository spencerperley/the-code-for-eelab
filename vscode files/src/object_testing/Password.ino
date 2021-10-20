#include "commonDecProject.h"

Password::Password() { indexOfEntered = 0; }

void Password::setIndexOfEntered(int numEntries)
{
    indexOfEntered = numEntries;
}

void Password::setEnteredPassword(int imput)
{
    enteredPassword[indexOfEntered] = imput;
    indexOfEntered++;
}

void Password::setCurrentPassword(int imput)
{
    currentPassword[indexOfEntered] = imput;
    indexOfEntered++;
}

int Password::getIndexOfEntered()
{
    return indexOfEntered;
}

void Password::printEnteredPassword()
{
    for (int i; i < 10; i++)
    {
        Serial.print(enteredPassword[i]);
        if (i < 9)
        {
            Serial.print(" , ");
        }
    }

    Serial.println("  ");
    Serial.println("  ");
}
void Password::printCurrentPassword()
{
    for (int i; i < 10; i++)
    {
        Serial.print(currentPassword[i]);
        if (i < 9)
        {
            Serial.print(" , ");
        }
    }

    Serial.println("  ");
    Serial.println("  ");
}

bool Password::passwordsMatch()
{
    for (int i; i < 10; i++)
    {
        if (enteredPassword[i] != currentPassword[i])
        {
            return false;
        }
    }
    return true;
    
}

