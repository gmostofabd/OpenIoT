/*
=========================================================
    OTA Example
=========================================================
*/

#include <OpenIoT.h>

void setup()
{
    Serial.begin(115200);

    OIF::Framework.begin();

    OIF::OTA.begin();
}

void loop()
{
    OIF::Framework.run();
}