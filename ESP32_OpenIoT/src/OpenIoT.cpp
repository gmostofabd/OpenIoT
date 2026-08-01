#include "OpenIoT.h"

namespace OIF
{

OpenIoT Framework;

OpenIoT::OpenIoT()
{
    _initialized = false;
}

bool OpenIoT::begin()
{
    if (_initialized)
        return true;

    Serial.println("[Framework] Initializing...");

    _initialized = true;

    Serial.println("[Framework] Ready");

    return true;
}

void OpenIoT::run()
{
    if (!_initialized)
        return;

    // Future managers:
    // Logger.run();
    // WiFi.run();
    // OTA.run();
    // Web.run();
    // MQTT.run();
}

void OpenIoT::stop()
{
    _initialized = false;
    Serial.println("[Framework] Stopped");
}

} // namespace OIF