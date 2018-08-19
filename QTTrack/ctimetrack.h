#ifndef CTIMETRACK_H
#define CTIMETRACK_H

#include <memory>
#include "ctimetrackconfig.h"

class CTimeTrack
{
public:
    CTimeTrack();

    virtual ~CTimeTrack();

    void TimeTrackInit();

private:
    std::unique_ptr<CTimeTrackConfig> configFile;
};

#endif // CTIMETRACK_H
