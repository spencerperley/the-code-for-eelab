/*
EE151 - Janine Darto
Spencer Perley
PreLab 7
*/
class JoyStick
{
    // Defining the private member variables
private:
    int rawX, rawY;
    float x, y, xVolts, yVolts;
    // Defining the public member functions
public:
    // Map the analog values to position and voltage
    void setPosition(int xPin, int yPin)
    {
        rawX = analogRead(xPin);
        rawY = analogRead(yPin);
        x = (rawX * .195503) - 100;
        y = (rawY * .195503) - 100;
        xVolts = rawX * .0048875;
        yVolts = rawY * .0048875;
        // Cut off very low values so that position is 0 at rest
        if (abs(x) < 4)
        {
            x = 0;
        }
        if (abs(y) < 4)
        {
            y = 0;
        }
    }
    // Format the data and print all of the data in the desierd format-
    // for all the X results
    void printAllX()
    {
        Serial.print("Analog Read A0: ");
        Serial.print(rawX);
        Serial.print(" Voltage A0: ");
        Serial.print(xVolts);
        Serial.print(" Position X: ");
        Serial.println(x);
    }
    // Do the same thing for all of the Y results
    void printAllY()
    {
        Serial.print("Analog Read A1: ");
        Serial.print(rawY);
        Serial.print(" Voltage A1: ");
        Serial.print(yVolts);
        Serial.print(" Position Y: ");
        Serial.println(y);
    }
};
JoyStick joyStick; // Instantiate a JoyStick object named joyStick
void setup()
{                       // Setup function
    Serial.begin(9600); // Initialize the serial monitor
}
void loop() //Main loop runs and calls all the methods
{
    joyStick.setPosition(0, 1);
    joyStick.printAllX();
    Serial.println(" ");
    joyStick.printAllY();
    Serial.println(" ");
    delay(1000); // wait for 1s
}