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
#include <thread>

static const std::string TaskName = "TaskName";
net::derpaul::timetrack::CTimeTrackTask* testTask = nullptr;
static const double TaskDuration = 5.0;

void TaskSetup(void)
{
	CHECK(nullptr == testTask);
	testTask = new net::derpaul::timetrack::CTimeTrackTask(TaskName);

	CHECK(nullptr != testTask);
	REQUIRE(0 == TaskName.compare(testTask->TimeTrackTaskNameGet()));
}

void TaskTearDown(void)
{
	if (nullptr != testTask)
	{
		delete testTask;
		testTask = nullptr;
	}
}

void TaskStart(void)
{
	REQUIRE(false == testTask->TimeTrackTaskIsRunning());
	bool result = testTask->TimeTrackTaskStart();
	REQUIRE(true == result);
	REQUIRE(true == testTask->TimeTrackTaskIsRunning());
}

void TaskEnd(void)
{
	REQUIRE(true == testTask->TimeTrackTaskIsRunning());
	bool result = testTask->TimeTrackTaskEnd();
	REQUIRE(true == result);
	REQUIRE(false == testTask->TimeTrackTaskIsRunning());
}

TEST_CASE("Create task") 
{
	TaskSetup();
	TaskTearDown();
}

TEST_CASE("Start not running task")
{
	TaskSetup();
	TaskStart();
	TaskTearDown();
}

TEST_CASE("Start already running task")
{
	TaskSetup();
	TaskStart();

	REQUIRE(true == testTask->TimeTrackTaskIsRunning());
	bool result = testTask->TimeTrackTaskStart();
	REQUIRE(false == result);
	REQUIRE(true == testTask->TimeTrackTaskIsRunning());

	TaskTearDown();
}

TEST_CASE("End not running task")
{
	TaskSetup();

	REQUIRE(false == testTask->TimeTrackTaskIsRunning());
	bool result = testTask->TimeTrackTaskEnd();
	REQUIRE(false == result);
	REQUIRE(false == testTask->TimeTrackTaskIsRunning());

	TaskTearDown();
}

TEST_CASE("End running task") 
{
	TaskSetup();
	TaskStart();
	TaskEnd();
	TaskTearDown();
}

TEST_CASE("Get duration of task")
{
	TaskSetup();
	TaskStart();
	std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long>(TaskDuration * 1000)));
	TaskEnd();

	REQUIRE(true == testTask->TimeTrackTaskIsCalculable());
	double duration = testTask->TimeTrackTaskDuration();
	REQUIRE(TaskDuration == Approx(duration));
}

