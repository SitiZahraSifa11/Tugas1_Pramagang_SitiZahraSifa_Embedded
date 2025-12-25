#include <WiFi.h>
#include <PubSubClient.h>
#include <DHTesp.h>

// ===== WIFI =====
const char* ssid = "Karna Roastwork";
const char* password = "followigkarna";

// ===== MQTT =====
const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;
const char* topic = "magang/iot/arduinoide";

// ===== OBJECT =====
WiFiClient espClient;
PubSubClient client(espClient);
DHTesp dht;

// ===== WIFI CONNECT =====
void setupWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
}

// ===== MQTT CONNECT =====
void reconnectMQTT() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("ESP32-ArduinoIDE")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setupWiFi();

  client.setServer(mqtt_server, mqtt_port);
  dht.setup(15, DHTesp::DHT11); // GPIO 15
}

void loop() {
  if (!client.connected()) {
    reconnectMQTT();
  }
  client.loop();

  TempAndHumidity data = dht.getTempAndHumidity();

  if (isnan(data.temperature) || isnan(data.humidity)) {
    Serial.println("Failed to read DHT11!");
    delay(2000);
    return;
  }

  String payload = "{";
  payload += "\"temperature\":";
  payload += String(data.temperature, 2);
  payload += ",";
  payload += "\"humidity\":";
  payload += String(data.humidity, 2);
  payload += "}";

  client.publish(topic, payload.c_str());

  Serial.println("Data terkirim:");
  Serial.println(payload);

  delay(5000);
}
