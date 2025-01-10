// Pin definitions
const int gasSensorPin = A0;  // MQ-2 sensor analog pin
const int ledPin = 9;         // LED pin
const int buzzerPin = 10;     // Buzzer pin
const int gasThreshold = 300; // Gas level threshold (adjust as needed)

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(gasSensorPin, INPUT);
  Serial.begin(9600); // Start serial communication
}

void loop() {
  int gasLevel = analogRead(gasSensorPin); // Read gas level
  Serial.print("Gas Level: ");
  Serial.println(gasLevel);

  if (gasLevel > gasThreshold) {
    // Gas detected above threshold
    digitalWrite(ledPin, HIGH);  // Turn on LED
    digitalWrite(buzzerPin, HIGH); // Turn on buzzer
    Serial.println("Gas Detected! Alert!");
  } else {
    // No gas detected
    digitalWrite(ledPin, LOW);   // Turn off LED
    digitalWrite(buzzerPin, LOW); // Turn off buzzer
  }

  delay(500); // Small delay for stability
}
