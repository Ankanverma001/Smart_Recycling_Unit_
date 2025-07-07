// Smart Recycling Unit - SRU
// Developed by Ankan Verma & Team Soulo

// Pin configuration
const int irSensorDry = 2;    // IR Sensor for dry waste
const int irSensorWet = 3;    // IR Sensor for wet waste
const int relayCW = 4;        // Relay to rotate motor Clockwise (CW)
const int relayCCW = 5;       // Relay to rotate motor Counter-Clockwise (CCW)

void setup() {
  // Set pin modes
  pinMode(irSensorDry, INPUT);
  pinMode(irSensorWet, INPUT);
  pinMode(relayCW, OUTPUT);
  pinMode(relayCCW, OUTPUT);

  // Ensure motor is off at start
  digitalWrite(relayCW, LOW);
  digitalWrite(relayCCW, LOW);
}

void loop() {
  // Read sensors
  bool dryDetected = digitalRead(irSensorDry) == LOW; // Active LOW
  bool wetDetected = digitalRead(irSensorWet) == LOW;

  if (dryDetected) {
    segregateDry();
  } else if (wetDetected) {
    segregateWet();
  }

  delay(500); // Short delay to avoid false triggering
}

void segregateDry() {
  // Activate CW motor rotation
  digitalWrite(relayCW, HIGH);
  digitalWrite(relayCCW, LOW);
  delay(1000); // Adjust this to match your motor/bin movement
  stopMotor();
}

void segregateWet() {
  // Activate CCW motor rotation
  digitalWrite(relayCCW, HIGH);
  digitalWrite(relayCW, LOW);
  delay(1000); // Adjust this to match your motor/bin movement
  stopMotor();
}

void stopMotor() {
  // Stop motor by turning off both relays
  digitalWrite(relayCW, LOW);
  digitalWrite(relayCCW, LOW);
}
