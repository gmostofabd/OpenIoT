/*****************************************************************
    OpenIoT Framework

    File : ConnectivityManager.cpp
*****************************************************************/


#include "ConnectivityManager.h"

#include "LoggerManager.h"

#include <WiFi.h>


namespace OIF
{


ConnectivityManager Connectivity;


/*********************************************************
    Constructor
*********************************************************/

ConnectivityManager::ConnectivityManager()
{
    _lastReconnect = 0;
}


/*********************************************************
    Begin WiFi
*********************************************************/

bool ConnectivityManager::begin()
{

    Log.info(
        "Connectivity",
        "Starting WiFi"
    );


    WiFi.mode(
        WIFI_STA
    );


    connect();


    return connected();

}


/*********************************************************
    Connect
*********************************************************/

void ConnectivityManager::connect()
{

    /*
       Replace with your config manager
       values later
    */


    WiFi.begin();


}


/*********************************************************
    Loop Service
*********************************************************/

void ConnectivityManager::run()
{

    if(!connected())
    {

        if(
            millis() - _lastReconnect > 10000
        )
        {

            _lastReconnect =
                millis();


            connect();

        }

    }

}


/*********************************************************
    Status
*********************************************************/

bool ConnectivityManager::connected() const
{

    return (
        WiFi.status()
        ==
        WL_CONNECTED
    );

}


/*********************************************************
    IP Address
*********************************************************/

String ConnectivityManager::ipAddress() const
{

    if(!connected())
        return "0.0.0.0";


    return WiFi.localIP().toString();

}


/*********************************************************
    Signal
*********************************************************/

int ConnectivityManager::signalStrength() const
{

    if(!connected())
        return 0;


    return WiFi.RSSI();

}


/*********************************************************
    Disconnect
*********************************************************/

void ConnectivityManager::disconnect()
{

    WiFi.disconnect();

}


} // namespace OIF