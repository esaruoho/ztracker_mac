//
//  WStack.cpp
//  ZTrackerMacOsXSDL
//
//  Created by Robert on 4/27/15.
//  Copyright (c) 2015 Aardbei. All rights reserved.
//

#include "zt.h"
#include "WStack.h"

WStack::WStack() {
    head = NULL;
}
WStack::~WStack() {
    WStackNode *t;
    if (!UI) return; // UI Gets deteled before UIP_*, so safe to check for that
    while(head) {
        t = head->next;
        delete head;
        head = t;
    }
}

bool WStack::isempty(void) {
    return (head == NULL);
}

void WStack::push(CUI_Page *p) {
    WStackNode *t = new WStackNode(p);
    if (head) {
        WStackNode *p=head;
        while(p->next) p = p->next;
        p->next = t;
    } else {
        head = t;
    }
}
CUI_Page *WStack::pop(void) {
    WStackNode *p = head;
    CUI_Page *c = NULL;
    if (head) {
        if (!p->next) {
            c = p->page;
            delete p;
            head = NULL;
        } else {
            while(p->next->next) p = p->next;
            c = p->next->page;
            delete p->next;
            p->next = NULL;
        }
    }
    return c;
}
void WStack::update(void) {
    WStackNode *p = head;
    if (head) {
        if (!p->next) {
            p = head;
        } else {
            while(p->next) p = p->next;
        }
        p->page->update();
    }
}

void WStack::draw(ZTDrawable *S) {
    if (!head) return;
    WStackNode *p = head;
    while(p) {
        p->page->draw(S);
        p = p->next;
    }
}
