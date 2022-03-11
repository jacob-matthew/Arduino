#include <Stepper.h>

/*
 * Arduino stepper motor control with rotary encoder.
 * This is a free software with NO WARRANTY.
 * https://simple-circuit.com/
 */
 
// include Arduino stepper motor library
#include <Stepper.h>
 
// number of steps per one revolution is 2048 ( = 4096 half steps)
#define STEPS  2048
 
// define stepper motor control pins
#define IN1  11
#define IN2  10
#define IN3   9
#define IN4   8
 
// initialize stepper library
Stepper stepper(STEPS, IN4, IN2, IN3, IN1);
 
int8_t  quad = 0;
uint8_t previous_data;
 
void setup()
{
  stepper.setSpeed(10);  // set stepper motor speed to 10 rpm
 
  // get rotary encoder state
  previous_data = digitalRead(A5) << 1 | digitalRead(A4);
 
  // pin change interrupt configuration
  PCICR  = 2;      // enable pin change interrupt for pins PCINT14..8 (Arduino A0 to A5)
  PCMSK1 = 0x30;   // enable pin change interrupt for pins PCINT12 & PCINT13 (Arduino A4 & A5)
}
 
ISR (PCINT1_vect)  // ISR for Arduino A4 (PCINT12) and A5 (PCINT13) pins
{
  uint8_t current_data = digitalRead(A5) << 1 | digitalRead(A4);
 
  if( current_data == previous_data )
    return;
 
  if( bitRead(current_data, 0) == bitRead(previous_data, 1) )
    quad -= 1;
  else
    quad += 1;
  previous_data = current_data;
}
 
int8_t encoder_update(void)
{
  int8_t val = 0;
  while(quad >= 4){
    val += 1;
    quad -= 4;
  }
  while(quad <= -4){
    val -= 1;
    quad += 4;
  }
  return val;
}
 
// main loop
void loop()
{
  int8_t stp = encoder_update();
 
  while(stp != 0)
  {
    int8_t dir = (stp > 0) ? -1 : 1;
    stepper.step( 20 * dir );
    stp += dir;
    stp += encoder_update();
  }
 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
 
  delay(100);
 
}
 
// end of code.
