## Library for printing messages to Syslog on ESP8266

This library allows ESP8266-based devices to send messages to
remote syslog servers. This is especially useful when you've put your
code into production, and you no longer have access to the serial console
since it isn't connected to your laptop anymore, but hidden away inside a
wall somewhere.
You'll need to set up a machine on your network as a syslog server. The easiest
way to do this is to use a Raspberry Pi with Raspbian. Raspbian comes with
rsyslogd, which supports the remote syslog protocol, but this capability is
disabled by default. You'll need to uncomment the following lines from
`/etc/rsyslog.conf`:
```
$ModLoad imudp
$UDPServerRun 514
```
Then restart rsyslog:
```
systemctl restart rsyslog
```
Note that you can use any Linux distribution with rsyslog, not just Rasbian on a
Raspberry Pi.

### Installation
Use `git` to clone this repository into your Arduino libraries folder. On a Mac,
this is usually `Documents/Arduino/libraries`:
```
cd ~/Documents/Arduino/libraries
git clone https://www.github.com/jerryr/EspSyslog
```
