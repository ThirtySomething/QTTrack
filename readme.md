# QTTrack
Simple time tracker - nothing else more.

## General information
[![License: LGPL v3](https://img.shields.io/badge/License-LGPL%20v3-blue.svg)](http://www.gnu.org/licenses/lgpl-3.0 "LGPL-3.0")

**QTTrack** is distributed under the terms of the **GNU LESSER GENERAL PUBLIC LICENSE**, version 3.0. The text of the license is included in the file [<code>LICENSE</code>](https://github.com/ThirtySomething/Weatherstation/blob/master/LICENSE.TXT "LGPL-3.0") in the project root.

## Motivation
Due to various tasks I have to do at work, a utility like a time tracker is a good idea. Colleagues have already written their own, but they have some peculiarities and/or behaviors that are part of their way of doing their job. So I decided to write my own to have a nice, small and handy tool.

## Technology
This project is coded in [C++][CPP]. The UI will be done using the [QT][QT] framework..

## Note
The project will be splittet into two parts. <code>CTimeTrack</code> contains the functionality of the time tracker. This is done in a Visual Studio Project and results in a library. The <code>QTTrack</code> part takes care about the user interface and picks up the **[QT Framework][QTWiki]** in the Open Source version which is downloadable [here][QT].

## Externals
I'm using the [YAIP][YAIP] INI parser to persist the data and some settings. The project is referenced in the folder <code>submodules</code> as a git submodule.

## Roadmap
* Implement the functionality in <code>CTimeTrack</code>
    * Task
        * Start a task
        * Stop a task
        * Calculate duration
    * Task list
        * Load
        * Save
        * Add new task
        * Delete existing task
    * Common settings for application
        * Load
        * Save
* Create the UI using [QT][QT]
* Create tests based on [Catch2-Framework][Catch]


[Catch]:https://github.com/catchorg/Catch2
[CPP]:https://en.wikipedia.org/wiki/C%2B%2B
[QT]:https://www.qt.io/
[QTWiki]:https://en.wikipedia.org/wiki/Qt_(software)
[YAIP]:https://github.com/ThirtySomething/YAIP
