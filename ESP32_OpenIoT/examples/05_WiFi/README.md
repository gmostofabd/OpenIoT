/*
=========================================================
    Serial Monitor Example
=========================================================
*/

#include <OpenIoT.h>

void setup()
{
    Serial.begin(115200);

    OIF::Framework.begin();

    Serial.println("OpenIoT Started");
}

void loop()
{
    Serial.println("Hello OpenIoT");

    delay(1000);

    OIF::Framework.run();
}