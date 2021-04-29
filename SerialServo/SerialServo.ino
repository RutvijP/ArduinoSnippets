
//This program is about parsing the serialport for int value which will then be converted to 
//servo value positions,which will be put onto a OLED display.

#include <Servo.h>
Servo myServo; // Servo object 
int servopin = 9;  
int val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(9);                       //Servo attached at Pin 9  
}

void loop() {

  while (Serial.available() > 0) {         //loop
  int val = Serial.parseInt();            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);        // scale it to use it with the servo (value between 0 and 180)
  myServo.write(val);                     // sets the servo position according to the scaled value
  delay(15);   
}
}
