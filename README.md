# Evil Crow Cable Pro
BadUSB and Hardware Keylogger cable based on RP2040 microcontroller.

![EvilCrow](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/logo.png)

**Idea, development and implementation:** Joel Serna (@JoelSernaMoreno).

**PCB design:** Ignacio Díaz Álvarez (@Nacon_96) and Forensic Security (@ForensicSec).

**Manufacturer and distributor:** AprilBrother (@aprbrother).

The developers and collaborators of this project do not earn money with this. 
You can invite me for a coffee to further develop Low-Cost hacking devices. If you don't invite me for a coffee, nothing happens, I will continue developing devices.

[![ko-fi](https://www.ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/E1E614OA5)

**Available with April Brother (shipping from China):** 

* https://www.aliexpress.us/item/3256806544396556.html

**Available with SAPSAN Cybersec & Military (shipping from EU, Poland):**

* https://sapsan-sklep.pl/en/products/evil-crow-cable-pro-badusb

**Available with KSEC Worldwide (shipping from United Kingdom):**

* https://labs.ksec.co.uk/product/evil-crow-cable-pro-usb-c/

**Available with Tienda Espía (shipping from Mexico):**

* https://tiendaespia.com.mx/producto/evil-crow-cable-pro-badusb-keylogger/

**Summary:**
1. Disclaimer
2. Introduction
3. Installation
	* Basic requirements
	* Layouts
	* Payloads
4. Firmware
	* Configuration
	* Change USB configuration
	* Keylogger viewlog
	* Keylogger deletelog
	* Data exfiltration
	* Data exfiltration viewlog
	* Data exfiltration deletelog
	* Format FS
5. Keylogger
	* With adapter
	* Weaponize a keyboard

![EvilCrowCablePro](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/evilcrowcablepro.jpeg)

# Disclaimer
Evil Crow Cable Pro is a basic device for professionals and cybersecurity enthusiasts.

We are not responsible for the incorrect use of Evil Crow Cable Pro.

We recommend using this device for testing, learning and fun :D

# Introduction

Evil Crow Cable Pro is a BadUSB and Hardware Keylogger device based on RP2040 microcontroller. 

**NOTE:**

* All devices have been flashed with basic firmware Evil Crow Cable Pro before shipping (Keylogger firmware).
* Please do not ask me to implement new functions in this code. You can develop code for Evil Crow Cable Pro and send PR with your new code.

# Installation

## Basic requirements

1. Download and Install Arduino IDE 2.3.6: https://www.arduino.cc/en/main/software
2. Download Evil Crow Cable Pro repository: git clone https://github.com/joelsernamoreno/EvilCrowCable-Pro.git
3. Open Arduino IDE.
4. Go to File - Preferences. Locate the field "Additional Board Manager URLs:" Add "https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json" without quotes. Click "Ok".
5. Select Tools - Board - Boards Manager. Search for "rp2040". Install "Raspberry Pi Pico/RP2040 version 5.4.0 by Earle F. Philhower". Click "Close".
6. Go to EvilCrowCable-Pro/libraries directory and unzip all libraries in Arduino libraries directory.
7. Open firmware.ino in Arduino IDE.
8. Select Tools:

	* Board - "Raspberry Pi Pico".
	* Flash Size - "2MB (Sketch: 1MB, FS: 1MB)".
	* CPU Speed - "120 MHz".
	* USB Stack - "Adafruit TinyUSB".
	* All other options: Default
	
9. Flash firmware.

## Layouts

Evil Crow Cable Pro is configured with English layout (EN_US), but is compatible with other keyboard layouts:

Available layouts:

* US_KEYBOARD
* ES_KEYBOARD
* UK_KEYBOARD
* FR_KEYBOARD
* DK_KEYBOARD
* DE_KEYBOARD
* IT_KEYBOARD
* PT_KEYBOARD
* FI_KEYBOARD
* BE_KEYBOARD
* BR_KEYBOARD
* TR_KEYBOARD

Edit USBCrowKeyboard.cpp in your Arduino library directory (USBCrowKeyboard/USBCrowKeyboard.cpp). Modify #define US_KEYBOARD to new layout (example: #define ES_KEYBOARD). Flash firmware again.

![Layout](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/layout.png)

**NOTE:** Not all layouts tested. If you find any wrong key you can change it and send PR to Evil Crow Cable Pro repository.

## Payloads

In firmware.ino you can find a file to include the payload (payload.h). Modify this with your new payload.

![Payload](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/payload.png)

**NOTE:** Check EvilCrowCable-Pro/payloads for some examples :)

# Firmware

This firmware allows a combination of Hardware Keylogger and BadUSB.

**NOTE:** The flash memory is very small. Do not store very large logs or you will brick Evil Crow Cable Pro.

## Configuration

You can configure the Keylogger and BadUSB from the config.h file:

* #define CHANGE_USB_CONFIG (true or false): Set CHANGE_USB_CONFIG true to change Vendor ID, Product ID, Manufacturer and Product.
* #define PAYLOAD_RUN (true or false): Set PAYLOAD_RUN true to execute the payload included in payload.h. Set PAYLOAD_RUN false to not execute the payload.
* #define KEYLOGGER (true or false): Set KEYLOGGER true to enable Evil Crow Cable Pro as a Hardware Keylogger. Set KEYLOGGER false to disable Hardware Keylogger.
* #define EXFIL (true or false): Set EXFIL true to enable Evil Crow Cable Pro to exfiltrate data. Set EXFIL false to disable data exfiltration.
* #define EXFIL_VIEWLOG (true or false): Set EXFIL_VIEWLOG true to view the data exfiltration log (serial monitor).
* #define EXFIL_DELETELOG (true or false): Set EXFIL_DELETELOG true to delete log.
* #define KEYLOGGER_VIEWLOG (true or false): Set KEYLOGGER_VIEWLOG true to view the keylogger log (serial monitor).
* #define KEYLOGGER_DELETELOG (true or false): Set KEYLOGGER_DELETELOG true to delete log.
* #define FORMATFS (true or false): Set FORMATFS true to format FS.

![Config](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/config.png)

## Change USB configuration

Evil Crow Cable Pro is configured with a default VID/PID/Manufacturer/Product. You can change the USB configuration. Set CHANGE_USB_CONFIG true to change Vendor ID, Product ID, Manufacturer and Product. (example: Apple keyboard):

![USBConfig](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/usbconfig.png)

If you enable CHANGE_USB_CONFIG to true, Evil Crow Cable Pro turns into an Apple keyboard.

![USBDmesg](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/usb-dmesg.png)

## Keylogger viewlog

Configure #define KEYLOGGER_VIEWLOG true in config.h. Flash the firmware in Evil Crow Cable Pro, open serial monitor and wait 10 seconds. 

![KeyloggerView](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/keyloggerview.png)

## Keylogger deletelog

Configure #define KEYLOGGER_DELETELOG true in config.h. Flash the firmware in Evil Crow Cable Pro, open serial monitor and wait 5 seconds. 

![KeyloggerDelete](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/keyloggerdelete.png)

## Data exfiltration

Set #define EXFIL true in config.h to enable data exfiltration.
Use exfilWin(command), exfilNix(command) or exfiMac(command) in payload.h. For example:

* exfilWin("systeminfo");
* exfilNix("cat /etc/passwd");
* exfilMac("whoami");

![ExfilPayload](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/exfilpayload.png)

## Data exfiltration viewlog

Configure #define EXFIL_VIEWLOG true in config.h. Flash the firmware in Evil Crow Cable Pro, open serial monitor and wait 10 seconds. 

Example:

delay(2000);
exfilNix("whoami");
delay(3000);
exfilNix("cat /etc/passwd");

![ExfilView](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/exfilviewlog.png)

## Data exfiltration deletelog

Configure #define EXFIL_DELETELOG true in config.h. Flash the firmware in Evil Crow Cable Pro, open serial monitor and wait 5 seconds. 

![ExfilDelete](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/exfildeletelog.png)

## Format FS

1. Open firmware.ino and set #define FORMATFS true. Flash the firmware and wait 10 seconds.
2. Set #define FORMATFS false in config.h and configure config.h with your new configuration. Flash the firmware.

![FS](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/fs.png)

Format FS OK:

![FSFormat](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/fsformat.png)

# Keylogger

## With adapter

You can use an adapter:

![KeyloggerAdapter](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/keyloggeradapter.jpg)

## Weaponize a keyboard

1. Open a keyboard:

![OpenKeyboard](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/openkeyboard.jpeg)

2. Cut the keyboard cable

![CutKeyboard](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/cutkeyboard.jpeg)

3. Solder Evil Crow Cable Pro

![SolderKeyboard](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/solderkeyboard.jpg)

4. Close the keyboard

![Keyboard](https://github.com/joelsernamoreno/EvilCrowCable-Pro/blob/main/images/keyboard.jpeg)
