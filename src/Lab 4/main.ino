#include "DHT.h";
#include <LiquidCrystal.h>;

// Import the Liquid Crystal library
DHT dht(10, DHT11);
LiquidCrystal lcd(12, 11, 5, 4, 13, 9);

int setTemp = 70;
bool lcdAterantor = false;
int delayTime = 0;

// volatile variables to hold the temperature and humidity and loop time variables
float temp = 0;
float humidity = 0;
int loopTime = 0;
int previousTime = 0;
int currentTime = 0;

// constants for the pins for the fan heater and cooler
const int fanPin = 6;
const int heaterPin = 8;
const int coolerPin = 7;

void setup()
{

	// Switch on the LCD screen
	lcd.begin(16, 2);
	dht.begin();
	// Set the pin modes for the fan, heater and cooler
	pinMode(fanPin, OUTPUT);
	pinMode(heaterPin, OUTPUT);
	pinMode(coolerPin, OUTPUT);
	// Set the fan, heater and cooler to off
	digitalWrite(fanPin, LOW);
	digitalWrite(heaterPin, LOW);
	digitalWrite(coolerPin, LOW);

	pinMode(2, INPUT_PULLUP);
	pinMode(3, INPUT_PULLUP);
	//Interupt statements for the buttons connected to pin 2 & 3
	attachInterrupt(digitalPinToInterrupt(2), increaseTemp, FALLING);
	attachInterrupt(digitalPinToInterrupt(3), decreaseTemp, FALLING);
}

/*
███╗   ███╗ █████╗ ██╗███╗   ██╗    ██╗      ██████╗  ██████╗ ██████╗ 
████╗ ████║██╔══██╗██║████╗  ██║    ██║     ██╔═══██╗██╔═══██╗██╔══██╗
██╔████╔██║███████║██║██╔██╗ ██║    ██║     ██║   ██║██║   ██║██████╔╝
██║╚██╔╝██║██╔══██║██║██║╚██╗██║    ██║     ██║   ██║██║   ██║██╔═══╝ 
██║ ╚═╝ ██║██║  ██║██║██║ ╚████║    ███████╗╚██████╔╝╚██████╔╝██║     
╚═╝     ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝    ╚══════╝ ╚═════╝  ╚═════╝ ╚═╝                                                                                                                                              
*/

/*______________________________________________________________________________________________________________________________*/
void loop()
{
	runLoopTime();

	updateTemp();

	// if the lcdAlert is true, then call the displaySetTemp function
	if (lcdAterantor)
	{
		displaySetTemp();
		// every loop increase the delayTime by the loopTime until it reaches 5000ms then reset delayTime to 0
		delayTime += loopTime;
		if (delayTime >= 5000)
		{
			delayTime = 0;
			lcdAterantor = false;
			lcd.clear();
		}
	}
	// if the lcdAlternator is false, then call the displayTemp function
	else
	{
		displayTemp();
		// every loop increase the delayTime by the loopTime until it reaches 5000ms then reset delayTime to 0
		delayTime += loopTime;
		if (delayTime >= 5000)
		{
			delayTime = 0;
			lcdAterantor = true;
			lcd.clear();
		}
	}

	// if the temperature is above the setTemp turn on the fan
	if (temp > setTemp)
	{
		digitalWrite(fanPin, HIGH);
	}
	else
	{
		digitalWrite(fanPin, LOW);
	}
	// if the temperature is below the setTemp turn on the heater
	if (temp < setTemp)
	{
		digitalWrite(heaterPin, HIGH);
	}
	else
	{
		digitalWrite(heaterPin, LOW);
	}

	// if the temperature is 5 above the set temp or the setTemp is two above and the humidity is above 80% turn on the cooler
	if (temp > setTemp + 5 || (setTemp > 2 && humidity > 80))
	{
		digitalWrite(coolerPin, HIGH);
	}
	else
	{
		digitalWrite(coolerPin, LOW);
	}
}
/*______________________________________________________________________________________________________________________________*/

/*
███████╗██╗   ██╗███╗   ██╗ ██████╗████████╗██╗ ██████╗ ███╗   ██╗███████╗
██╔════╝██║   ██║████╗  ██║██╔════╝╚══██╔══╝██║██╔═══██╗████╗  ██║██╔════╝
█████╗  ██║   ██║██╔██╗ ██║██║        ██║   ██║██║   ██║██╔██╗ ██║███████╗
██╔══╝  ██║   ██║██║╚██╗██║██║        ██║   ██║██║   ██║██║╚██╗██║╚════██║
██║     ╚██████╔╝██║ ╚████║╚██████╗   ██║   ██║╚██████╔╝██║ ╚████║███████║
╚═╝      ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝                                                                      
*/

// a function that increases the setTemp by 1
void increaseTemp()
{
	lcd.clear();
	setTemp++;
	lcdAterantor = true;
	delayTime = 0;
}
// a function that decreases the setTemp by 1
void decreaseTemp()
{
	lcd.clear();
	setTemp--;
	lcdAterantor = true;
	delayTime = 0;
}

//a function to display and update the temperature in F and humidity with no arguments
void displayTemp()
{
	// update the LCD screen
	lcd.setCursor(0, 0);
	lcd.print("Temp: ");
	lcd.print(temp);
	lcd.print(" F");
	lcd.setCursor(0, 1);
	lcd.print("Humidity: ");
	lcd.print(humidity);
	lcd.print("%");
}

// update the temperature and humidity
void updateTemp()
{
	temp = dht.readTemperature(true);
	humidity = dht.readHumidity();
}

// a function to display the setTemp
void displaySetTemp()
{
	// update the LCD screen 
	lcd.setCursor(0, 0);
	lcd.print("Set Temp: ");
	lcd.print(setTemp);
	lcd.print(" F");
}

// a function that calculates the loop time
// this is used to calculate the time between each loop
// this was taken from my project code
void runLoopTime()
{
	previousTime = currentTime;
	currentTime = millis();
	loopTime = currentTime - previousTime;
}