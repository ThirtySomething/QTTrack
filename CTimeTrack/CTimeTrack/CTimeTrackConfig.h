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

#include <memory>
#include <string>
#include "YAIP.h"

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
			class CTimeTrackConfig
			{
			public:
				CTimeTrackConfig(std::string timeTrackConfigFileName);

				virtual ~CTimeTrackConfig(void);

				void TimeTrackConfigInit(void);

				std::string DataFileNameGet(void);

				void DataFileNameSet(std::string timeTrackDataFileName);

			private:
				std::string timeTrackConfigFileName;

				std::unique_ptr<net::derpaul::yaip::YAIP> timeTrackConfig;

				std::string nameSectionTimeTrack;

				static const std::string nameKeyDataFile;

				static const std::string defaultKeyDataFile;
			};
		}
	}
}
