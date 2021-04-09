/**** Wireless Mood Meter ***/

/*  author   : Ashraf Minhaj
 *  mail     : ashraf_minhaj@yahoo.com
 *  tutorial : youtube.com/fusebatti
 */

#include<Servo.h>

// declare servo name
Servo meter_servo;

// we'll store input data in this variable
char val;

void setup()
{
  //initlize the mode of the pins
   meter_servo.attach(9); 
   //set the serial communication rate with bluetooth module
   Serial.begin(9600);
}

void loop()
{ 
  while(Serial.available() == 0); //check whether arduino is reciving signal or not
  val = Serial.read() ;           //read data sent over bluetooth

  /********* Happy *********/
  if (val == 'h'){
    meter_servo.write(180);
  }

  /********* Medium Happy ***/
  if (val == 'm'){
    meter_servo.write(130);
  }

  /********* Neutral *******/
  if (val == 'n'){
    meter_servo.write(70);
  }

  /********* Sad *******/
  if (val == 's'){
    meter_servo.write(20);
  }
  
  /********* Angry *******/
  if (val == 'a'){
    meter_servo.write(0);
  }
}
