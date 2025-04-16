#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Pin definitions
#define TRIG_PIN 9
#define ECHO_PIN 8
#define BUZZER_PIN 7
#define EMERGENCY_BUTTON 6

// Ultrasonic sensor variables
long duration;
int distance;

// GPS and GSM setup
SoftwareSerial gpsSerial(4, 3); // RX, TX for GPS
SoftwareSerial gsmSerial(10, 11); // RX, TX for GSM
TinyGPSPlus gps;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(EMERGENCY_BUTTON, INPUT_PULLUP);

  Serial.begin(9600);
  gpsSerial.begin(9600);
  gsmSerial.begin(9600);

  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  checkObstacle();
  readGPS();
  checkEmergencyButton();
}

void checkObstacle() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  if (distance > 0 && distance < 50) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }
}

void readGPS() {
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }
}

void checkEmergencyButton() {
  if (digitalRead(EMERGENCY_BUTTON) == LOW) {
    if (gps.location.isValid()) {
      String latitude = String(gps.location.lat(), 6);
      String longitude = String(gps.location.lng(), 6);
      sendSMS("Emergency! Location: " + latitude + ", " + longitude);
    } else {
      sendSMS("Emergency! Location not available.");
    }
    delay(5000); // Debounce delay
  }
}

void sendSMS(String message) {
  gsmSerial.println("AT+CMGF=1"); // Set SMS to text mode
  delay(100);
  gsmSerial.println("AT+CMGS=\"+1234567890\""); // Recipient's phone number
  delay(100);
  gsmSerial.println(message);
  delay(100);
  gsmSerial.write(26); // End message with Ctrl+Z
  delay(5000);
}
