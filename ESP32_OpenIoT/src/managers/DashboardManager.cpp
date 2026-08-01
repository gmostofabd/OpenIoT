/*****************************************************************
    OpenIoT Framework

    File        : DashboardManager.cpp
    Description : Dashboard Generator

    Version     : 1.0.0

    License     : MIT
*****************************************************************/


#include "DashboardManager.h"

#include "ConfigManager.h"
#include "VersionManager.h"


using namespace OIF;


DashboardManager Dashboard;



DashboardManager::DashboardManager()
{
}


bool DashboardManager::begin()
{
    return true;
}



String DashboardManager::html()
{
    return buildDashboard();
}



String DashboardManager::buildDashboard()
{

    String page;


    page.reserve(2500);



    page += F(
        "<!DOCTYPE html>"
        "<html>"
        "<head>"
        "<meta name='viewport' "
        "content='width=device-width,initial-scale=1'>"
        "<title>OpenIoT Dashboard</title>"
    );



    page += F(
        "<style>"
        "body{"
        "font-family:Arial;"
        "background:#111;"
        "color:white;"
        "text-align:center;"
        "}"
        ".card{"
        "background:#222;"
        "margin:15px;"
        "padding:20px;"
        "border-radius:10px;"
        "}"
        "</style>"
    );



    page += F(
        "</head>"
        "<body>"
    );



    page += F(
        "<h1>OpenIoT Framework</h1>"
    );



    page += F(
        "<div class='card'>"
        "<h2>Device</h2>"
    );



    page +=
        Config.device().name;



    page += F(
        "</div>"
    );



    page += F(
        "<div class='card'>"
        "<h2>Firmware</h2>"
    );


    page +=
        Version.current().version;


    page += F(
        "</div>"
    );



    page += F(
        "<div class='card'>"
        "<h2>API</h2>"
        "<p>"
        "/api/system</p>"
        "<p>"
        "/api/device</p>"
        "<p>"
        "/api/network</p>"
        "</div>"
    );



    page += F(
        "</body>"
        "</html>"
    );


    return page;

}