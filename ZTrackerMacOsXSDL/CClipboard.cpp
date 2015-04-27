//
//  CClipboard.cpp
//  ZTrackerMacOsXSDL
//
//  Created by Robert on 4/27/15.
//  Copyright (c) 2015 Aardbei. All rights reserved.
//

#include "zt.h"
#include "CClipboard.h"

/* Clipboard */

CClipboard::CClipboard() {
    int i;
    for (i=0;i<MAX_TRACKS;i++) {
        this->event_list[i] = NULL;
    }
    tracks = rows = full = 0;
}
CClipboard::~CClipboard() {
    this->clear();
}

void CClipboard::copy(void) {
    int i;
    event *h,*t;
    this->clear();
    if (!selected) return;
    tracks = select_track_end - select_track_start;
    if ( (select_track_start == 0) &&
        (select_track_end == MAX_TRACKS-1) &&
        (select_row_start == 0) &&
        (select_row_end == song->patterns[cur_edit_pattern]->length-1) )
        this->full = 1;
    else
        full = 0;
    
    if (tracks>=0) tracks++; else tracks = 0;
    rows = select_row_end - select_row_start;
    if (rows>=0) rows++; else rows = 0;
    for(i=select_track_start;i<=select_track_end;i++) {
        h = song->patterns[cur_edit_pattern]->tracks[i]->event_list;
        while(h) {
            if (h->row>=select_row_start && h->row<=select_row_end) {
                t = new event(h);
                if (!t) {
                    SDL_Delay(1);
                }
                if (i-select_track_start <0 || i-select_track_start>=MAX_TRACKS) {
                    SDL_Delay(1);
                }
                t->next_event = this->event_list[i-select_track_start];
                t->row -= select_row_start;
                this->event_list[i-select_track_start] = t;
            }
            h = h->next_event;
        }
    }
}

void CClipboard::paste(int start_track, int start_row, int mode) {  // 0 = insert, 1 = overwrite, 2 = merge
    int i,j,target_row;
    event *h;//,*t;
    
    file_changed++;
    
    if (start_track == 0 && start_row == 0 && this->full==1)
        song->patterns[cur_edit_pattern]->resize(rows);
    
    if (mode == 0) // Push em down
        for(i=start_track;i<start_track+tracks && i < MAX_TRACKS;i++)
            for (j=start_row;j<start_row+rows;j++)
                song->patterns[cur_edit_pattern]->tracks[i]->ins_row(j);
    
    if (mode == 1)  // Clear the space
        for(i=start_track;i<start_track+tracks && i< MAX_TRACKS;i++)
            for(j=start_row;j<start_row+rows && j<song->patterns[cur_edit_pattern]->length ;j++)
                song->patterns[cur_edit_pattern]->tracks[i]->update_event(j,0x80,MAX_INSTS,0x80,0x0,0xff,0x0);
    
    j = start_track;
    for (i=0;i<MAX_TRACKS;i++) {
        h = this->event_list[i];
        while(h) {
            target_row = h->row + start_row;
            if (j<MAX_TRACKS  &&  target_row<song->patterns[cur_edit_pattern]->length) {
                song->patterns[cur_edit_pattern]->tracks[j]->update_event(target_row,h);
            }
            h = h->next_event;
        }
        j++;
    }
}

void CClipboard::clear(void) {
    int i;
    event *head,*t;
    for (i=0;i<MAX_TRACKS;i++) {
        head = event_list[i];
        while (head) {
            t = head->next_event;
            delete head;
            head = t;
        }
        event_list[i] = NULL;
    }
}

/* End Clipboard */