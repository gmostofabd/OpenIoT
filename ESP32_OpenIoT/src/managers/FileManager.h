#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "../../Platform.h"

namespace OIF
{

class FileManager
{
public:
    FileManager();

    bool begin();
    bool exists(const char *path);
    String read(const char *path);
    bool write(const char *path, const String &data);
    bool removeFile(const char *path);
    uint32_t totalSpace();
    uint32_t usedSpace();

private:
    bool _mounted;
};

extern FileManager Storage;

}

#endif