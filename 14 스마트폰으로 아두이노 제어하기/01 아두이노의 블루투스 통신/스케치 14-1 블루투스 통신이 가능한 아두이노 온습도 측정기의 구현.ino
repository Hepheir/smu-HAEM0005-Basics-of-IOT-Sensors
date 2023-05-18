#include <DHT.h>
#include <SoftwareSerial.h>

#define DHTTYPE DHT11
#define DHTPin 2

DHT dht(DHTPin, DHTTYPE);
SoftwareSerial BTSerial(10, 11);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("DHT 센서로 값 읽기 실패!");
    return;
  }

  BTSerial.print(t);
  BTSerial.print(",");
  BTSerial.print(h);
}