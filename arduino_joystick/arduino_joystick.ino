/*
 * Basic control of a joystick
 * 
 * A Joystick Module has the following pins:
 * GND
 * +5V
 * X-Axis (analog)
 * Y-Axis (analog)
 * Push button
 * 
 * Based on: https://www.brainy-bits.com/arduino-joystick-tutorial/
 */


// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

void setup() {
  Serial.begin (9600);
  
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
}

void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin)); // value will be 0 if pressed
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin)); // value from 0 to 1023 (default somewhere around 512)
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin)); // value from 0 to 1023 (default somewhere around 512)
  Serial.print("\n\n");
  delay(500);
}
