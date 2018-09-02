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

#include "./../../submodules/Catch/single_include/catch2/catch.hpp"
#include "CTimeTrackTask.h"

static const std::string TaskName = "TaskName";

TEST_CASE("Create task") {
	net::derpaul::timetrack::CTimeTrackTask* testTask = nullptr;

	CHECK(nullptr == testTask);

	testTask = new net::derpaul::timetrack::CTimeTrackTask(TaskName);

	CHECK(nullptr != testTask);
	REQUIRE(0 == TaskName.compare(testTask->TimeTrackTaskNameGet()));

	delete testTask;
}

TEST_CASE("Start not running task") {
	net::derpaul::timetrack::CTimeTrackTask* testTask = nullptr;

	CHECK(nullptr == testTask);

	testTask = new net::derpaul::timetrack::CTimeTrackTask(TaskName);

	CHECK(nullptr != testTask);
	REQUIRE(0 == TaskName.compare(testTask->TimeTrackTaskNameGet()));

	REQUIRE(false == testTask->TimeTrackTaskIsRunning());
	bool result = testTask->TimeTrackTaskStart();
	REQUIRE(true == result);
	REQUIRE(true == testTask->TimeTrackTaskIsRunning());

	delete testTask;
}

TEST_CASE("Start already running task") {
	net::derpaul::timetrack::CTimeTrackTask* testTask = nullptr;

	CHECK(nullptr == testTask);

	testTask = new net::derpaul::timetrack::CTimeTrackTask(TaskName);

	CHECK(nullptr != testTask);
	REQUIRE(0 == TaskName.compare(testTask->TimeTrackTaskNameGet()));

	REQUIRE(false == testTask->TimeTrackTaskIsRunning());
	bool result = testTask->TimeTrackTaskStart();
	REQUIRE(true == result);
	REQUIRE(true == testTask->TimeTrackTaskIsRunning());

	REQUIRE(true == testTask->TimeTrackTaskIsRunning());
	result = testTask->TimeTrackTaskStart();
	REQUIRE(false == result);
	REQUIRE(true == testTask->TimeTrackTaskIsRunning());

	delete testTask;
}
