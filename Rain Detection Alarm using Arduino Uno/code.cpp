const int rainSensor = A0;
const int buzzer = 8;

int threshold = 500; // Adjust according to your sensor

void setup() {
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

  Serial.begin(9600);
}

void loop() {
  int rainValue = analogRead(rainSensor);

  Serial.print("Rain Sensor Value: ");
  Serial.println(rainValue);

  if (rainValue < threshold) {
    digitalWrite(buzzer, HIGH);  // Rain detected
  } else {
    digitalWrite(buzzer, LOW);   // No rain
  }

  delay(200);
}