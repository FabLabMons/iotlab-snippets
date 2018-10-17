/* Reads photoresistance value on pin A0 and displays the value on serial console. */

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  int lightValue = analogRead(A0);
  Serial.println(lightValue);
  delay(1000);
}