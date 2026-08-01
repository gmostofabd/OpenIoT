/*****************************************************************
    OpenIoT Framework

    File        : GitHubOTA.cpp
    Description : GitHub OTA Engine

*****************************************************************/
#include "GitHubOTA.h"

#include "ConfigManager.h"
#include "VersionManager.h"
#include "LoggerManager.h"

#include <ArduinoJson.h>


using namespace OIF;


GitHubOTA GitHubUpdate;


GitHubOTA::GitHubOTA()
{

    memset(
        _remoteVersion,
        0,
        sizeof(_remoteVersion)
    );


    memset(
        _firmwareURL,
        0,
        sizeof(_firmwareURL)
    );

}


bool GitHubOTA::begin()
{

    Log.info(
        "GITHUB OTA",
        "OTA engine ready"
    );


    return true;

}



bool GitHubOTA::checkVersion()
{

    String json;


    if(!downloadVersionFile(json))
    {

        Log.error(
            "GITHUB OTA",
            "Version download failed"
        );

        return false;

    }



    if(!parseVersion(json))
        return false;



    if(
        Version.isNewer(
            _remoteVersion
        )
    )
    {

        Log.info(
            "GITHUB OTA",
            "New firmware available"
        );


        return true;

    }



    Log.info(
        "GITHUB OTA",
        "Firmware is up to date"
    );


    return false;

}



bool GitHubOTA::update()
{

    return downloadFirmware();

}



const char*
GitHubOTA::remoteVersion() const
{
    return _remoteVersion;
}



bool GitHubOTA::downloadVersionFile(
    String &json
)
{

    const GitHubConfig &cfg =
        Config.github();


	String url = _firmwareURL;
    



#if defined(ESP32)

    HTTPClient http;


#elif defined(ESP8266)

    HTTPClient http;

#endif



    http.begin(url);



    int code =
        http.GET();



    if(code != 200)
    {

        http.end();

        return false;

    }



    json =
        http.getString();



    http.end();


    return true;

}



bool GitHubOTA::parseVersion(
    const String &json
)
{

    JsonDocument doc;


    DeserializationError error =
        deserializeJson(
            doc,
            json
        );


    if(error)
        return false;



    strncpy(
        _remoteVersion,
        doc["version"] | "0.0.0",
        sizeof(_remoteVersion)-1
    );



    strncpy(
        _firmwareURL,
        doc["firmware"] | "",
        sizeof(_firmwareURL)-1
    );



    return true;

}


bool GitHubOTA::downloadFirmware()
{
    const GitHubConfig &cfg =
        Config.github();


    String url = _firmwareURL;



    Log.info(
        "GITHUB OTA",
        "Downloading firmware"
    );


    Log.info(
        "GITHUB OTA",
        url.c_str()
    );


#if defined(ESP32)

    HTTPClient http;


    http.begin(url);



    int httpCode =         http.GET();
	Serial.printf("HTTP Code: %d\n", httpCode);



    if(httpCode != HTTP_CODE_OK)
    {
        http.end();

        Log.error(
            "GITHUB OTA",
            "Download failed"
        );

        return false;
    }



    int length =
        http.getSize();

Serial.printf("Content Length: %d\n", length);

if (length <= 0) {
    Log.error("GITHUB OTA", "Invalid firmware size");
    http.end();
    return false;
}



    if(!Update.begin(length))
    {
        http.end();

        Log.error(
            "GITHUB OTA",
            "Not enough space"
        );

        return false;
    }



    WiFiClient *stream =
        http.getStreamPtr();



    size_t written =
        Update.writeStream(
            *stream
        );



    if(written != length)
    {
        Log.error(
            "GITHUB OTA",
            "Write incomplete"
        );

        Update.abort();

        http.end();

        return false;
    }



   if (Update.end(true)) {
    Serial.println("OTA Success");
    ESP.restart();
} else {
    Serial.printf("OTA Error: %s\n", Update.errorString());
}


    if(Update.isFinished())
    {

        Log.info(
            "GITHUB OTA",
            "Update successful"
        );


        http.end();


        delay(1000);


        ESP.restart();


    }



    http.end();



    return true;



#elif defined(ESP8266)



    t_httpUpdate_return result =
        ESPhttpUpdate.update(
            url
        );



    switch(result)
    {

        case HTTP_UPDATE_OK:

            Log.info(
                "GITHUB OTA",
                "Update successful"
            );

            return true;


        case HTTP_UPDATE_FAILED:

            Log.error(
                "GITHUB OTA",
                "Update failed"
            );

            return false;


        case HTTP_UPDATE_NO_UPDATES:

            Log.warning(
                "GITHUB OTA",
                "No update"
            );

            return false;


    }


#endif


    return false;
}