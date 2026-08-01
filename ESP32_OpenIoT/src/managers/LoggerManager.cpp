/*****************************************************************
    OpenIoT Framework

    File        : LoggerManager.cpp
    Description : Logging Manager

    Version     : 1.0.0
    License     : MIT

    Developed By:
    Md. Golam Mostofa
*****************************************************************/

#include "LoggerManager.h"
#include <stdarg.h>

namespace OIF
{

//======================================================
// Global Logger Instance
//======================================================

LoggerManager Log;

//======================================================
// Constructor
//======================================================

LoggerManager::LoggerManager()
{
    _level = LogLevel::Info;
}

//======================================================
// Initialize Logger
//======================================================

bool LoggerManager::begin()
{
    info("LOGGER", "Logger Initialized");
    return true;
}

//======================================================
// Set Log Level
//======================================================

void LoggerManager::setLevel(LogLevel level)
{
    _level = level;
}

//======================================================
// Get Current Log Level
//======================================================

LogLevel LoggerManager::level() const
{
    return _level;
}

//======================================================
// Print Prefix
//======================================================

void LoggerManager::printPrefix(LogLevel level,
                                const char *module)
{
    switch (level)
    {
        case LogLevel::Error:
            Serial.print("[ERROR]");
            break;

        case LogLevel::Warning:
            Serial.print("[WARN ]");
            break;

        case LogLevel::Info:
            Serial.print("[INFO ]");
            break;

        case LogLevel::Debug:
            Serial.print("[DEBUG]");
            break;

        default:
            Serial.print("[LOG  ]");
            break;
    }

    Serial.print('[');
    Serial.print(module);
    Serial.print("] ");
}

//======================================================
// Error
//======================================================

void LoggerManager::error(const char *module,
                          const char *message)
{
    if (_level < LogLevel::Error)
        return;

    printPrefix(LogLevel::Error, module);
    Serial.println(message);
}

//======================================================
// Warning
//======================================================

void LoggerManager::warning(const char *module,
                            const char *message)
{
    if (_level < LogLevel::Warning)
        return;

    printPrefix(LogLevel::Warning, module);
    Serial.println(message);
}

//======================================================
// Info
//======================================================

void LoggerManager::info(const char *module,
                         const char *message)
{
    if (_level < LogLevel::Info)
        return;

    printPrefix(LogLevel::Info, module);
    Serial.println(message);
}

//======================================================
// Success
//======================================================

void LoggerManager::success(const char *module,
                            const char *message)
{
    if (_level < LogLevel::Info)
        return;

    Serial.print("[ OK  ]");
    Serial.print('[');
    Serial.print(module);
    Serial.print("] ");
    Serial.println(message);
}

//======================================================
// Debug
//======================================================

void LoggerManager::debug(const char *module,
                          const char *message)
{
    if (_level < LogLevel::Debug)
        return;

    printPrefix(LogLevel::Debug, module);
    Serial.println(message);
}

//======================================================
// Formatted Print
//======================================================

void LoggerManager::printf(LogLevel level,
                           const char *module,
                           const char *format,
                           ...)
{
    if (_level < level)
        return;

    char buffer[256];

    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    printPrefix(level, module);
    Serial.println(buffer);
}

} // namespace OIF