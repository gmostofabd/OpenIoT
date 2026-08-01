/*****************************************************************
    OpenIoT Framework

    File        : FileManager.cpp
    Description : LittleFS File Manager

    Version     : 1.0.0
    License     : MIT

    Developed By:
    Md. Golam Mostofa
*****************************************************************/

#include "FileManager.h"
#include "LoggerManager.h"

#if defined(ESP32)
#include <LittleFS.h>
#elif defined(ESP8266)
#include <LittleFS.h>
#endif

namespace OIF
{

//==========================================================
// Global Instance
//==========================================================

FileManager Storage;

//==========================================================
// Constructor
//==========================================================

FileManager::FileManager()
{
    _mounted = false;
}

//==========================================================
// Initialize LittleFS
//==========================================================

bool FileManager::begin()
{
    Log.info("FILE", "Initializing LittleFS");

#if defined(ESP32)

    _mounted = LittleFS.begin(true);

#elif defined(ESP8266)

    _mounted = LittleFS.begin();

#endif

    if (_mounted)
        Log.info("FILE", "LittleFS Mounted");
    else
        Log.error("FILE", "LittleFS Mount Failed");

    return _mounted;
}

//==========================================================
// Check File Exists
//==========================================================

bool FileManager::exists(const char *path)
{
    if (!_mounted)
        return false;

    return LittleFS.exists(path);
}

//==========================================================
// Read File
//==========================================================

String FileManager::read(const char *path)
{
    if (!_mounted)
        return "";

    File file = LittleFS.open(path, "r");

    if (!file)
        return "";

    String data = file.readString();

    file.close();

    return data;
}

//==========================================================
// Write File
//==========================================================

bool FileManager::write(const char *path, const String &data)
{
    if (!_mounted)
        return false;

    File file = LittleFS.open(path, "w");

    if (!file)
        return false;

    file.print(data);

    file.close();

    return true;
}

//==========================================================
// Delete File
//==========================================================

bool FileManager::removeFile(const char *path)
{
    if (!_mounted)
        return false;

    return LittleFS.remove(path);
}

//==========================================================
// Total Filesystem Size
//==========================================================

uint32_t FileManager::totalSpace()
{
    if (!_mounted)
        return 0;

#if defined(ESP32)

    return LittleFS.totalBytes();

#elif defined(ESP8266)

    FSInfo info;
    LittleFS.info(info);
    return info.totalBytes;

#endif

    return 0;
}

//==========================================================
// Used Filesystem Size
//==========================================================

uint32_t FileManager::usedSpace()
{
    if (!_mounted)
        return 0;

#if defined(ESP32)

    return LittleFS.usedBytes();

#elif defined(ESP8266)

    FSInfo info;
    LittleFS.info(info);
    return info.usedBytes;

#endif

    return 0;
}

} // namespace OIF