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
    return NULL;
}

