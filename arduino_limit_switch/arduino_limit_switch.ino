/*
  Example to turn on and off the board's LED when pressing the limit switch attached to a digital pin.

  Using a limit switch is similar to using a button
 
  Based on: http://www.arduino.cc/en/Tutorial/Button
 */

const int limitPin = 2;     // the number of the limit switch pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int limitState = 0;         // variable for reading the limit switch status

void setup() {
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  
  // initialize the limit switch pin as an input:
  pinMode(limitPin, INPUT_PULLUP);
}

void loop() {

  limitState = digitalRead(limitPin);

  // Turn on LED when limit is pressed
  if (limitState == LOW) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
