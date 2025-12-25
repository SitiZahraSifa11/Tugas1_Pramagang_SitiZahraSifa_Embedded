# Tugas1_Pramagang_SitiZahraSifa_Embedded

# Simulasi IoT - Pembacaan Sensor & Pengiriman Data (MQTT)
Tugas ini merupakan implementasi sistem Internet of Things (IoT) yang
menggunakan perangkat keras yaitu alat fisik asli untuk membaca data sensor
suhu dan kelembaban, kemudian mengirimkan data tersebut ke broker MQTT
secara real-time.

Sistem ini menggunakan Arduino IDE dengan board ESP32
dan sensor DHT11

Proyek ini dibuat untuk memenuhi Tugas Awal Magang
Bidang Embedded System dan Internet of Things (IoT).

Tools & Teknologi
- Arduino IDE
- ESP32 Dev Module 
- Sensor DHT11
- Protocol MQTT
- Broker MQTT: test.mosquitto.org

Library:
- WiFi.h
- PubSubClient
- DHT sensor library for ESPx

MQTT Client (Monitoring):
- MQTT Explorer / IoT MQTT Panel (Android)

Alur Sistem
- ESP32 membaca data suhu dan kelembaban dari sensor DHT
- ESP32 terhubung ke jaringan WiFi
- Data sensor dikemas dalam format JSON
- Data dikirim ke broker MQTT setiap 5 detik
- Data dipantau melalui aplikasi MQTT client
