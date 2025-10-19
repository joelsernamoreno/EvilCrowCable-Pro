// Based on Irongeek's PHUKD (Programmable HID USB Keystroke Dongle) Library: http://www.irongeek.com/i.php?page=security/programmable-hid-usb-keystroke-dongle

/********************************************************************
 * Opens the run bar and executes the command. 
 ********************************************************************/
void CommandAtRunBarMSWIN(char *SomeCommand){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(100);
  Keyboard.releaseAll();
  delay(1500);
  Keyboard.print(SomeCommand);
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
}

/********************************************************************
 * Run the program with admin privileges. - Joel Serna
 ********************************************************************/
void RunProgramAdminMSWIN(char *SomeCommand){
  Keyboard.press(KEY_LEFT_GUI);
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print(SomeCommand);
  delay(500);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(3000);
  Keyboard.press(KEY_LEFT_ARROW);
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
}

/********************************************************************
 * Opens the run bar and executes the command. 
 ********************************************************************/
void CommandAtRunBarGnome(char *SomeCommand){
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F2);
  delay(100);
  Keyboard.releaseAll();
  delay(1500);
  Keyboard.print(SomeCommand);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

/********************************************************************
 * Opens spotlight and executes the command. - Adam Baldwin
 ********************************************************************/
void CommandAtRunBarOSX(const char *SomeCommand){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  delay(100);
  Keyboard.releaseAll();
  delay(1500);
  Keyboard.print(SomeCommand);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll(); 
}

/********************************************************************
 * Minimize open windows. - Joel Serna
 ********************************************************************/
void MinimizeWindowMSWIN(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('d');
  delay(100);
  Keyboard.releaseAll();
}

/********************************************************************
 * Open the search box. - Joel Serna
 ********************************************************************/
void CommandOpenSearchMSWIN(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('s');
  delay(100);
  Keyboard.releaseAll();
}

/********************************************************************
 * Block active sessions. - Joel Serna
 ********************************************************************/
void BlockSessionMSWIN(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('l');
  delay(100);
  Keyboard.releaseAll();
}

/********************************************************************
 * Close active program. - Joel Serna
 ********************************************************************/
void CloseProgramsMSWIN(){
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  delay(100);
  Keyboard.releaseAll();
}

/********************************************************************
 * Opens New Terminal and executes command. -Adam Baldwin
 ********************************************************************/
void CommandAtNewTerminal(char *SomeCommand){
  CommandAtRunBarOSX("Terminal");
/*
  // Open a new terminal in case another one was open
  delay(1000);
  Keyboard.set_modifier(MODIFIERKEY_GUI);
  Keyboard.set_key1(KEY_N);
  Keyboard.send_now(); // send strokes
  Keyboard.set_modifier(0); //prep release of  control keys
  Keyboard.set_key1(0); //have to do this to keep it from hitting key multiple times.
  Keyboard.send_now(); //Send the key changes
  delay(1500);
  Keyboard.print(SomeCommand);
  Keyboard.set_key1(KEY_ENTER); 
  Keyboard.send_now();    
  Keyboard.set_key1(0);
*/
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('n');
  delay(100);
  Keyboard.releaseAll();
  delay(1500);
  Keyboard.print(SomeCommand);
  delay(200);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll(); 
}

/********************************************************************
 * Opens the run bar and executes the command. -Aaron Howell
 ********************************************************************/
void ShrinkCurWinOSX(){
/*
  Keyboard.set_modifier(MODIFIERKEY_GUI); //clover key
  Keyboard.set_key1(KEY_H); // clover-h hides window, clover-m minimizes window
  Keyboard.send_now();
  delay(250);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
*/
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('h');
  delay(100);
  Keyboard.releaseAll();
  delay(250);
}

/********************************************************************
 * Shrinks the active window to help hide it.
 ********************************************************************/
void ShrinkCurWin(){
/*
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.set_key1(KEY_SPACE);
  Keyboard.send_now(); 
  delay(250);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();  
  Keyboard.print("n");
*/
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(' ');
  delay(100);
  Keyboard.releaseAll();
  delay(250);
  Keyboard.print("n");
}

void ShrinkCurWinMSWIN(){
  ShrinkCurWin();
}

void ShrinkCurWinGnome(){
  ShrinkCurWin();
}

/********************************************************************
 * This function simplifies the pressing and releasing of a key.  
 ********************************************************************/
void PressAndRelease(int KeyCode,int KeyCount){
  int KeyCounter=0;
  for (KeyCounter=0;  KeyCounter!=KeyCount; KeyCounter++){
/*
    Keyboard.set_key1(KeyCode); // use r key
    Keyboard.send_now(); // send strokes
    Keyboard.set_key1(0); 
    Keyboard.send_now(); // send strokes
*/
    Keyboard.print(KeyCode);
  }
}
