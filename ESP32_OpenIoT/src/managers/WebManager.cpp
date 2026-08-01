/*****************************************************************
    OpenIoT Framework

    File        : WebManager.cpp
    Description : Embedded Web Server Manager

    Version     : 1.0.0

    License     : MIT
*****************************************************************/

#include "WebManager.h"

#include "DashboardManager.h"
#include "JSONManager.h"
#include "LoggerManager.h"

namespace OIF
{

WebManager Web;


/*********************************************************
    Constructor
*********************************************************/

WebManager::WebManager()

#if defined(ESP32)

    : _server(80)

#elif defined(ESP8266)

    : _server(80)

#endif

{
}


/*********************************************************
    Initialize
*********************************************************/

bool WebManager::begin()
{
    Log.info(
        "WEB",
        "Starting Web Server"
    );

    registerRoutes();

    _server.begin();

    Log.info(
        "WEB",
        "Web Server Started"
    );

    return true;
}


/*********************************************************
    Main Loop
*********************************************************/

void WebManager::run()
{
    _server.handleClient();
}


/*********************************************************
    Stop Server
*********************************************************/

void WebManager::stop()
{
    _server.stop();
}


/*********************************************************
    Register Web Routes
*********************************************************/

void WebManager::registerRoutes()
{

    _server.on(
        "/",
        [this]()
        {
            handleRoot();
        }
    );

    _server.on(
        "/api/system",
        [this]()
        {
            handleSystem();
        }
    );

    _server.on(
        "/api/device",
        [this]()
        {
            handleDevice();
        }
    );

    _server.on(
        "/api/network",
        [this]()
        {
            handleNetwork();
        }
    );

}


/*********************************************************
    Root Page
*********************************************************/

void WebManager::handleRoot()
{
    _server.send(
        200,
        "text/html",
        Dashboard.html()
    );
}


/*********************************************************
    System JSON
*********************************************************/

void WebManager::handleSystem()
{
    _server.send(
        200,
        "application/json",
        JSON.systemJSON()
    );
}


/*********************************************************
    Device JSON
*********************************************************/

void WebManager::handleDevice()
{
    _server.send(
        200,
        "application/json",
        JSON.deviceJSON()
    );
}


/*********************************************************
    Network JSON
*********************************************************/

void WebManager::handleNetwork()
{
    _server.send(
        200,
        "application/json",
        JSON.networkJSON()
    );
}

} // namespace OIF