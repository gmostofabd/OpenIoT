/*
=========================================================
    Framework Initialization
=========================================================
*/

#include <OpenIoT.h>

void setup()
{
    Serial.begin(115200);

    if(OIF::Framework.begin())
    {
        Serial.println("Framework Ready");
    }
}

void loop()
{
    OIF::Framework.run();
}