//******************************************************************************
// Copyright 2018 ThirtySomething
//******************************************************************************
// This file is part of CTimeTrack/QTTimeTrack.
//
// CTimeTrack/QTTimeTrack is free software: you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation, either version 3 of the License,
// or (at your option) any later version.
//
// CTimeTrack/QTTimeTrack is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with CTimeTrack/QTTimeTrack. If not, see <http://www.gnu.org/licenses/>.
//******************************************************************************

#pragma once

#include <string>
#include <ctime>

/**
 * Namespace of time tracker
 */
namespace net {
	/**
	 * Namespace of time tracker
	 */
	namespace derpaul {
		/**
		 * Namespace of time tracker
		 */
		namespace timetrack {
			class CTimeTrackTask
			{
			public:
				CTimeTrackTask(std::string taskName);

				virtual ~CTimeTrackTask(void);

				bool TimeTrackTaskStart(void);

				bool TimeTrackTaskEnd(void);

				double TimeTrackTaskDuration(void);

			private:
				std::string timeTrackTaskName;

				time_t timeStart;

				time_t timeEnd;

				bool isRunning;

				bool isMeasured;
			};
		}
	}
}
