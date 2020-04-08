/*
  SD card read/write example.
  
  Doesn't do anything in the loop, 
  it just writes into a file, and then reads the same file, all at setup. 

  If you run it several times, the same text will be appended to the end of 
  the file.
*/

#include <SPI.h>
#include <SD.h>

File myFile;
const int chipSelect = 53; // pin used on Arduino Mega

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("hello.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to hello.txt...");
    myFile.println("Hello world. This is written on the SD card.");
    // close the file:
    myFile.close();
    Serial.println("Done");
  } else {
    // if the file didn't open, print an error:
    Serial.println("Error opening hello.txt for writing");
  }

  // re-open the file for reading:
  myFile = SD.open("hello.txt");
  if (myFile) {
    Serial.println("Contents of file hello.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("Error opening hello.txt for reading");
  }
}

void loop() {
  // nothing happens after setup
}
