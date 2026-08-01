#pragma once

/*****************************************************************
    OpenIoT Framework

    File        : LoggerManager.h
    Description : Logging Manager

    Version     : 1.0.0
    License     : MIT
*****************************************************************/

#ifndef LOGGER_MANAGER_H
#define LOGGER_MANAGER_H

#include "../../Platform.h"

namespace OIF
{

//======================================================
// Log Levels
//======================================================

enum class LogLevel : uint8_t
{
    None = 0,
    Error,
    Warning,
    Info,
    Debug
};

//======================================================
// Logger Manager
//======================================================

class LoggerManager
{
public:

    LoggerManager();

    bool begin();

    void setLevel(LogLevel level);

    LogLevel level() const;

    void error(const char *module,
               const char *message);

    void warning(const char *module,
                 const char *message);

    void info(const char *module,
              const char *message);

    void debug(const char *module,
               const char *message);

    void success(const char *module,
                 const char *message);

    void printf(LogLevel level,
                const char *module,
                const char *format,
                ...);

private:

    LogLevel _level;

    void printPrefix(LogLevel level,
                     const char *module);
};

//======================================================
// Global Object
//======================================================

extern LoggerManager Log;

}

#endif