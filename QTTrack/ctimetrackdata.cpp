#include "ctimetrackdata.h"

CTimeTrackData::CTimeTrackData()
{
    timeTrackData = std::make_unique<net::derpaul::yaip::YAIP>();
}
