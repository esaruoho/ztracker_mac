//
//  CScreenUpdateManager.h
//  ZTrackerMacOsXSDL
//
//  Created by Robert on 4/27/15.
//  Copyright (c) 2015 Aardbei. All rights reserved.
//

#ifndef ZTrackerMacOsXSDL_CScreenUpdateManager_h
#define ZTrackerMacOsXSDL_CScreenUpdateManager_h

class CScreenUpdateManager
{
public:
    SDL_Rect r[MAX_UPDATE_RECTS];
    
    int updated_rects;
    
    bool update_all;
    
    CScreenUpdateManager()
    {
        updated_rects = 0;
        update_all = false;
    }
    
    ~CScreenUpdateManager()
    {
    }
    
    void Update(Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2)
    {
        if (update_all)
        {
            return;
        }
        
        if (updated_rects < MAX_UPDATE_RECTS-1)
        {
            if (x1<0) x1=0; if (y1<0) y1=0;
            if (x2>CONSOLE_WIDTH-1) x2 = CONSOLE_WIDTH-1;
            if (y2>CONSOLE_HEIGHT-1) y2 = CONSOLE_HEIGHT-1;
            r[updated_rects].x = x1;
            r[updated_rects].y = y1;
            r[updated_rects].w = x2-x1;
            r[updated_rects].h = y2-y1;
            int i = updated_rects;
            //                if (r[i].x<0 || r[i].y<0 || r[i].x>CONSOLE_WIDTH-1 || r[i].y>CONSOLE_HEIGHT-1)
            //                    SDL_Delay(1);
            updated_rects++;
        }
    }
    
    void UpdateWH(Sint16 x1, Sint16 y1, Uint16 w, Uint16 h)
    {
        if (update_all) return;
        if (updated_rects < MAX_UPDATE_RECTS-1) {
            r[updated_rects].x = x1;
            r[updated_rects].y = y1;
            r[updated_rects].w = w;
            r[updated_rects].h = h;
            /*
             int i = updated_rects;
             
             if (r[i].x<0 || r[i].y<0 || r[i].x>CONSOLE_WIDTH-1 || r[i].y>CONSOLE_HEIGHT-1)
             SDL_Delay(1);
             */
            updated_rects++;
        }
    }
    
    void UpdateAll(void)
    {
        update_all = true;
    }
    
    void Reset(void)
    {
        updated_rects = 0;
    }
    
    void Refresh(ZTDrawable *S)
    {
        if (update_all) {
            SDL_UpdateRect(S->surface,0,0,0,0);
            update_all = false;
            updated_rects = 0;
        } else
            if (updated_rects > 0) {
#ifdef DEBUG_SCREENMANAGER
                for (int i=0;i < updated_rects; i++)
                    SDL_FillRect(S->surface,&r[i], rand() );
#endif
                /*
                 for (int i=0;i<updated_rects;i++)
                 if (r[i].x<0 || r[i].y<0 || r[i].x>CONSOLE_WIDTH-1 || r[i].y>CONSOLE_HEIGHT-1)
                 SDL_Delay(1);
                 */
                SDL_UpdateRects(S->surface, updated_rects, &r[0]);
                updated_rects = 0;
            }
    }
    
    bool NeedRefresh(void)
    {
        return (updated_rects > 0);
    }
};

extern CScreenUpdateManager screenmanager;

#endif
