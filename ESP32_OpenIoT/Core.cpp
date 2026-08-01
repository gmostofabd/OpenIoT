/*****************************************************************
    OpenIoT Framework (OIF)

    File        : Core.cpp
    Description : Framework Core

    Author      : Md. Golam Mostofa
    License     : MIT
*****************************************************************/

#include "Core.h"

//--------------------------------------------------
// Print Framework Banner
//--------------------------------------------------
void OIF_printBanner()
{
    Serial.println();
    Serial.println(F("=========================================="));
    Serial.println(F("        OpenIoT Framework (OIF)"));
    Serial.print(F("Version : "));
    Serial.println(OIF_VERSION);
    Serial.print(F("Author  : "));
    Serial.println(OIF_AUTHOR);
    Serial.println(F("=========================================="));
    Serial.println();
}

//--------------------------------------------------
// Initialize All Modules
//--------------------------------------------------
void OIF_initializeModules()
{
    Serial.println(F("[CORE] Initializing modules..."));

    // Future initialization sequence
    // OIF_Config_begin();
    // OIF_Logger_begin();
    // OIF_File_begin();
    // OIF_WiFi_begin();
    // OIF_Web_begin();
    // OIF_JSON_begin();
    // OIF_OTA_begin();

    Serial.println(F("[CORE] Initialization complete."));
}

//--------------------------------------------------
// Framework Begin
//--------------------------------------------------
void OIF_begin()
{
    Serial.begin(115200);

    while (!Serial)
    {
        delay(10);
    }

    OIF_printBanner();

    OIF_initializeModules();
}

//--------------------------------------------------
// Framework Loop
//--------------------------------------------------
void OIF_run()
{
    // Future module execution
    // OIF_Logger_run();
    // OIF_WiFi_run();
    // OIF_Web_run();
    // OIF_OTA_run();
}

//--------------------------------------------------
// Framework Stop
//--------------------------------------------------
void OIF_stop()
{
    Serial.println(F("[CORE] Framework stopped."));
}