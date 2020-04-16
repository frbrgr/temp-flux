#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "Adafruit_SHT31.h"
#include "InfluxDbClient.h"

#include "tf-config.hpp"

Adafruit_SHT31 sensor;
InfluxDBClient flux{INFLUX_SERVER, INFLUX_DB};
Point p{"temps"};

void setup()
{
    sensor.begin(0x44);
    Serial.begin(9600);
    Serial.println();
    Serial.print("Connecting");

    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("Connected, IP address: ");
    Serial.println(WiFi.localIP());

    p.addTag("ort", "test");
}

void loop()
{
    p.clearFields();
    p.addField("temp", sensor.readTemperature(), 2);
    p.addField("humi", sensor.readHumidity(), 2);
    flux.writePoint(p);

    Serial.println(p.toLineProtocol());
    delay(LOOP_DELAY);
}
