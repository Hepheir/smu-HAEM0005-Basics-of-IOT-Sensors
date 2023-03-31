/*
  Author: 202115064 김동주 <hepheir@gmail.com>

  Prerequisite:
    (Library) EduIntro by Arduino LLC (v0.0.16)
    -> can be installed via Arduino IDE Library manager
*/

#include <EduIntro.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT11 dht(DHTPIN);

void setup() {
    Serial.begin(9600);
}

void loop() {
    // EduIntro: read data and return status
    dht.update();

    delay(2000);
    int h = dht.readHumidity();
    int t = dht.readCelsius();

    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" C");
}