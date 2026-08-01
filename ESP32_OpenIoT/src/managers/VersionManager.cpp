/*****************************************************************
    OpenIoT Framework

    File        : VersionManager.cpp
    Description : Firmware Version Implementation

    Version     : 1.0.0

    License     : MIT
*****************************************************************/

#include "VersionManager.h"

#include <string.h>
#include <stdlib.h>


using namespace OIF;


VersionManager Version;



VersionManager::VersionManager()
{
    memset(&_current, 0, sizeof(_current));

    memset(
        _remoteVersion,
        0,
        sizeof(_remoteVersion)
    );
}



bool VersionManager::begin()
{

    strncpy(
        _current.name,
        "OpenIoT Firmware",
        sizeof(_current.name)
    );


    strncpy(
        _current.version,
        "1.0.0",
        sizeof(_current.version)
    );


    strncpy(
        _current.channel,
        "stable",
        sizeof(_current.channel)
    );


    strncpy(
        _current.buildDate,
        __DATE__,
        sizeof(_current.buildDate)
    );


    strncpy(
        _current.buildTime,
        __TIME__,
        sizeof(_current.buildTime)
    );


    return true;
}



const FirmwareInfo&
VersionManager::current()
{
    return _current;
}



void VersionManager::setRemoteVersion(
    const char* version
)
{
    strncpy(
        _remoteVersion,
        version,
        sizeof(_remoteVersion)-1
    );
}



bool VersionManager::isNewer(
    const char* remoteVersion
)
{

    return compareVersion(
        remoteVersion,
        _current.version
    ) > 0;

}



int VersionManager::compareVersion(
    const char* v1,
    const char* v2
)
{

    int major1 = 0;
    int minor1 = 0;
    int patch1 = 0;


    int major2 = 0;
    int minor2 = 0;
    int patch2 = 0;


    sscanf(
        v1,
        "%d.%d.%d",
        &major1,
        &minor1,
        &patch1
    );


    sscanf(
        v2,
        "%d.%d.%d",
        &major2,
        &minor2,
        &patch2
    );


    if(major1 != major2)
        return major1 - major2;


    if(minor1 != minor2)
        return minor1 - minor2;


    return patch1 - patch2;
}