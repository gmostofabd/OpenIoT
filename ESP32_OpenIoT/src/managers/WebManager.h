#pragma once

/*****************************************************************
    OpenIoT Framework

    File        : WebManager.h
    Description : Embedded Web Server Manager

    Version     : 1.0.0

    License     : MIT
*****************************************************************/

#include "../../Platform.h"


namespace OIF
{


class WebManager
{

public:

    WebManager();


    bool begin();


    void run();


    void stop();


private:

#if defined(ESP32)

    WebServer _server;

#elif defined(ESP8266)

    ESP8266WebServer _server;

#endif


    void registerRoutes();


    void handleRoot();


    void handleSystem();


    void handleDevice();


    void handleNetwork();

};


}


extern OIF::WebManager Web;