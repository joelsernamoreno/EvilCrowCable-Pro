#include "exfil.h"
#include "phukd.h"

void payload() {
  delay(2000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.write('r');
  delay(100);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.println("powershell");
  delay(5000);
  Keyboard.println("Add-Type -AssemblyName System.speech");
  delay(2000);
  Keyboard.println("$speak = New-Object System.Speech.Synthesis.SpeechSynthesizer");
  delay(2000);
  Keyboard.println("$speak.Speak(\"This is a test\")");
  delay(2000);
  Keyboard.println("exit");
}
