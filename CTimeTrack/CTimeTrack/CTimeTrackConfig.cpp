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

#include "CTimeTrackConfig.h"

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
			const std::string CTimeTrackConfig::nameKeyDataFile = "DataFile";
			const std::string CTimeTrackConfig::defaultKeyDataFile = "TimeTrackerData.ini";

			// ******************************************************************
			// ******************************************************************
			CTimeTrackConfig::CTimeTrackConfig(std::string NameConfigFile)
				: timeTrackConfigFileName(NameConfigFile)
				, nameSectionTimeTrack(NameConfigFile)
			{
				timeTrackConfig = std::make_unique<net::derpaul::yaip::YAIP>();
			}

			// ******************************************************************
			// ******************************************************************
			CTimeTrackConfig::~CTimeTrackConfig(void)
			{
			}

			// ******************************************************************
			// ******************************************************************
			void CTimeTrackConfig::TimeTrackConfigInit(void)
			{
				if (false == timeTrackConfig->INIFileLoad(timeTrackConfigFileName))
				{
					timeTrackConfig->SectionKeyValueSet(nameSectionTimeTrack, nameKeyDataFile, defaultKeyDataFile);
					timeTrackConfig->INIFileSave(timeTrackConfigFileName);
				}
			}

			// ******************************************************************
			// ******************************************************************
			std::string CTimeTrackConfig::DataFileNameGet(void)
			{
				return timeTrackConfig->SectionKeyValueGet(nameSectionTimeTrack, nameKeyDataFile, defaultKeyDataFile);
			}

			// ******************************************************************
			// ******************************************************************
			void CTimeTrackConfig::DataFileNameSet(std::string timeTrackDataFileName)
			{
				timeTrackConfig->SectionKeyValueSet(nameSectionTimeTrack, nameKeyDataFile, timeTrackDataFileName);
				timeTrackConfig->INIFileSave(timeTrackConfigFileName);
			}

		}
	}
}
