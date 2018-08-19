#ifndef CTIMETRACKDATA_H
#define CTIMETRACKDATA_H

#include <memory>
#include "./../submodules/YAIP/src/YAIP++.h"

class CTimeTrackData
{
public:
    CTimeTrackData();

private:
    std::unique_ptr<net::derpaul::yaip::YAIP> timeTrackData;
};

#endif // CTIMETRACKDATA_H
