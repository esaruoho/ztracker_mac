//
//  WStack.h
//  ZTrackerMacOsXSDL
//
//  Created by Robert on 4/27/15.
//  Copyright (c) 2015 Aardbei. All rights reserved.
//

#ifndef __ZTrackerMacOsXSDL__WStack__
#define __ZTrackerMacOsXSDL__WStack__

class WStack {  // The window stack.. used for showing popup windows
private:
    WStackNode *head;
public:
    WStack();
    ~WStack();
    void push(CUI_Page *p);
    CUI_Page *pop(void);
    void update(void);
    void draw(ZTDrawable *S);
    bool isempty(void);
};

extern WStack window_stack;

#endif /* defined(__ZTrackerMacOsXSDL__WStack__) */
