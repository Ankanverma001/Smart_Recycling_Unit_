# 🗑️ Smart Recycling Unit (SRU) ♻️
An IoT-powered smart recycling system that automates waste segregation into dry and wet categories using IR sensors and motor-controlled mechanisms. Developed for improving waste management practices in public, institutional, and hospitality sectors.

---

## 🚀 Project Highlights

- Automatic Dry/Wet waste detection
- IR sensor-based object detection
- Motor-controlled bin rotation
- IoT-enabled functionality for smart monitoring
- Cost-effective and modular hardware design
- Approved for installation at DJAC Building, IIT Kanpur

---

## 🧠 How It Works

1. Waste is inserted near the detection unit.
2. An **IR sensor** detects the object.
3. The system analyzes waste type (dry/wet logic can be upgraded via ML or moisture sensor).
4. A **12V DC motor** rotates the bin via **relay** based on classification.
5. The item is dropped into the correct bin (dry or wet).

---

## 🛠️ Components Used

| Component            | Quantity | Description                          |
|----------------------|----------|--------------------------------------|
| Arduino Nano         | 1        | Main microcontroller board           |
| IR Sensors           | 2        | Object detection                     |
| 12V DC Motor         | 1        | Bin rotation                         |
| 2-Channel Relay      | 1        | To switch motor direction            |
| Motor Driver (L298N) | 1        | (Optional for direction control)     |
| Power Adapter 12V    | 1        | For motor and relay module           |
| Jumper Wires         | –        | For connections                      |
| Breadboard/PCB       | 1        | (Zero PCB recommended)               |
| Bin Container        | 2        | Dry and Wet bins                     |

👉 See [`components_list.md`](components_list.md) for full part numbers.

---

## 💻 Arduino Code

Upload this code to your Arduino Nano:
[Click to view `sru_code.ino`](sru_code.ino)

```cpp
// Basic version – can be extended with IoT (ESP32, GSM, etc.)

int irSensor1 = 2; // Dry waste
int irSensor2 = 3; // Wet waste
int relay1 = 4;    // Motor CW
int relay2 = 5;    // Motor CCW

void setup() {
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
}

void loop() {
  if (digitalRead(irSensor1) == LOW) {
    // Detected dry waste
    digitalWrite(relay1, HIGH);
    delay(1000); // Rotate CW
    digitalWrite(relay1, LOW);
  }

  if (digitalRead(irSensor2) == LOW) {
    // Detected wet waste
    digitalWrite(relay2, HIGH);
    delay(1000); // Rotate CCW
    digitalWrite(relay2, LOW);
  }

  delay(500);
}
