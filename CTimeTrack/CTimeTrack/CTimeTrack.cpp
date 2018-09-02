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

#include "CTimeTrack.h"

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
			CTimeTrack::CTimeTrack(std::string nameFileConfig, std::string nameFileData)
				: nameFileConfig(nameFileConfig)
				, nameFileData(nameFileData)
			{
				fileConfig = std::make_unique<CTimeTrackConfig>(nameFileConfig);
				fileData = std::make_unique<CTimeTrackData>(nameFileData);
			}

			// ******************************************************************
			// ******************************************************************
			CTimeTrack::~CTimeTrack()
			{

			}

			// ******************************************************************
			// ******************************************************************
			void CTimeTrack::TimeTrackInit()
			{
				fileConfig->TimeTrackConfigInit();
				fileConfig->DataFileNameSet(nameFileData);
				fileData->TimeTrackDataInit();
			}
		}
	}
}
