/*
 * Example of using the DS1302 RTC module
 * 
 * Set up the actual time and date
 * and see the values on the serial monitor
 * 
 * Uses the RTC library here: https://github.com/chrisfryer78/ArduinoRTClibrary
 * 
 * Wiring: 
 *   SCLK -> 6, I/O -> 7, CE -> 8
 * or
 *   CLK -> 6 , DAT -> 7, Reset -> 8
 * 
 */

#include <virtuabotixRTC.h>

virtuabotixRTC myRTC(6, 7, 8);

void setup() {
   Serial.begin(9600);

   // One time setup - set current date time
   // This setup is done only one time and the module will continue counting it automatically
   // Remember to "comment/remove" this function once you're done
   // Format: seconds, minutes, hours, day of the week, day of the month, month, year
   //myRTC.setDS1302Time(15, 10, 11, 3, 8, 4, 2020); 

   // Once the time is set, comment, upload again but with commented code, and test if it is still counting correctly
   // by unplugging and then later plugging again the arduino, and checking the serial monitor.
}

void loop() {
   // This allows for the update of variables for time or accessing the individual elements.
   myRTC.updateTime();
  
   // Start printing elements
   Serial.print("Current Date / Time: ");
   Serial.print(myRTC.dayofmonth);
   Serial.print("/");
   Serial.print(myRTC.month);
   Serial.print("/");
   Serial.print(myRTC.year);
   Serial.print(" ");
   Serial.print(myRTC.hours);
   Serial.print(":");
   Serial.print(myRTC.minutes);
   Serial.print(":");
   Serial.println(myRTC.seconds);
  
  // Delay so the program doesn't print non-stop
   delay(1000);
}
