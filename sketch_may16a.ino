#include <ESP8266WiFi.h>

#define BLYNK_TEMPLATE_ID "TMPL6PJ3T2h7k"
#define BLYNK_TEMPLATE_NAME "Fish Feeder"
#define BLYNK_AUTH_TOKEN "W9qM9wUrJ0vsvQ_2L3DAj908FiigdgyD"

#include <BlynkSimpleEsp8266.h>
#include <Servo.h>



// Data Blynk
char auth[] = "W9qM9wUrJ0vsvQ_2L3DAj908FiigdgyD";  // Token yang diberikan oleh Blynk
char ssid[] = "Huluhhh";        // Nama jaringan WiFi
char pass[] = "12345678";    // Password WiFi

Servo myServo;  // Membuat objek servo
#define BUZZER_PIN D5   

// Fungsi untuk mengatur servo
BLYNK_WRITE(V0) {  // V1 adalah tombol pada Blynk
  int pinValue = param.asInt();  // Mendapatkan status tombol (0 atau 1)
  if (pinValue == 1) {
    myServo.write(180);  // Membuka pakan pada 90 derajat
    digitalWrite(BUZZER_PIN, HIGH);
    delay(500);
    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
    myServo.write(0);
  } else {
    myServo.write(0);   // Menutup dispenser pakan pada 0 derajat
  }
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  myServo.attach(D2);  // Servo terhubung ke pin D2
  myServo.write(0);  // Servo pada posisi tertutup
   pinMode(BUZZER_PIN, OUTPUT);  // Set pin buzzer sebagai output
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  Blynk.run();
}
