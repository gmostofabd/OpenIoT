/*
=========================================================
    Scheduler Example
=========================================================
*/

#include <OpenIoT.h>

void task()
{
    Serial.println("Task Running");
}

void setup()
{
    Serial.begin(115200);

    OIF::Framework.begin();

    OIF::Scheduler.every(
        1000,
        task
    );
}

void loop()
{
    OIF::Framework.run();
}