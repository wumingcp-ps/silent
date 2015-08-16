cmake_minimum_required (VERSION 2.8) 
project(silent) 
set (silent_VERSION_MAJOR 1) 
set (silent_VERSION_MINOR 0) 
add_definitions(-DUNICODE -D_UNICODE) 
add_definitions(-D_AFXDLL) 
set(CMAKE_MFC_FLAG 1) 
add_executable(silent WIN32 
	silent.h
	silent.cpp
	sound.h
	sound.cpp
	headset.h
	headset.cpp
	silentDlg.h
       	silentDlg.cpp
	stdafx.h
	stdafx.cpp
       	Resource.h
	targetver.h	
	silent.rc
	res/silent.rc2
) 
