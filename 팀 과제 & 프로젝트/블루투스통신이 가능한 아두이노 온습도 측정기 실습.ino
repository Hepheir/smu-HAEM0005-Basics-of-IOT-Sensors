/**
  Author: Hepheir<hepheir@gmail.com>
 */

#include <SoftwareSerial.h>

#define BOUD_RATE 9600

#define PIN__ZS040__RX 10
#define PIN__ZS040__TX 11


SoftwareSerial mySerial(PIN__ZS040__RX, PIN__ZS040__TX);

void setup() {
  Serial.begin(BOUD_RATE);
  mySerial.begin(BOUD_RATE);
  mySerial.listen();
}

void loop() {
  Serial.print(mySerial.isListening());
  Serial.print(mySerial.peek());
  if (mySerial.available()) {
    Serial.write(mySerial.read());
    Serial.println("!");
  }
  mySerial.write(".");
  Serial.println(".");

  delay(300);
}