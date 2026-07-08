int buzzer = 8;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int light = analogRead(A4);
  delay(200);
}

