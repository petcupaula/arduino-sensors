/*
 * Rotary encoder control with integrated pushbutton
 * 
 * Relies on enabling the internal pull-up resistors (otherwise could use external pull-up resistors)
 * 
 * Wiring and code based on: https://bildr.org/2012/08/rotary-encoder-arduino/
 * and http://tronicslab.com/rotary-encoders-complete-tutorial-3/
 * 
 * if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++; //clockwise movement
 * if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --; //counter-clockwise movement
*/

// Pins can not be changed 2/3 are special pins
int encoderPin1 = 2;
int encoderPin2 = 3;

// Push button switch
int encoderSwitchPin = 4;

// Volatile variables because the interrupt routine changes these variables
volatile int lastEncoded = 0;
volatile long encoderValue = 0;

long lastEncoderValue = 0;
int buttonVal = 0;
int lastButtonState = 0;

void setup() {
  Serial.begin (9600);
  
  pinMode(encoderPin1, INPUT);
  pinMode(encoderPin2, INPUT);
  pinMode(encoderSwitchPin, INPUT);

  digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
  digitalWrite(encoderPin2, HIGH); //turn pullup resistor on
  digitalWrite(encoderSwitchPin, HIGH); //turn pullup resistor on
  
  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3)
  attachInterrupt(0, updateEncoder, CHANGE);
  attachInterrupt(1, updateEncoder, CHANGE);
}

void loop(){  
  if(encoderValue != lastEncoderValue) {
    Serial.println(encoderValue);
    lastEncoderValue = encoderValue;
  }

  buttonVal = digitalRead(encoderSwitchPin);
  if(buttonVal == LOW && lastButtonState != buttonVal) {
    Serial.println("Button Pressed!");
  }
  lastButtonState = buttonVal;
  
  delay(1000); //just here to slow down the output, and show it will work even during a delay
}

void updateEncoder(){
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit //signalA
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit //signalB
  
  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number 
  int sum = (lastEncoded << 2) | encoded; //adding it to the previous encoded value 
  
  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++; 
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --; 
  
  lastEncoded = encoded; //store this value for next time 
}
