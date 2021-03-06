/*************************************************************************
 *
 * FILE  CUI_Loadscreen.cpp
 * $Id: CUI_Loadscreen.cpp,v 1.10 2001/11/15 04:46:51 zonaj Exp $
 *
 * DESCRIPTION 
 *   The load file selector screen.
 *
 * This file is part of ztracker - a tracker-style MIDI sequencer.
 *
 * Copyright (c) 2000-2001, Christopher Micali <micali@concentric.net>
 * Copyright (c) 2001, Daniel Kahlin <tlr@users.sourceforge.net>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the names of the copyright holders nor the names of their
 *    contributors may be used to endorse or promote products derived 
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS�� AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******/
#include "zt.h"

char load_filename[256];
char szSearch[256];

extern int is_loading;

void do_nothing(void) {

}

void do_load(void) {
    popup_window(UIP_LoadMsg);
}

void filelist_onEnter(UserInterfaceElement *b) {
    if(ztPlayer->playing)
    {
        UIP_RUSure->str = " You crazy?";
        popup_window(UIP_RUSure);
        return;
    }
    UIP_RUSure->str = " Load file?";
    UIP_RUSure->OnYes = (VFunc)do_load;
    FileList *f = (FileList *)b;
    strcpy(load_filename,f->getCurrentItem());
    if (file_changed)
        popup_window(UIP_RUSure);
    else
        popup_window(UIP_LoadMsg);
}
/*
void BTNCLK_Toggle(UserInterfaceElement *b) {
    Button *btn;
    btn = (Button *)b;
    need_refresh++; 
    btn->updown = !btn->updown;
    if (btn->updown)
        song->instruments[cur_inst]->flags |= INSTFLAGS_CHANVOL;
    else
        song->instruments[cur_inst]->flags &= (0xFF-INSTFLAGS_CHANVOL);
    need_refresh++;     
}
*/
CUI_Loadscreen::CUI_Loadscreen(void) {
    FileList *fl;
    DirList *dl;
//  TextInput *ti;
    DriveList *dr;

//  Button *b;  

    UI = new UserInterface;

    fl = new FileList;
    UI->add_element(fl,0);
    fl->x = 2;
    fl->y = 13;
    fl->xsize = 30;
    fl->ysize = 30;
//  fl->str = &load_filename[0]; 
    fl->OnChange();
    fl->onEnter = (ActFunc)filelist_onEnter;
//    strcpy(fl->filepattern,"*.zt");

    dl = new DirList;
    UI->add_element(dl,1);
    dl->x = 34;
    dl->y = 13;
    dl->xsize = 20;
    dl->ysize = 19;

    dr = new DriveList;
    UI->add_element(dr,2);
    dr->x = 56;
    dr->y = 13;
    dr->xsize=20;
    dr->ysize=19;
    



//  b->OnClick = (ActFunc)BTNCLK_ToggleNoteRetrig;
    

/*
    ti = new TextInput;
    UI->add_element(ti,3);
    ti->x = 2;
    ti->y = 45;
    ti->ysize = 1; ti->xsize=30; ti->length=30; //ti->xsize = 50; ti->length=50;
//  ti->str = (unsigned char *)&load_filename[0];
    ti->str = (unsigned char *)&szSearch[0];
*/
    clear = 1;
}

CUI_Loadscreen::~CUI_Loadscreen(void) {
    if (UI) delete UI; UI = NULL;
}

void CUI_Loadscreen::enter(void) {
    need_refresh = 1;
    is_loading = 0;
    cur_state = STATE_LOAD;
    FileList *fl;
    DirList *dl;
    fl = (FileList *)UI->get_element(0);
    dl = (DirList *)UI->get_element(1);
    dl->OnChange();
    fl->OnChange();
    if (song->filename[0] && song->filename[0]!=' ')
        strcpy(load_filename, (const char *)song->filename);
//    fl->set_cursor(load_filename);
    fl->setCursor(fl->findItem(load_filename));
}

void CUI_Loadscreen::leave(void) {

}

void CUI_Loadscreen::update() {
    FileList *fl;
    DirList *dl;
    DriveList *dr;
    int key=0;

    UI->update();

    fl = (FileList *)UI->get_element(0);
    dl = (DirList *)UI->get_element(1);
    dr = (DriveList *)UI->get_element(2);

    if (dl->updated || dr->updated) {
        dl->OnChange();
        fl->OnChange();
    }

    if (Keys.size()) {
        key = Keys.getkey();
        switch(key) {
            case DIK_RETURN:
                need_refresh++;
                break;
        }
    }
}

void CUI_Loadscreen::draw(ZTDrawable *S) {
    if (clear) {
        if (S->lock() == 0) {
            S->fillRect(col(1),row(12),CONSOLE_WIDTH,424,COLORS.Background);
            S->unlock();
            clear=0;
        }
    }
    S->copy(CurrentSkin->bmLoad, 275, 267);
    if (S->lock()==0) {
        UI->draw(S); 
        if (!is_loading)
            draw_status(S);
        printtitle(11,"File Load",COLORS.Text,COLORS.Background,S);
        need_refresh = 0; updated=2;
        S->unlock();
    }
}
/* eof */
