/*

NOTE:
This implementation represents a prototype version of the GridShield.
For rapid development and testing, WiFi-based communication has been used.
In real-world deployment, this system is intended to operate over industrial communication protocols (e.g., Ethernet / IEC-based standards).
 
Certain components of the system, particularly related to data integrity and security mechanisms, 
have been intentionally abstracted and are not fully disclosed in this repository. 
As this project targets critical infrastructure applications,
complete implementation details cannot be publicly shared at this stage.
Full system architecture and detailed implementation can be demonstrated
upon request or during further evaluation.

*/

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "mbedtls/sha256.h"

const char* WIFI_SSID     = "PARTH";
const char* WIFI_PASSWORD = "1234567890";
const char* API_ENDPOINT  = "http://192.168.1.100:5000";

#define PIN_VOLTAGE 34
#define PIN_CURRENT 35

float VOLTAGE_SCALE = 0.25;
float CURRENT_SCALE = 0.185;

const unsigned long TRANSMIT_INTERVAL = 2000;
unsigned long lastTransmitTime = 0;

void setup() {
    Serial.begin(115200);
    delay(500);

    Serial.println("\n[INIT] GridShield Node Starting...");
    connectToNetwork();

    analogReadResolution(12);
}

void loop() {

    if (millis() - lastTransmitTime < TRANSMIT_INTERVAL) {
        return;
    }

    if (WiFi.status() != WL_CONNECTED) {
        reconnectNetwork();
    }

    float voltage = readVoltage();
    float current = readCurrent();

    transmitData(voltage, current);

    lastTransmitTime = millis();
}

void connectToNetwork() {

    Serial.print("[NET] Connecting");

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) {
        delay(500);
        Serial.print(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\n[NET] Connected | IP: " + WiFi.localIP().toString());
    } else {
        Serial.println("\n[NET] Connection Failed");
    }
}

void reconnectNetwork() {
    Serial.println("[NET] Reconnecting...");
    WiFi.disconnect();
    connectToNetwork();
}


float readStableADC(int pin) {

    const int sampleCount = 50;
    long total = 0;

    for (int i = 0; i < sampleCount; i++) {
        total += analogRead(pin);
        delay(2);
    }

    return (float)total / sampleCount;
}

float readVoltage() {

    float adcValue = readStableADC(PIN_VOLTAGE);
    float voltage = adcValue * (3.3 / 4095.0);
    voltage = voltage / VOLTAGE_SCALE;

    Serial.println("[DATA] Voltage: " + String(voltage) + " V");
    return voltage;
}

float readCurrent() {

    float adcValue = readStableADC(PIN_CURRENT);
    float sensorVoltage = adcValue * (3.3 / 4095.0);
    float current = (sensorVoltage - 2.5) / CURRENT_SCALE;

    Serial.println("[DATA] Current: " + String(current) + " A");
    return current;
}


String generateIntegrityCode(const String& input) {

    byte hash[32];
    mbedtls_sha256_context ctx;

    mbedtls_sha256_init(&ctx);
    mbedtls_sha256_starts(&ctx, 0);
    mbedtls_sha256_update(&ctx,
        (const unsigned char*)input.c_str(),
        input.length()
    );
    mbedtls_sha256_finish(&ctx, hash);
    mbedtls_sha256_free(&ctx);

    String output;
    for (int i = 0; i < 32; i++) {
        if (hash[i] < 16) output += "0";
        output += String(hash[i], HEX);
    }

    return output;
}

void transmitData(float voltage, float current) {

    unsigned long timestamp = millis();

    StaticJsonDocument<256> payload;

    String baseString = "NODE-GS-001"
                      + String(voltage, 2)
                      + String(current, 2)
                      + String(timestamp);

    String integrityCode = generateIntegrityCode(baseString);

    payload["node_id"]   = "NODE-GS-001";
    payload["voltage"]   = voltage;
    payload["current"]   = current;
    payload["power"]     = voltage * current;
    payload["timestamp"] = timestamp;
    payload["safety_code"] = integrityCode;

    String jsonData;
    serializeJson(payload, jsonData);

    HTTPClient http;
    http.begin(API_ENDPOINT);
    http.addHeader("Content-Type", "application/json");

    int responseCode = http.POST(jsonData);

    if (responseCode > 0) {
        Serial.println("[API] Status: " + String(responseCode));
        Serial.println("[API] Response: " + http.getString());
    } else {
        Serial.println("[ERROR] Transmission Failed (" + String(responseCode) + ")");
    }

    http.end();
}