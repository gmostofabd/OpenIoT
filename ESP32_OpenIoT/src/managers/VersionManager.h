#pragma once

/*****************************************************************
    OpenIoT Framework

    File        : VersionManager.h
    Description : Firmware Version Management

    Version     : 1.0.0

    License     : MIT
*****************************************************************/

#include "../../Platform.h"

namespace OIF
{

struct FirmwareInfo
{
    char name[32];
    char version[16];
    char buildDate[16];
    char buildTime[16];
    char channel[16];
    char firmwareURL[128];
};


class VersionManager
{
public:

    VersionManager();


    bool begin();


    const FirmwareInfo& current();


    bool isNewer(
        const char* remoteVersion
    );


    void setRemoteVersion(
        const char* version
    );


private:

    FirmwareInfo _current;

    char _remoteVersion[16];


    int compareVersion(
        const char* v1,
        const char* v2
    );

};


} // namespace OIF


extern OIF::VersionManager Version;