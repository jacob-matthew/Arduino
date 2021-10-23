

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position 

void setup(){
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT); 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 

}

void loop(){
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(2);
  //print out the value of the pushbutton
  Serial.println(sensorVal);
  
  // Keep in mind the pullup means the pushbutton's
  // logic is inverted. It goes HIGH when it's open,
  // and LOW when it's pressed. Turn on pin 13 when the 
  // button's pressed, and off when it's not:
  if (sensorVal == LOW) {
    digitalWrite(13, HIGH);
    myservo.write(180);           
    delay(300);                                
    myservo.write(8);               
    delay(300);                        
    myservo.write(185);              
    delay(300);                      
  } 
  else {
    digitalWrite(13, LOW);
                
  }
}
