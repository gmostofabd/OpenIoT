/*****************************************************************
    OpenIoT Framework

    File        : JSONManager.cpp
    Description : JSON Implementation

    Version     : 1.0.0

    License     : MIT
*****************************************************************/

#include "JSONManager.h"

#include "ConfigManager.h"
#include "VersionManager.h"
#include "ConnectivityManager.h"


namespace OIF
{


JSONManager JSON;


/*********************************************************
    Constructor
*********************************************************/

JSONManager::JSONManager()
{
}


/*********************************************************
    Begin
*********************************************************/

bool JSONManager::begin()
{
    return true;
}


/*********************************************************
    System JSON
*********************************************************/

String JSONManager::systemJSON()
{

    JsonDocument doc;


    addSystemData(doc);


    String output;


    serializeJson(
        doc,
        output
    );


    return output;

}


/*********************************************************
    Device JSON
*********************************************************/

String JSONManager::deviceJSON()
{

    JsonDocument doc;


    addDeviceData(doc);


    String output;


    serializeJson(
        doc,
        output
    );


    return output;

}


/*********************************************************
    Network JSON
*********************************************************/

String JSONManager::networkJSON()
{

    JsonDocument doc;


    addNetworkData(doc);


    String output;


    serializeJson(
        doc,
        output
    );


    return output;

}


/*********************************************************
    System Data
*********************************************************/

void JSONManager::addSystemData(
    JsonDocument& doc
)
{

    doc["framework"] =
        "OpenIoT";


    doc["version"] =
        Version.current().version;



#if defined(ESP32)

    doc["chip"] =
        "ESP32";


#elif defined(ESP8266)

    doc["chip"] =
        "ESP8266";

#endif


    doc["uptime"] =
        millis();

}


/*********************************************************
    Device Data
*********************************************************/

void JSONManager::addDeviceData(
    JsonDocument& doc
)
{

    const DeviceConfig& cfg =
        Config.device();


    doc["name"] =
        cfg.name;


    doc["firmware"] =
        cfg.version;

}


/*********************************************************
    Network Data
*********************************************************/

void JSONManager::addNetworkData(
    JsonDocument& doc
)
{

    doc["connected"] =
        Connectivity.connected();


    doc["ip"] =
        Connectivity.ipAddress();


    doc["rssi"] =
        Connectivity.signalStrength();

}


} // namespace OIF