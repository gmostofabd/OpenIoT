#ifndef CONNECTIVITY_MANAGER_H
#define CONNECTIVITY_MANAGER_H

#include "../../Platform.h"

namespace OIF
{

class ConnectivityManager
{
public:
    ConnectivityManager();

    bool begin();

    void run();

    void connect();

    void disconnect();

    bool connected() const;

    String ipAddress() const;

    int signalStrength() const;

private:
    unsigned long _lastReconnect;
};

// Global instance declaration
extern ConnectivityManager Connectivity;

} // namespace OIF

#endif