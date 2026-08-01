#pragma once

/*****************************************************************
    OpenIoT Framework

    File        : JSONManager.h
    Description : JSON Data Manager

    Version     : 1.0.0

    License     : MIT
*****************************************************************/

#include "../../Platform.h"

#include <ArduinoJson.h>


namespace OIF
{


class JSONManager
{

public:

    JSONManager();


    bool begin();


    String systemJSON();


    String deviceJSON();


    String networkJSON();



private:

    void addSystemData(
        JsonDocument& doc
    );


    void addDeviceData(
        JsonDocument& doc
    );


    void addNetworkData(
        JsonDocument& doc
    );


};



}


extern OIF::JSONManager JSON;