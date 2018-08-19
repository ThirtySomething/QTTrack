#include "ctimetrackconfig.h"

const std::string CTimeTrackConfig::nameConfigFile = "QTTrack.ini";
const std::string CTimeTrackConfig::nameSectionTimeTrack = CTimeTrackConfig::nameConfigFile;
const std::string CTimeTrackConfig::nameKeyDataFile = "DataFile";
const std::string CTimeTrackConfig::defaultKeyDataFile = "TimeTrackerData.ini";


CTimeTrackConfig::CTimeTrackConfig()
{
    timeTrackConfig = std::make_unique<net::derpaul::yaip::YAIP>();
}

CTimeTrackConfig::~CTimeTrackConfig()
{
}

void CTimeTrackConfig::ConfigInit()
{
    if (false == timeTrackConfig->INIFileLoad(nameConfigFile))
    {
        timeTrackConfig->SectionKeyValueSet(nameSectionTimeTrack, nameKeyDataFile, defaultKeyDataFile);
        timeTrackConfig->INIFileSave(nameConfigFile);
    }
}
