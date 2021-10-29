#include "DHT.h";
#include <LiquidCrystal.h>;

// Import the Liquid Crystal library
DHT dht(10, DHT11);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void UpdateTempHumDisplay(float temp, float humidity) //Prints the temperature and humidity to the screen
{
	lcd.print("Now ");
	lcd.print(temp);
	lcd.print(" F");
	lcd.print((int)humidity);
	lcd.print("%");
}

set temo

void setup()
{
	// Switch on the LCD screen
	lcd.begin(16, 2);
	dht.begin();

	pinMode(9, INPUT_PULLUP);
	pinMode(13, INPUT_PULLUP);

	// Print these words to my LCD screen
}

void loop()
{
	// put your main code here, to run repeatedly:
	lcd.print("Now ");
	//UpdateTempHumDisplay(dht.readTemperature(true), dht.readHumidity()); //dht.readHumidity(),dht.readTemperature(true));
	delay(2000);
	lcd.clear();
	lcd.print("wow ");
	delay(2000);
}