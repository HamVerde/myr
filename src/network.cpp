#include "network.hpp"

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

WiFiUDP udp;
char buffer [1];

void setupNetwork() {
  WiFi.mode(WIFI_STA);
  WiFi.begin("", "");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  udp.begin(50001);
}

char readNetwork() {
  buffer[0] = 0;

  int length = udp.parsePacket();
  if (length > 0) {
    udp.read(buffer, 1);
  }

  return buffer[0];
}
