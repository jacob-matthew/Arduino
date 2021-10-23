//Gytis_Orz sketch from Hackster.io more info https://www.hackster.io/Gytis_Orz/macro-keypad-02cb43
// Wiring:
// VCC -> 5V
// GND -> GND
// OUT -> A1 (Analog 1)
#include<Keyboard.h>
#define KEY_MENU 0xED
void setup() {
 Serial.begin(9600);
}

void loop() {
 // is any button pressed?
 int valueA1=get_button();
 if(valueA1>0) { 
   Serial.print("Click button ");
   Serial.println(valueA1);
   delay(500);
 } 
}

// button detection
int get_button() {
 // get A1 analog input value
 int val=analogRead(A1);
 if(val>1000)
 return 1; //you can change the "return x;" to whatever you want like using a keyboard library you can make it to copy or paste something
 else if(val>900)
 return 2;
 else if(val>820)
 return 3;
 else if(val>750)
 return 4;
 else if(val>660)
 return 5;
 else if(val>620)
 return 6;
 else if(val>585)
 return 7;
 else if(val>540)
 return 8;
 else if(val>500)
 return 9;
 else if(val>475)
 return 10;
 else if(val>455)
 return 11;
 else if(val>425)
 return 12;
 else if(val>370)
 return 13;
 else if(val>300)
 return 14;
 else if(val>260)
 return 15;
 else if(val>200)
 return 16;
 else
   return 0; 
}
