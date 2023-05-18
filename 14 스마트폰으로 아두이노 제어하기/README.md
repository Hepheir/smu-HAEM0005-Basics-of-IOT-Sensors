![](https://img.shields.io/badge/-Youtube-red?style=for-the-badge&logo=youtube)

# 온습도 모니터 앱 만들기

[![YOUTUBE][youtube/image]][youtube/video]


[youtube/video]: http://www.youtube.com/watch?v=SGGcZf7z6TM
[youtube/image]: https://img.youtube.com/vi/SGGcZf7z6TM/0.jpg


## 아두이노 코드

```cpp
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
```

## 모바일 애플리케이션

"03 온습도 모니터 앱 만들기" 폴더 내부에 있음.