/*
=========================================================
    Smart IoT Device
=========================================================
*/

#include <OpenIoT.h>

const char* ssid="YOUR_WIFI";
const char* pass="YOUR_PASSWORD";

void setup()
{
    Serial.begin(115200);

    OIF::Framework.begin();

    OIF::WiFi.begin(
        ssid,
        pass
    );

    OIF::OTA.begin();

    OIF::Web.begin(80);

    OIF::MQTT.begin(
        "broker.hivemq.com",
        1883
    );

    OIF::Log.info(
        "SYSTEM",
        "Device Ready"
    );
}

void loop()
{
    OIF::Framework.run();
}