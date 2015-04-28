//
//  WindowsTimer.h
//  ZTrackerMacOsXSDL
//
//  Created by Robert on 4/27/15.
//  Copyright (c) 2015 Aardbei. All rights reserved.
//

#ifndef __ZTrackerMacOsXSDL__WindowsTimer__
#define __ZTrackerMacOsXSDL__WindowsTimer__

#define TIME_PERIODIC 0

extern DWORD *SetTimer(int hwnd, DWORD *nIDEvent, UINT elapse, void *timerFunc);

extern MMRESULT timeSetEvent(DWORD delay, DWORD resolution, void *timeProc, DWORD *user, DWORD event);

extern MMRESULT timeKillEvent(DWORD timerId);

extern MMRESULT timeBeginPeriod(DWORD period);

#endif /* defined(__ZTrackerMacOsXSDL__WindowsTimer__) */
