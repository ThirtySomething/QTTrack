#include "ctimetrack.h"

CTimeTrack::CTimeTrack()
{
    configFile = std::make_unique<CTimeTrackConfig>();
}

CTimeTrack::~CTimeTrack()
{

}

void CTimeTrack::TimeTrackInit()
{
    configFile->ConfigInit();
}
