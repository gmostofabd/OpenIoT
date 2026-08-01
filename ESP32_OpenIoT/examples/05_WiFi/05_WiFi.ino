/*
=========================================================
    Embedded Web Server
=========================================================
*/

#include <OpenIoT.h>

void setup()
{
    Serial.begin(115200);

    OIF::Framework.begin();

    OIF::Web.begin(80);

    OIF::Web.on(
        "/",
        []()
        {
            OIF::Web.send(
                "Hello OpenIoT!"
            );
        }
    );
}

void loop()
{
    OIF::Framework.run();
}