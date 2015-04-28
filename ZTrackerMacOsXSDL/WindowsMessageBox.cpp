//
//  MessageBox.cpp
//  ZTrackerMacOsXSDL
//
//  Created by Robert on 4/27/15.
//  Copyright (c) 2015 Aardbei. All rights reserved.
//

#include "zt.h"
#include "WindowsMessageBox.h"

//_In_opt_  HWND hWnd,
//_In_opt_  LPCTSTR lpText,
//_In_opt_  LPCTSTR lpCaption,
//_In_      UINT uType

void MessageBox(int hWnd, LPCTSTR text, LPCTSTR lpCaption, UINT uType)
{
    std::cout << lpCaption << ": " << text << "\n";
}