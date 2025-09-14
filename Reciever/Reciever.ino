#include <espnow.h>
#include <ESP8266WiFi.h>

const uint16_t pin[4] = { 14, 12,  5, 4 };

int left = 0, right = 0;
// Callback function for receiving data
void receiveCallback(uint8_t *mac_addr, uint8_t *data, uint8_t len) {



// Set PWM values
  analogWrite(pin[0], data[0] );
  analogWrite(pin[1], data[1] );
  analogWrite(pin[2], data[2] );
  analogWrite(pin[3], data[3] );

  Serial.printf("pwm- &d  &d  &d  &d", data[0], data[1], data[2], data[3]);
}



void setup() {
  pinMode(pin[0], OUTPUT);
  pinMode(pin[1], OUTPUT);
  pinMode(pin[2], OUTPUT);
  pinMode(pin[3], OUTPUT);

  // Initialize Serial Monitor
  Serial.begin(9600);

  // Initialize Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  // Initialize ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register receiving callback function
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(receiveCallback);
}

void loop() {
  //Nothing

}
