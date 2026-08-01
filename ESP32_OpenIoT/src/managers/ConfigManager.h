#pragma once

/*****************************************************************
    OpenIoT Framework

    File        : ConfigManager.h
    Description : Central Configuration Manager

    Version     : 1.0.0

    License     : MIT
*****************************************************************/

#include "../../Platform.h"

namespace OIF
{

struct NetworkConfig
{
    char ssid[32];
    char password[64];
    char hostname[32];
};


struct WebConfig
{
    uint16_t port;
};


struct GitHubConfig
{
    char owner[64];
    char repository[64];
    char branch[32];
    char channel[16];
};


struct DeviceConfig
{
    char name[32];
    char version[16];
};


class ConfigManager
{
public:

    ConfigManager();

    bool begin();

    void reset();

    const DeviceConfig& device() const;

    const NetworkConfig& network() const;

    const WebConfig& web() const;

    const GitHubConfig& github() const;


private:

    DeviceConfig _device;

    NetworkConfig _network;

    WebConfig _web;

    GitHubConfig _github;


    void loadDefaults();

};


} // namespace OIF


extern OIF::ConfigManager Config;