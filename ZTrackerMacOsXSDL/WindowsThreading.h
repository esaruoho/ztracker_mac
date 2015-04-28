//
//  WindowsThreading.h
//  ZTrackerMacOsXSDL
//
//  Created by Robert on 4/28/15.
//  Copyright (c) 2015 Aardbei. All rights reserved.
//

#ifndef __ZTrackerMacOsXSDL__WindowsThreading__
#define __ZTrackerMacOsXSDL__WindowsThreading__

#define THREAD_PRIORITY_TIME_CRITICAL 1

extern bool SetThreadPriority(HANDLE thread, int priority);

extern HANDLE GetCurrentThread(void);

extern DWORD WaitForSingleObject(HANDLE handle, DWORD milliseconds);

#endif /* defined(__ZTrackerMacOsXSDL__WindowsThreading__) */
