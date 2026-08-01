#pragma once

/*****************************************************************
    OpenIoT Framework

    File        : GitHubOTA.h
    Description : GitHub Firmware Update Engine

    Version     : 1.0.0
*****************************************************************/

#include "../../Platform.h"


namespace OIF
{


class GitHubOTA
{

public:

    GitHubOTA();


    bool begin();


    bool checkVersion();


    bool update();


    const char* remoteVersion() const;



private:

    char _remoteVersion[16];

    char _firmwareURL[160];


    bool downloadVersionFile(
        String &json
    );


    bool parseVersion(
        const String &json
    );


    bool downloadFirmware();


};



}


extern OIF::GitHubOTA GitHubUpdate;