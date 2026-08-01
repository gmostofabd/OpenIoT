/*
=========================================================
    OpenIoT Framework

    Example : 01_Blink
    Board   : ESP32
=========================================================
*/

#include <OpenIoT.h>

#define LED_PIN 2

void setup()
{
    Serial.begin(115200);

    pinMode(LED_PIN, OUTPUT);

    OIF::Framework.begin();
}

void loop()
{
    digitalWrite(LED_PIN, HIGH);
    delay(500);

    digitalWrite(LED_PIN, LOW);
    delay(500);

    OIF::Framework.run();
}