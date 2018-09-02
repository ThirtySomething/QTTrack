#ifndef CTIMETRACKCONFIG_H
#define CTIMETRACKCONFIG_H

#include <memory>
#include "./../../submodules/YAIP/src/YAIP++.h"

class CTimeTrackConfig
{
public:
    CTimeTrackConfig();

    void ConfigInit();

    virtual ~CTimeTrackConfig();

private:
    std::unique_ptr<net::derpaul::yaip::YAIP> timeTrackConfig;

    static const std::string nameConfigFile;

    static const std::string nameSectionTimeTrack;

    static const std::string nameKeyDataFile;

    static const std::string defaultKeyDataFile;
};

#endif // CTIMETRACKCONFIG_H
