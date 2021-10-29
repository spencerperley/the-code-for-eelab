byte LEDBrightness = 0;

void setup()
{ 
    pinMode(9,OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    analogWrite(9,LEDBrightness);

    Serial.println(LEDBrightness);

    LEDBrightness++; //increment LEDBrightness

    delay(10);

}