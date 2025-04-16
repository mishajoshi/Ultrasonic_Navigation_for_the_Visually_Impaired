# Ultrasonic Navigation System for the Visually Impaired

## 📖 Overview  
This project is a wearable assistive device designed for visually impaired users. It uses ultrasonic sensors to detect nearby obstacles, a GPS module to track the user's location, and a GSM module to send emergency alerts via SMS with live GPS coordinates. The system is built around an Arduino UNO microcontroller programmed in Embedded C.

---

## 🛠️ Hardware Components

| Component             | Purpose                                          |
|:---------------------|:------------------------------------------------|
| Arduino UNO            | Central controller for processing sensor data   |
| HC-SR04 Ultrasonic Sensor | Detects obstacles by measuring distance       |
| Neo-6M GPS Module      | Provides real-time geographical location         |
| SIM800L GSM Module     | Sends SMS alerts with GPS data                   |
| Buzzer                 | Generates sound alerts for obstacles             |
| Emergency Button       | Triggers emergency SMS transmission               |
| Breadboard + Jumper Wires | Physical connections and prototyping         |

---

## 💻 Software & Tools

- **Arduino IDE**
- **Embedded C**
- **TinyGPS++ Library**
- **SoftwareSerial Library**

---

## 📝 Features

- **Obstacle Detection:**  
  Detects obstacles within 50 cm and activates a buzzer for alert.

- **Real-Time GPS Tracking:**  
  Continuously monitors and updates the user's location using the Neo-6M module.

- **Emergency SMS Alerts:**  
  Sends an SMS with GPS coordinates to a preset phone number when the emergency button is pressed.

---

## 🚀 Getting Started

### 📦 Prerequisites

- Install **Arduino IDE**
- Install the **TinyGPS++** library (via Library Manager)
- Install **SoftwareSerial** (pre-installed in most Arduino IDE setups)

### 🔌 Wiring Connections

| Component         | Arduino Pin  |
|:-----------------|:-------------|
| HC-SR04 Trig      | 9             |
| HC-SR04 Echo      | 8             |
| Buzzer            | 7             |
| Emergency Button  | 6             |
| GPS RX            | 4             |
| GPS TX            | 3             |
| GSM RX            | 10            |
| GSM TX            | 11            |

### 📂 Upload the Code

1. Open `Ultrasonic_Navigation.ino` in the Arduino IDE.
2. Connect your Arduino UNO to your computer.
3. Select the correct COM port and board type (Arduino UNO).
4. Click **Upload**.

---

## 📊 Expected Output

- Buzzer sounds when an obstacle is detected within 50 cm.
- GPS coordinates are updated in real-time.
- On emergency button press, an SMS containing current GPS coordinates is sent to the preset number.

Example SMS:
```
Emergency! Location: 35.784732, -78.682649
```

---

## 📌 Future Improvements

- Add voice guidance or vibration motor feedback.
- Integrate multiple ultrasonic sensors for full directional awareness.
- Implement low battery and signal detection.

---

## 📃 License

This project is open-source and free to use for educational and personal projects.

