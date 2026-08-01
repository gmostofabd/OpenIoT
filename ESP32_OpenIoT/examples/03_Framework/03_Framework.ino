/*
=========================================================
    Logger Example
=========================================================
*/

#include <OpenIoT.h>

void setup()
{
    Serial.begin(115200);

    OIF::Framework.begin();

    OIF::Log.info(
        "SYSTEM",
        "Framework Started"
    );

    OIF::Log.warning(
        "MEMORY",
        "Heap Low"
    );

    OIF::Log.error(
        "NETWORK",
        "Connection Failed"
    );
}

void loop()
{
    OIF::Framework.run();
}