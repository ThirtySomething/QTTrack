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

#include "CTimeTrackTask.h"

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
			// ******************************************************************
			// ******************************************************************
			CTimeTrackTask::CTimeTrackTask(std::string taskName)
				: timeTrackTaskName(taskName)
				, timeStart(0)
				, timeEnd (0)
				, isRunning(false)
				, isMeasured(false)
			{
			}

			// ******************************************************************
			// ******************************************************************
			CTimeTrackTask::~CTimeTrackTask(void)
			{
			}

			// ******************************************************************
			// ******************************************************************
			bool CTimeTrackTask::TimeTrackTaskStart(void)
			{
				if (false == isRunning)
				{
					time(&timeStart);
					isRunning = true;
					isMeasured = false;
				}
				return (!isRunning);
			}

			// ******************************************************************
			// ******************************************************************
			bool CTimeTrackTask::TimeTrackTaskEnd(void)
			{
				if (true == isRunning)
				{
					time(&timeEnd);
					isRunning = false;
					isMeasured = true;
				}
				return (!isRunning);
			}

			// ******************************************************************
			// ******************************************************************
			double CTimeTrackTask::TimeTrackTaskDuration(void)
			{
				double duration = 0.0;

				if (true == isMeasured)
				{
					duration = difftime(timeEnd, timeStart);
				}

				return duration;
			}
		}
	}
}
