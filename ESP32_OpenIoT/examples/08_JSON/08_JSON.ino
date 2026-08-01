/*
=========================================================
    MQTT Publish
=========================================================
*/

#include <OpenIoT.h>

void setup()
{
    Serial.begin(115200);

    OIF::Framework.begin();

    OIF::MQTT.begin(
        "broker.hivemq.com",
        1883
    );
}

void loop()
{
    OIF::MQTT.publish(
        "openiot/status",
        "Framework Running"
    );

    delay(5000);

    OIF::Framework.run();
}