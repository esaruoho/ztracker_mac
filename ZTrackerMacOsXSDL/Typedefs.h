//
//  Typedefs.h
//  ZTrackerMacOsXSDL
//
//  Created by Robert on 4/27/15.
//  Copyright (c) 2015 Aardbei. All rights reserved.
//

#ifndef ZTrackerMacOsXSDL_Typedefs_h
#define ZTrackerMacOsXSDL_Typedefs_h


typedef uint MMRESULT;
typedef uint UINT;
typedef uint HANDLE;
typedef uint DWORD;
typedef Uint64 __int64;

typedef uint HMIDIOUT;

typedef char* PSTR, *LPSTR;

typedef const char* LPCTSTR;

typedef Uint32 TColor;

typedef struct timecaps_tag {
    uint wPeriodMin;
    uint wPeriodMax;
} TIMECAPS, *PTIMECAPS, *NPTIMECAPS, *LPTIMECAPS;

#endif
