/*****************************************************************
    OpenIoT Framework (OIF)

    File        : Core.h
    Description : Framework Core Header

    Author      : Md. Golam Mostofa
    License     : MIT
*****************************************************************/

#ifndef OIF_CORE_H
#define OIF_CORE_H

#include <Arduino.h>

//--------------------------------------------------
// Framework Information
//--------------------------------------------------
#define OIF_NAME        "OpenIoT Framework"
#define OIF_VERSION     "1.0.0-alpha"
#define OIF_AUTHOR      "Md. Golam Mostofa"

//--------------------------------------------------
// Core API
//--------------------------------------------------
void OIF_begin();
void OIF_run();
void OIF_stop();

//--------------------------------------------------
// Internal Functions
//--------------------------------------------------
void OIF_printBanner();
void OIF_initializeModules();

#endif