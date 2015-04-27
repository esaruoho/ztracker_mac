//
//  WaitForSingleObject.cpp
//  ZTrackerMacOsXSDL
//
//  Created by Robert on 4/27/15.
//  Copyright (c) 2015 Aardbei. All rights reserved.
//

#include "zt.h"
#include "WaitForSingleObject.h"

// https://msdn.microsoft.com/en-us/library/windows/desktop/ms687032%28v=vs.85%29.aspx

//DWORD WINAPI WaitForSingleObject(
//                                 _In_  HANDLE hHandle,
//                                 _In_  DWORD dwMilliseconds
//                                 );

DWORD WaitForSingleObject(HANDLE handle, DWORD milliseconds)
{
    return 0;
}