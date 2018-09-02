# QTTrack
Simple time tracker - nothing else more.

## General information
[![License: LGPL v3](https://img.shields.io/badge/License-LGPL%20v3-blue.svg)](http://www.gnu.org/licenses/lgpl-3.0 "LGPL-3.0")

**QTTrack** is distributed under the terms of the **GNU LESSER GENERAL PUBLIC LICENSE**, version 3.0. The text of the license is included in the file [<code>LICENSE</code>](https://github.com/ThirtySomething/Weatherstation/blob/master/LICENSE.TXT "LGPL-3.0") in the project root.

## Motivation
Due to various tasks I have to do at work, a utility like a time tracker is a good idea. Colleagues have already written their own, but they have some peculiarities and/or behaviors that are part of their way of doing their job. So I decided to write my own to have a nice, small and handy tool.

## Technology
This project is coded in C++ and takes advantage of the [QT][QT] framework for the user interface.

## Note
This project is using the **[QT Framework][QTWiki]** in the Open Source version which is downloadable [here][QT]. The UI can be found in the folder <code>QTTrack</code>. The functionality is a library stored in the folder <code>CTimeTrack</code>.

First of all you have to build the functionality. This will result in a library in a new created folder <code>bin</code>. Depending on your settings, the library will have one of these names:
* CTimeTrack32.lib
* CTimeTrack32D.lib
* CTimeTrack64.lib
* CTimeTrack64D.lib

In the second step you have to build the UI. Here the corresponding library is referenced.

## Externals
I'm using the [YAIP][YAIP] INI parser to persist the data and some settings. The project is referenced in the folder <code>submodules</code> as a git submodule.

[QT]:https://www.qt.io/
[QTWiki]:https://en.wikipedia.org/wiki/Qt_(software)
[YAIP]:https://github.com/ThirtySomething/YAIP
