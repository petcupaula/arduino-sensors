/*
 * Example of using a Digital Capacitive Touch Sensor Module
 * 
 */
 
#define sensorPin 2 //Arduino Digital pin D1
 
int ledPin = 13;

void setup() {
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);  
  pinMode(sensorPin, INPUT);
}
 
void loop() {
  int senseValue = digitalRead(sensorPin);
  
  if (senseValue == HIGH){
    digitalWrite(ledPin, HIGH);
    Serial.println("TOUCHED");
  }
  
  else{
    digitalWrite(ledPin,LOW);
    Serial.println("not touched");
  } 
  
  delay(500);
}
