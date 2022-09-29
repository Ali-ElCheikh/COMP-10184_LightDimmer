// Mohawk College - COMP-10184 
// 
// Digital Input/Output Lab - Test Program 
// 

/**
 * I, Ali El Cheikh Ali, student number 000760145, certify that what I am submitting is my own work;
 * that I have not copied it from any other source. I also certify that I have not allowed my work to be copied by others
 */
#include <Arduino.h> 

//Global variables
int inPush = D5;
int outLED = D4;
float iVal;

byte lastBtnState;
byte ledState = LOW;

void setup() { 
  
  //This is the pushbutton 
  pinMode(inPush, INPUT_PULLUP); 
  
 
  //This is the LED 
  pinMode(outLED, OUTPUT); 
 

} 

 
void loop() {

  byte iButton = digitalRead(inPush);  

  iVal = analogRead(A0);
  
  //Code for the button to turn ON once pressed (if it is OFF), turn OFF once pressed (if it is ON), and to keep it in the same state if the button does not get pressed.
  if (iButton != lastBtnState) {
    
    lastBtnState = iButton;

    if (iButton == LOW) {
      if (ledState == HIGH) {

        ledState = LOW;

      }
      else {

        ledState = HIGH;
      
      }

      digitalWrite(outLED, ledState);

    }
  }

    // code for the dial to dim/brighten the LED
    if (ledState == LOW){
      
      iVal = (255./1023.) * iVal; //Used to utilize the entire "resistor" dial, if it is off then it will only utilize some of the circle dial.
      analogWrite(outLED, iVal);
      
    }

  delay(1); 
  
}



 
