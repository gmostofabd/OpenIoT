/*
=========================================================
    WiFi Example
=========================================================
*/

#include <OpenIoT.h>

const char* ssid="YOUR_WIFI";
const char* password="YOUR_PASSWORD";

void setup()
{
    Serial.begin(115200);

    OIF::Framework.begin();

    OIF::WiFi.begin(
        ssid,
        password
    );
}

void loop()
{
    OIF::Framework.run();
}