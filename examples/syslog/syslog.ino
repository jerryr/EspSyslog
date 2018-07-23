#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#define SSID "My_ssid_here"
#define PASSWD "My_passwd_here"
WiFiClient client;

WiFiUDP udp;
#include <Syslog.h>

Syslog logger("gadget", "testapp", "192.168.1.200");
void setup() {
  Serial.begin(115200);
  WiFi.begin(SSID, PASSWD);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  logger.info("Connected to wifi");
}

void loop() {
  logger.debug("running loop");
  delay(2000);
}
