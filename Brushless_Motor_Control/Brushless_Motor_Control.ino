// Jacob Brown
// August 26th 2021
// Control Brushless Motor with Potentiometer

#include <Servo.h>

Servo ESC;  //create servo object to control the ESC

int potValue;  //value from the analog pin


void setup() {
  //Attach the ESC on pin 9
  ESC.attach(9,1000,2000);  //(pin, min pulse width, max pulse width in mi)
}

void loop() {
  potValue = analogRead(A0);  //read the value of the potentiometer (val
  potValue = map(potValue, 0, 1023, 0, 180);
  ESC.write(potValue);
}
