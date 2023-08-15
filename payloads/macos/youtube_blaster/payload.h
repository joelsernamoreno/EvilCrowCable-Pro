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
  Keyboard.println("osascript -e 'set volume 7'");
  delay(3000);
  Keyboard.println("open https://www.youtube.com/watch?v=dQw4w9WgXcQ");
}
