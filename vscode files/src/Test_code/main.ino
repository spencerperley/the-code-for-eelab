






int varDelay = 500; // Set a constant "ConstantDelay" to an integer 500

int blink (int blinkSpeed,int pinNum){
    digitalWrite(pinNum,HIGH); // Set pin 13 to HIGH (5v) 
    delay(blinkSpeed);  // Pause for 500ms 
    digitalWrite(pinNum,LOW);  // Set pin 13 to LOW (5v)

}

void setup() // This is the function to settup the arduino 
{
    for (int i = 1 ; i < 7 ; i = i + 1 ){
        pinMode(i,OUTPUT);  // Initiation of the built-in led on pin 13 as an output
    }
} // End brakets indicate end of settup function 

void loop()  // Start the main loop
{
    while (varDelay>10){

        for (int i = 1 ; i < 7 ; i = i + 1 ){
            blink(varDelay,i);
        }

        for (int i = 6 ; i > 0 ; i = i - 1 ){
            blink(varDelay,i);
        }
        
        varDelay=varDelay/2;

    }    
    varDelay = 500;
    
} // End the main loop 



