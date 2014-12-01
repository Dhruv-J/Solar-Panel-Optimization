/* 
 * Copyright (c) Dhruv Jain, 2014
 * 
 * Liscense: Please see LISENCSE for lisencse and copy information
 */
 
// for controlling the two motors
#include <Servo.h>
Servo my_servo_x;
int xpos = 180;
Servo my_servo_y;
int ypos = 180;
int voltage_delay = 20;
int pos_delay=50;

void setup()
{
  my_servo_x.attach(12); //attaches the first servo to pin 12
  my_servo_y.attach(11); //attaches the second servo to pin 11
  Serial.begin(9600);
  Serial.print("Hello Terminal"); // prints hello terminal when you open the serial monitor
}

int readVoltage()
{
  int volt1, volt2, volt3; //says that there are three voltage measurements
  volt1 = analogRead(0); 
  delay(voltage_delay);
  volt2 = analogRead(0);
  delay(voltage_delay);
  volt3 = analogRead(0);
  delay(voltage_delay);
  int average = (volt1 + volt2 + volt3) / 3; //averages the three measurements out
  return average;
}

void loop() {
    xpos = 0;
    int volt, best_volt = 0;
    int best_x, best_y;
    
    while (xpos <= 180) 
    {
        //Serial.print(xpos); //prints xpos on serial monitor
        //Serial.println(" "); //prints new line
        my_servo_x.write(xpos); //makes position of my_servo_x to xpos
        
        ypos = 0;
        while (ypos <= 180)
        {
          //Serial.print(ypos); //prints ypos on serial monitor
          //Serial.println(" "); //prints new line
          my_servo_y.write(ypos); //makes position of my_servo_y to ypos
          
          volt = readVoltage();
          if (volt > best_volt)
          {
            best_volt = volt;
            best_x = xpos;
            best_y = ypos;
            Serial.println(best_volt);
            Serial.println(best_x);
            Serial.println(best_y);
            Serial.println("-----------");
          }
          
          ypos = ypos + 10; //increments ypos by 10
          // delay(500);
          delay(pos_delay);
        }
        
        xpos = xpos + 10; //increments xpos by 45
        delay(500);
     }   
     my_servo_x.write(best_x);
     my_servo_y.write(best_y);
     delay(1000000);
     
 }

    
    
   

