#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

const char* ssid = "realme narzo 50A Prime";
const char* password = "rf171207";

// Token dan chat ID Telegram Anda
#define botToken "8431349961:AAFcAHMpEC1NwC4zyx3MhOxBzZ9jL_SndCk"
#define chatID   "6819833943"

// Pin sensor MQ-2
int sensorPin = 34;     // pin analog ESP32
int threshold = 400;    // ambang asap

// LED dan buzzer
int ledPower = 4;       // LED indikator alat ON
int ledSmoke = 2;       // LED indikator asap
int buzzerPin = 15;     // Buzzer

WiFiClientSecure client;
UniversalTelegramBot bot(botToken, client);

void setup() {
  Serial.begin(115200);
  delay(2000);

  // Setup pin output
  pinMode(ledPower, OUTPUT);
  pinMode(ledSmoke, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Kondisi awal
  digitalWrite(ledPower, HIGH);   // Alat ON
  digitalWrite(ledSmoke, LOW);    // Tidak ada asap
  digitalWrite(buzzerPin, LOW);   // Buzzer OFF

  // Koneksi WiFi
  WiFi.begin(ssid, password);
  Serial.print("Menghubungkan WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWiFi Terhubung!");

  client.setInsecure();  // Telegram HTTPS
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print("Nilai Sensor Asap: ");
  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    digitalWrite(ledSmoke, HIGH);   // LED asap ON

    // Bunyi buzzer 1 detik
    digitalWrite(buzzerPin, HIGH);
    delay(1000);
    digitalWrite(buzzerPin, LOW);

    // Kirim pesan Telegram
    String warning = "⚠️ Peringatan! Asap rokok terdeteksi di kamar mandi putra lantai 1!\nNilai sensor: " + String(sensorValue);
    bot.sendMessage(chatID, warning, "");

    delay(5000); // jeda anti spam
  } 
  else {
    digitalWrite(ledSmoke, LOW);  // Tidak ada asap
    digitalWrite(buzzerPin, LOW);
  }

  delay(500);
}




