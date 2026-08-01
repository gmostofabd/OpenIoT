#pragma once

/*****************************************************************
    OpenIoT Framework

    Platform Detection Layer

    Author : Md. Golam Mostofa
*****************************************************************/

#include <Arduino.h>

#if defined(ESP32)

    #include <WiFi.h>
    #include <WebServer.h>
    #include <HTTPClient.h>
    #include <Update.h>
    #include <LittleFS.h>

    #define OIF_PLATFORM_NAME "ESP32"

#elif defined(ESP8266)

    #include <ESP8266WiFi.h>
    #include <ESP8266WebServer.h>
    #include <ESP8266HTTPClient.h>
    #include <ESP8266httpUpdate.h>
    #include <LittleFS.h>

    #define OIF_PLATFORM_NAME "ESP8266"

#else

    #error OpenIoT currently supports ESP32 and ESP8266 only.

#endif