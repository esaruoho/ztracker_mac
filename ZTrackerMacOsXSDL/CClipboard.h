//
//  CClipboard.h
//  ZTrackerMacOsXSDL
//
//  Created by Robert on 4/27/15.
//  Copyright (c) 2015 Aardbei. All rights reserved.
//

#ifndef ZTrackerMacOsXSDL_CClipboard_h
#define ZTrackerMacOsXSDL_CClipboard_h

class CClipboard
{
public:
    event *event_list[MAX_TRACKS];
    int tracks;
    int rows;
    int full;
    
    CClipboard();
    ~CClipboard();
    void copy(void);
    void paste(int start_track, int start_row, int mode); // 0 = insert, 1 = overwrite, 2 = merge
    void clear(void);
};

#endif
