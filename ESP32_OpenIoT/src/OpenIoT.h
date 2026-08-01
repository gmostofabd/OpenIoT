#pragma once

/*****************************************************************
    OpenIoT Framework
*****************************************************************/

#include "../Platform.h"

namespace OIF
{

class OpenIoT
{
public:

    OpenIoT();

    bool begin();

    void run();

    void stop();

private:

    bool _initialized;
};

extern OpenIoT Framework;

} // namespace OIF