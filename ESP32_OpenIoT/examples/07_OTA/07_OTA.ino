/*
=========================================================
    JSON Example
=========================================================
*/

#include <OpenIoT.h>

void setup()
{
    Serial.begin(115200);

    OIF::Framework.begin();

    DynamicJsonDocument doc(256);

    doc["device"]="ESP32";
    doc["framework"]="OpenIoT";
    doc["version"]="1.0.0";

    serializeJsonPretty(
        doc,
        Serial
    );
}

void loop()
{
    OIF::Framework.run();
}