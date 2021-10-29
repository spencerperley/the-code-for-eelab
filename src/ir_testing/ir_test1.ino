#include <LiquidCrystal.h>

#include <IRremote.h>

int RECV_PIN = 7; // the pin where you connect the output pin of IR sensor 

IRrecv irrecv(RECV_PIN); 

decode_results results; 

//Initialise the LCD with the arduino. LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {


    Serial.begin(9600); 

    irrecv.enableIRIn();  // Switch on the LCD screen

    lcd.begin(16, 2);  

    lcd.print("Waiting");  // Print these words to my LCD screen
}

void loop() {

  if (irrecv.decode(&results))  // Returns 0 if no data ready, 1 if data ready. 

 { 

  lcd.print(results.value); //prints the value a a button press 


  irrecv.resume(); // Restart the ISR state machine and Receive the next value 


}