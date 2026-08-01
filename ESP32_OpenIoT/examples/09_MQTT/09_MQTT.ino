/*
=========================================================
    REST API Example
=========================================================
*/

#include <OpenIoT.h>

void setup()
{
    Serial.begin(115200);

    OIF::Framework.begin();

    OIF::REST.begin();
}

void loop()
{
    OIF::Framework.run();
}