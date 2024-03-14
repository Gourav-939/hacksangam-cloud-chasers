const int trigPins = 6;  // Trigger pin of the ultrasonic sensor
const int echoPins = 7;  // Echo pin of the ultrasonic sensor

void setup() {
  Serial.begin(9600);
  pinMode(trigPins, OUTPUT);
  pinMode(echoPins, INPUT);
}

void loop() {
  // Measure distance using ultrasonic sensor
  long duration;
  float distance;
  
  digitalWrite(trigPins, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPins, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPins, LOW);
  
  duration = pulseIn(echoPins, HIGH);
  distance = duration * 0.034 / 2;  // Speed of sound is 34 cm/ms
  
  // Print distance to serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Determine water level based on distance
  if (distance < 10) {
    Serial.println("Waste level is high!");
  } else if (distance < 20) {
    Serial.println("Waste level is medium.");
  } else {
    Serial.println("Waste level is low.");
  }

  delay(1000);  // Delay for stability, adjust as needed
}
