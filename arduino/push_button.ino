/* Blinks a LED on pin 10 when the button on pin 12 is pressed. */

const int ledPin = 10;
const int pushButton = 12;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pushButton, INPUT);
}

void loop() {
  int buttonState = digitalRead(pushButton);
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
  }
}