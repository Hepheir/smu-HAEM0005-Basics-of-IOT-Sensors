#define BUZZER_PIN 3
#define BUZZER_FREQ 523
#define BUZZER_DURATION 500

void setup() {
    tone(BUZZER_PIN, BUZZER_FREQ, BUZZER_DURATION);
    delay(500);
}

void loop() {
}