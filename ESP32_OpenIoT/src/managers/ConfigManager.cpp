/*****************************************************************
    OpenIoT Framework

    File        : ConfigManager.cpp
    Description : Configuration Implementation

    Version     : 1.0.0

    License     : MIT
*****************************************************************/

#include "ConfigManager.h"

#include <string.h>


using namespace OIF;


ConfigManager Config;



ConfigManager::ConfigManager()
{
}



bool ConfigManager::begin()
{
    loadDefaults();

    return true;
}



void ConfigManager::loadDefaults()
{

    /*
        Device Configuration
    */

    strncpy(
        _device.name,
        "OpenIoT Device",
        sizeof(_device.name)
    );


    strncpy(
        _device.version,
        "1.0.0",
        sizeof(_device.version)
    );


    /*
        Network Configuration
    */

    strncpy(
        _network.ssid,
        "YOUR_WIFI",
        sizeof(_network.ssid)
    );


    strncpy(
        _network.password,
        "YOUR_PASSWORD",
        sizeof(_network.password)
    );


    strncpy(
        _network.hostname,
        "openiot-device",
        sizeof(_network.hostname)
    );



    /*
        Web Configuration
    */

    _web.port = 80;



    /*
        GitHub OTA Configuration
    */

    strncpy(
        _github.owner,
        "gmostofabd",
        sizeof(_github.owner)
    );


    strncpy(
        _github.repository,
        "OpenIoT-Framework",
        sizeof(_github.repository)
    );


    strncpy(
        _github.branch,
        "main",
        sizeof(_github.branch)
    );


    strncpy(
        _github.channel,
        "stable",
        sizeof(_github.channel)
    );

}



void ConfigManager::reset()
{
    loadDefaults();
}



const DeviceConfig&
ConfigManager::device() const
{
    return _device;
}



const NetworkConfig&
ConfigManager::network() const
{
    return _network;
}



const WebConfig&
ConfigManager::web() const
{
    return _web;
}



const GitHubConfig&
ConfigManager::github() const
{
    return _github;
}