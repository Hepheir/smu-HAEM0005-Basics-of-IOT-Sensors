/**
 * @brief
 *
 * [Tools] - [Serial Monitor] 을 열고 콘솔 메시지 입력에 0 혹은 1을 입력하면, 값에 따라 13번 핀에 전압이 HIGH 혹은 LOW가 출력됨.
 *
 */

#define LED 13

int i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() <= 0) {
    return;
  }
  i = Serial.read();
  Serial.println(i);

  switch (i)
  {
  case '1':
    digitalWrite(LED, HIGH);
    break;

  case '0':
    digitalWrite(LED, LOW);
    break;

  default:
    break;
  }
}
