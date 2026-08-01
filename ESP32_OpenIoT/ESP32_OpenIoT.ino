#include "src/OpenIoT.h"


void setup()
{
    Serial.begin(115200);
    delay(1000);

    OIF::Framework.begin();
}

void loop()
{
    OIF::Framework.run();
}
