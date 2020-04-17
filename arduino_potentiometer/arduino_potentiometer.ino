/*
  Example of using a potentiometer
  
  Based on: AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);

  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
