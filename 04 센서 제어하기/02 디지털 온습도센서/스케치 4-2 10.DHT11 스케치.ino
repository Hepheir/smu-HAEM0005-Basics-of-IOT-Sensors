/*
  Author: 202115064 김동주 <hepheir@gmail.com>

  Uses "DHT sensor library" by "Adafruit" v1.4.3
*/

#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    dht.begin();
}

void loop() {
    delay(1000);
    int h = dht.readHumidity();
    int t = dht.readTemperature();

    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" C");
}