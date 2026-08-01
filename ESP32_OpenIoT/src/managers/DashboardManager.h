#pragma once

/*****************************************************************
    OpenIoT Framework

    File        : DashboardManager.h
    Description : Web Dashboard Manager

    Version     : 1.0.0

    License     : MIT
*****************************************************************/

#include "../../Platform.h"


namespace OIF
{


class DashboardManager
{

public:

    DashboardManager();


    bool begin();


    String html();


private:

    String buildDashboard();

};


}


extern OIF::DashboardManager Dashboard;