/*****************************************************************
    OpenIoT Framework

    File        : OTAManager.cpp
    Description : OTA Update Manager

    Version     : 2.0.0
    License     : MIT
*****************************************************************/

#include "OTAManager.h"
#include "LoggerManager.h"

#if defined(ESP32) || defined(ESP8266)
#include <ArduinoOTA.h>
#endif

namespace OIF
{

OTAManager OTA;

OTAManager::OTAManager()
{
    _enabled = false;
}

bool OTAManager::begin()
{

#if defined(ESP32) || defined(ESP8266)

    ArduinoOTA.setHostname("OpenIoT");

    ArduinoOTA.onStart([]()
    {
        Log.info(
            "OTA",
            "Update started"
        );
    });

    ArduinoOTA.onEnd([]()
    {
        Log.info(
            "OTA",
            "Update completed"
        );
    });

    ArduinoOTA.onProgress(
        [](unsigned int progress, unsigned int total)
        {
            uint8_t percent =
                (progress * 100) / total;

            Serial.printf(
                "OTA %u%%\n",
                percent
            );
        });

    ArduinoOTA.onError(
        [](ota_error_t error)
        {
            Serial.printf(
                "OTA Error %u\n",
                error
            );
        });

    ArduinoOTA.begin();

    _enabled = true;

    Log.info(
        "OTA",
        "Arduino OTA Ready"
    );

#endif

    return _enabled;
}

void OTAManager::run()
{

#if defined(ESP32) || defined(ESP8266)

    if(_enabled)
    {
        ArduinoOTA.handle();
    }

#endif

}

void OTAManager::stop()
{
    _enabled = false;
}

bool OTAManager::enabled() const
{
    return _enabled;
}

}