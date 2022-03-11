/* Combo Sweep with PushButton
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int myservoPin=  9;      // the number of the servo pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  pinMode(buttonPin, INPUT);
  pinMode(buttonPin,INPUT_PULLUP);
}

void checkButton(){
  buttonState = digitalRead(buttonPin);
  
  while(buttonState == HIGH)
    buttonState = digitalRead(buttonPin);
  
}
void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos); // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
    checkButton();
    
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
    checkButton();
    
  }


/* ignore
   // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn servo off:
    digitalWrite(myservoPin, LOW);
  } else {
    // turn servo on:
    digitalWrite(myservoPin, HIGH);
  }
  */
  
}
