#pragma once

/*****************************************************************
    OpenIoT Framework

    File        : OTAManager.h
    Description : OTA Update Manager

    Version     : 2.0.0
    License     : MIT
*****************************************************************/

#include "../../Platform.h"

namespace OIF
{

class OTAManager
{
public:

    OTAManager();

    bool begin();

    void run();

    void stop();

    bool enabled() const;

private:

    bool _enabled;

};

extern OTAManager OTA;

}