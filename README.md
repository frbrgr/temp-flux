# temp-flux
measures temerature and humidity and writes it to a remote InfluxDB database. It uses the ESP8266 core for Arduino via PlatformIO.

## Configuration
is done in `include/tf-config.hpp`. Enter your Wifi parameters and your InfluxDB server's IP address and database name. Adjust the `INTERVAL` macro value to your desired measurement interval in seconds.

## Hardware
consists of an ESP8266 module and a SHT31 sensor module connected with I2C
