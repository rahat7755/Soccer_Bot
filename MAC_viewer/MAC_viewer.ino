#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Get and print the MAC address
  String mac = WiFi.macAddress();
  Serial.print("ESP8266 MAC Address: ");
  Serial.println(mac);
}

void loop() {
  // Nothing here
}
