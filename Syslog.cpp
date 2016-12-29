#include <Arduino.h>
#include <WiFiUdp.h>
#include <Syslog.h>

void Syslog::dolog(uint8_t pri, char *message) {
  uint8_t buffer[MAX_PACKET_SIZE];
  uint16_t len = snprintf((char *)buffer, MAX_PACKET_SIZE, "<%d> %s %s: %s", pri, _host,
                                            _app, message);
  len = (len > MAX_PACKET_SIZE)?MAX_PACKET_SIZE:len; // handle truncation if message too long
  udp.beginPacket(_server, _port);
  udp.write(buffer, len);
  udp.endPacket();
}
