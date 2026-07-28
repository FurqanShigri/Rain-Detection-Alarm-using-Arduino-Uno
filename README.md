# 🌧️ Rain Detection Alarm using Arduino Uno

## 📌 Project Overview

The **Rain Detection Alarm** is an Arduino-based project that detects rainfall using a **YL-83 Rain Sensor** and **YL-38 (LM393) Rain Sensor Module**. When rain is detected, the Arduino activates a buzzer to alert the user. This project is simple, inexpensive, and useful for weather monitoring and home automation applications.

---

## 🎯 Objectives

* Detect rain using a rain sensor.
* Alert the user with a buzzer when rain is detected.
* Display sensor values through the Serial Monitor.
* Learn how to interface analog sensors with Arduino.

---

## 🛠️ Components Required

| Component                        | Quantity    |
| -------------------------------- | ----------- |
| Arduino Uno                      | 1           |
| YL-83 Rain Sensor Plate          | 1           |
| YL-38 (LM393) Rain Sensor Module | 1           |
| Active Buzzer (5V)               | 1           |
| Jumper Wires                     | As Required |
| Breadboard (Optional)            | 1           |
| USB Cable                        | 1           |

---

## 🔌 Circuit Connections

### Rain Sensor Module

| YL-38 Module Pin | Arduino Uno |
| ---------------- | ----------- |
| VCC              | 5V          |
| GND              | GND         |
| AO               | A0          |

### Buzzer

| Buzzer Pin   | Arduino Uno   |
| ------------ | ------------- |
| Positive (+) | Digital Pin 8 |
| Negative (-) | GND           |

### Rain Sensor Plate

Connect the **YL-83 Rain Sensor Plate** to the two terminals on the **YL-38 Module** marked **+** and **-**.

---

## ⚙️ Working Principle

1. The YL-83 sensor plate detects water droplets on its surface.
2. The YL-38 module converts the sensor signal into an analog voltage.
3. Arduino continuously reads the analog value from pin **A0**.
4. When the sensor value falls below the predefined threshold, rain is detected.
5. Arduino turns ON the buzzer to notify the user.
6. When the sensor dries, the buzzer turns OFF automatically.

---

## 💻 Arduino Code

```cpp
const int rainSensor = A0;
const int buzzer = 8;

int threshold = 500;

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
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }

  delay(200);
}
```

---

## ▶️ How to Run

1. Assemble the circuit according to the connection table.
2. Upload the Arduino code to the Arduino Uno.
3. Open the **Serial Monitor** at **9600 baud**.
4. Observe the sensor value.
5. Sprinkle a few drops of water on the sensor plate.
6. The buzzer should turn ON when rain is detected.

---

## 📊 Expected Output

### Dry Sensor

```
Rain Sensor Value: 850
Buzzer: OFF
```

### Wet Sensor

```
Rain Sensor Value: 250
Buzzer: ON
```

> **Note:** The sensor values may vary depending on the module and sensitivity adjustment. Change the `threshold` value if needed.

---

## 🌍 Applications

* Rain warning systems
* Smart clothes drying systems
* Automatic window closing systems
* Greenhouse monitoring
* Agriculture and irrigation
* Smart home automation
* Weather monitoring stations

---

## 🚀 Future Improvements

* Add a 16×2 LCD to display rain status.
* Add LEDs for visual indication.
* Send notifications using Wi-Fi (ESP8266/ESP32).
* Control a servo motor to close windows automatically.
* Upload rain data to an IoT cloud platform.

---

## 🛠️ Troubleshooting

### Sensor value always shows 0

* Check that the **AO** pin is connected to **A0**.
* Ensure the YL-38 module is powered with **5V** and **GND**.
* Verify that the YL-83 sensor plate is connected to the module.
* Test using `analogRead(A0)` to verify the analog signal.
* If using a simulator, ensure it supports analog rain sensor simulation.

### Buzzer is always ON

* Increase the threshold value.
* Check if the sensor plate is wet or dirty.
* Adjust the sensitivity potentiometer on the YL-38 module.

### Buzzer never turns ON

* Check the buzzer wiring.
* Verify the buzzer works by connecting it directly to 5V briefly.
* Confirm the threshold value matches your sensor readings.

---

## 📚 Learning Outcomes

By completing this project, you will learn:

* Arduino analog input reading
* Using environmental sensors
* Controlling digital outputs
* Sensor calibration
* Basic embedded system programming

---

## 👨‍💻 Author

**Project:** Rain Detection Alarm using Arduino Uno

Built using **Arduino Uno**, **YL-83 Rain Sensor**, **YL-38 Rain Sensor Module**, and an **Active Buzzer**.
