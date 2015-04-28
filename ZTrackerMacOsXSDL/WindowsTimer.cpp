//
//  WindowsTimer.cpp
//  ZTrackerMacOsXSDL
//
//  Created by Robert on 4/27/15.
//  Copyright (c) 2015 Aardbei. All rights reserved.
//

#include "zt.h"
#include "WindowsTimer.h"

// https://msdn.microsoft.com/en-us/library/windows/desktop/ms644906%28v=vs.85%29.aspx
//UINT_PTR WINAPI SetTimer(
//_In_opt_  HWND hWnd,
//_In_      UINT_PTR nIDEvent,
//_In_      UINT uElapse,
//_In_opt_  TIMERPROC lpTimerFunc
//);

DWORD *SetTimer(int hwnd, DWORD *nIDEvent, UINT elapse, void *timerFunc)
{
#warning TODO
    
    return NULL;
}

// https://msdn.microsoft.com/en-us/library/windows/desktop/dd757634%28v=vs.85%29.aspx
//
// MMRESULT timeSetEvent(
//                      UINT uDelay,
//                      UINT uResolution,
//                      LPTIMECALLBACK lpTimeProc,
//                      DWORD_PTR dwUser,
//                      UINT fuEvent
//                      );

MMRESULT timeSetEvent(DWORD delay, DWORD resolution, void *timeProc, DWORD *user, DWORD event)
{
#warning TODO

    return 0;
}

// https://msdn.microsoft.com/en-us/library/windows/desktop/dd757630%28v=vs.85%29.aspx
//
// MMRESULT timeKillEvent(
//                       UINT uTimerID
//                       );

MMRESULT timeKillEvent(DWORD timerId)
{
#warning TODO
    
    return 0;
}

// https://msdn.microsoft.com/en-us/library/windows/desktop/dd757624%28v=vs.85%29.aspx
//
// MMRESULT timeBeginPeriod(
//                         UINT uPeriod
//                         );

MMRESULT timeBeginPeriod(DWORD period)
{
#warning TODO
    
    return 0;
}