//
//  MessageBox.h
//  ZTrackerMacOsXSDL
//
//  Created by Robert on 4/27/15.
//  Copyright (c) 2015 Aardbei. All rights reserved.
//

#ifndef __ZTrackerMacOsXSDL__MessageBox__
#define __ZTrackerMacOsXSDL__MessageBox__

#define MB_ICONERROR 1
#define MB_OK 2

extern void MessageBox(int hWnd, LPCTSTR text, LPCTSTR lpCaption, UINT uType);

#endif /* defined(__ZTrackerMacOsXSDL__MessageBox__) */
