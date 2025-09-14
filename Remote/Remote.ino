#include <esp_now.h>
#include <WiFi.h>



const uint8_t pin_x = 35, pin_y = 34;                    // ADC pins for joystick
int X = 0, Y = 0;
uint8_t data[4];                                       //packet size.

esp_now_peer_info_t peerInfo;
uint8_t receiver_mac[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };  // Replace with receiver's MAC

void send(uint8_t data[]) {
  esp_now_send(peerInfo.peer_addr, data, sizeof(data));
}



void setup() {
  pinMode(pin_x, INPUT);
  pinMode(pin_y, INPUT);
  pinMode(2, OUTPUT);

  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }

  memset(&peerInfo, 0, sizeof(peerInfo));
  memcpy(peerInfo.peer_addr, receiver_mac, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    digitalWrite(2, 1);
    return;
  }
}



void loop() {
  X = analogRead(pinx);
  Y = analogRead(piny);

  X = map(X, 4095, 0, 7, -7);
  Y = map(Y, 4095, 0, 7, -7);

  //Zero_zone
  if (X >= -2 && X <= 2) X = 0;
  if (Y >= -2 && Y <= 2) Y = 0;

  //joystick to wheel
  int left = Y + X;
  int right = Y - X;
  left = constrain(map(left, -7, 7, -255, 255), -255, 255);
  right = constrain(map(right, -7, 7, -255, 255), -255, 255);

  data[0] = left > 0 ? left : 0;
  data[1] = left < 0 ? -left : 0;
  data[2] = right > 0 ? right : 0;
  data[3] = right < 0 ? -right : 0;


  send(data);  //cast for esp_now_send


  delay(30);
}
