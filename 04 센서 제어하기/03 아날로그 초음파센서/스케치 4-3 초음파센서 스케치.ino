/*
  Author: 202115064 김동주 <hepheir@gmail.com>
 */

#define TRIG_PIN 2 // Output
#define ECHO_PIN 3 // Input

#define SPEED_OF_SOUND 343.0 // metres per second

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  float duration;
  float distance;

  float pulse_width_uS;
  float distance_cm;

  digitalWrite(TRIG_PIN, HIGH);
  delay(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  // distance = (340.0 * duration) / 10000 / 2;

  // Datasheet: https://www.elecrow.com/download/HC_SR04%20Datasheet.pdf
  pulse_width_uS = duration;
  distance_cm = pulse_width_uS / 58;

  Serial.print("Duration:");
  Serial.print(pulse_width_uS);
  Serial.println("uS");

  Serial.print("Distance:");
  Serial.print(distance_cm);
  Serial.println("cm");

  delay(500);
}