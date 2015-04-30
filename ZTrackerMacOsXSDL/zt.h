#ifndef _ZT_H
#define _ZT_H

// This adds some debugging stuff and some on-screen debug indicators
//#define DEBUG

// This makes every updated rect appear randomly colored so you can see what gets updated
//#define DEBUG_SCREENMANAGER

//#define _USE_EXTENDED_LOCALES_

//#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
//#include <io.h>
////#include <direct.h>
//
////#include <windows.h>
////#include <mmsystem.h>
//#include <math.h>
//
//
#include <SDL/SDL.h>
//#include "SDLMain.h"
////#include "sdl_mixer.h"  // this is for audio testing

#include "Typedefs.h"

#define VER_MAJ 0
#define VER_MIN 98
 
//#define _ENABLE_AUDIO 1  // this enables audio init and audio plugins

#define CONSOLE_WIDTH zt_globals.screen_width
#define CONSOLE_HEIGHT zt_globals.screen_height

#define CONSOLE_DEPTH 32

#define EDIT_LOCK_TIMEOUT 800 // ms

//#define PATTERN_EDIT_ROWS (32+4)
extern int PATTERN_EDIT_ROWS;

#define DIK_MOUSE_1_ON  0xF1
#define DIK_MOUSE_1_OFF 0xF2
#define DIK_MOUSE_2_ON  0xF3
#define DIK_MOUSE_2_OFF 0xF4

#define GET_LOW_BYTE(x)  ((unsigned char)(x & 0x00FF))
#define GET_HIGH_BYTE(x) ((unsigned char)((x & 0xFF00)>>8))

#define LOW_MIDI_BYTE(x)  ((x) & 0x007F)
#define HIGH_MIDI_BYTE(x) ((x) & 0x3F80)

#ifdef RGB
#undef RGB
#endif
#define RGB(r,g,b) (long)((r)+((g)<<8)+((b)<<16))

//// Some hacks
#define mutetrack(t) song->track_mute[t] = 1; MidiOut->mute_track(t)
#define unmutetrack(t) song->track_mute[t] = 0; MidiOut->unmute_track(t)
#define toggle_track_mute(t) song->track_mute[t] = !song->track_mute[t];    if (song->track_mute[t]) MidiOut->mute_track(t); else MidiOut->unmute_track(t)
////


#define MAX_MIDI_DEVS 64 // Max midi devices in lists

#define MAX_MIDI_OUTS MAX_MIDI_DEVS
#define MAX_MIDI_INS  MAX_MIDI_DEVS

#define MAX_TRACKS 64 // Max # of tracks
#define MAX_INSTS 100 // Max # of instruments

#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

//#include "resource.h"            // resource includes for win32 icon

extern int lock_mutex(HANDLE hMutex, int timeout);
extern int unlock_mutex(HANDLE hMutex);

#include "WindowsMessageBox.h"
#include "WindowsTimer.h"
#include "WindowsThreading.h"
#include "WindowsMidi.h"

#include "fxml.h"
#include "lc_sdl_wrapper.h"      // libCON wrapper
#include "zlib_wrapper.h"        // zlib wrapper
#include "CDataBuf.h"            // data buffer for building chunks before writing to disk
//#include "timer.h"               // timer 
#include "module.h"              // module load/save and memory/events
#include "UserInterface.h"       // UI drawing, widgets, and UI managment
#include "font.h"                // font drawer
#include "keybuffer.h"           // keyboard driver
#include "conf.h"                // config class (assoc. array class)
#include "midi-io.h"             // MIDI in/out 
#include "OutputDevices.h"       // in/out plugins
#include "edit_cols.h"           // pattern editor columns hack
#include "playback.h"            // playing
#include "CUI_Page.h"            // main UI pages
#include "import_export.h"       // file import/export
#include "img.h"                 // image loading/scaling



extern ZTConf zt_globals;

#include "ColorSet.h"

#include "skins.h"

enum state { STATE_PEDIT, STATE_IEDIT, STATE_PLAY, STATE_LOGO, 
             STATE_ABOUT, STATE_SONG_CONFIG, STATE_SYSTEM_CONFIG,
             STATE_CONFIG, STATE_ORDER, STATE_PEDIT_WIN, STATE_HELP,
             STATE_LOAD, STATE_SAVE, STATE_STATUS, STATE_SLIDER_INPUT,
             STATE_SONG_MESSAGE, STATE_ARPEDIT, STATE_MIDIMACEDIT

};
#define DEFAULT_STATE STATE_PEDIT
#define DEFAULT_STATE_UIP UIP_Patterneditor

#define MAX_UPDATE_RECTS 512

#include "CScreenUpdateManager.h"
#include "CClipboard.h"

class WStackNode {
    public:
        CUI_Page *page;
        WStackNode *next;
        
        WStackNode(CUI_Page *p);
        ~WStackNode();
};

#include "WStack.h"

typedef struct {
    unsigned char r;
    unsigned char g;   //239 6912 // 239 6914
    unsigned char b;
} color;

typedef struct {
    int startx;
    int type;
    int place;
} edit_col;

typedef struct {
    unsigned char note;
    unsigned char chan;
} mbuf;

enum E_col_type { T_NOTE, T_OCTAVE, T_INST, T_VOL, T_CHAN, T_LEN, 
                  T_FX, T_FXP};

    enum Ecmd {
        CMD_NONE,
        CMD_SWITCH_HELP,
        CMD_SWITCH_PEDIT, 
        CMD_SWITCH_IEDIT,
        CMD_SWITCH_SONGCONF,
        CMD_SWITCH_ORDERLIST,
        CMD_SWITCH_SYSCONF,
        CMD_SWITCH_ABOUT,
        CMD_SWITCH_LOAD,
        CMD_SWITCH_SAVE,
        CMD_SWITCH_CONFIG,
        CMD_PLAY,
        CMD_PLAY_PAT,
        CMD_PLAY_PAT_LINE,
        CMD_STOP,
        CMD_PANIC,
        CMD_HARD_PANIC,
        CMD_QUIT,
        CMD_PLAY_ORDER,
        CMD_SWITCH_SONGLEN,
        CMD_SWITCH_SONGMSG,
        CMD_SWITCH_ARPEDIT,
        CMD_SWITCH_MIDIMACEDIT
    };


extern Skin *CurrentSkin;

extern CClipboard *clipboard;

extern bool bScrollLock;
extern bool bMouseIsDown;

//extern int FULLSCREEN;
//extern int FADEINOUT;
//extern int AUTOOPENMIDI;
//extern char SKINFILE[256];
//extern char COLORFILE[256];
//extern char WORKDIRECTORY[256];

#ifdef DEBUG
    extern BarGraph *playbuff1_bg,*playbuff2_bg,*keybuff_bg;
#endif

//int lock_mutex(HANDLE hMutex, int timeout = 2000L);
//int unlock_mutex(HANDLE hMutex);

void reset_editor(void);

int zcmp(char *s1, char *s2);
int zcmpi(char *s1, char *s2);

int checkclick(int x1, int y1, int x2, int y2);

extern int sel_pat,sel_order;
extern int modal;
//extern int prebuffer_rows;
extern int LastX,LastY,MousePressX,MousePressY;
extern edit_col edit_cols[41];
extern int zclear_flag, zclear_presscount;
extern int fast_update, FU_x, FU_y, FU_dx, FU_dy;
extern zt_module *song;
extern player *ztPlayer;
extern int editing; // editing flag/mutex (so it doesnt play a null pointer or something
extern char *col_desc[41];
extern int status_change;
extern int cur_edit_row,cur_edit_row_disp,cur_edit_pattern;
extern instrument blank_instrument;
extern KeyBuffer Keys;
extern int cur_state,need_refresh;
extern int cur_volume_percent;
extern int cur_naturalization_percent;
extern int fixmouse;
extern int cur_inst;
extern char* zt_directory;

extern bool bDontKeyRepeat;

extern char *statusmsg;
extern char szStatmsg[1024];

#define COLORS CurrentSkin->Colors

void status(char *msg,ZTDrawable *S);
void status(ZTDrawable *S);

void force_status(char *msg);

void redrawscreen(ZTDrawable *S);
void disp_pattern(int tracks_shown,int field_size,int cols_shown, ZTDrawable *S);

extern int select_row_start,select_row_end;
extern int select_track_start,select_track_end;
extern int selected;

extern int need_popup_refresh;

extern int NoFlicker;
extern int updated;
extern int cur_state,need_refresh;
extern int do_exit;
extern int editing;
extern int cur_edit_order;
extern int cur_edit_track;
extern int cur_edit_col;
extern int cur_edit_row;
extern int cur_edit_row_disp;
extern int cur_edit_pattern;
extern int cur_edit_track_disp;
extern int cur_edit_column;
extern int base_octave ;
extern int cur_step;

extern int keypress;
extern int keywait;
extern int keytimer;
extern int keyID;
extern int status_change;

extern event blank_event;
extern instrument blank_instrument;

extern int key_jazz;
extern mbuf jazz[512];

extern midiOut *MidiOut;
extern midiIn  *MidiIn;


extern UserInterface *UI;

enum E_edit_viewmode { VIEW_SQUISH, VIEW_REGULAR, VIEW_FX, VIEW_BIG }; //, VIEW_EXTEND };

extern int last_cmd_keyjazz,last_keyjazz;

void draw_status(ZTDrawable *S); /* S MUST BE LOCKED! */
extern Bitmap *load_cached_bitmap(char *name);
extern char ls_filename[256],load_filename[256], save_filename[256];
extern void setGamma(float f, ZTScreen *S);
extern int faded, doredraw;

extern Bitmap *load_bitmap(char *name);

extern void fadeIn(float step, ZTScreen *S);

extern CUI_Page *ActivePage, *LastPage, *PopupWindow;

extern CUI_About *UIP_About;
extern CUI_InstEditor *UIP_InstEditor;
extern CUI_Logoscreen *UIP_Logoscreen;
extern CUI_Loadscreen *UIP_Loadscreen;
extern CUI_Savescreen  *UIP_Savescreen;
extern CUI_Ordereditor *UIP_Ordereditor;
extern CUI_Playsong *UIP_Playsong;
extern CUI_Songconfig *UIP_Songconfig;
extern CUI_Sysconfig *UIP_Sysconfig;
extern CUI_Config *UIP_Config;
extern CUI_Patterneditor *UIP_Patterneditor;
extern CUI_PEParms *UIP_PEParms;
extern CUI_PEVol   *UIP_PEVol;
extern CUI_PENature   *UIP_PENature;
extern CUI_SliderInput *UIP_SliderInput;
extern CUI_LoadMsg *UIP_LoadMsg;
extern CUI_SaveMsg *UIP_SaveMsg;
extern CUI_NewSong *UIP_NewSong;
extern CUI_RUSure *UIP_RUSure;
extern CUI_SongDuration *UIP_SongDuration;
extern CUI_SongMessage *UIP_SongMessage;
extern CUI_Arpeggioeditor *UIP_Arpeggioeditor;
extern CUI_Midimacroeditor *UIP_Midimacroeditor;

extern void switch_page(CUI_Page *page);
extern int need_update;

void popup_window(CUI_Page *page);
void close_popup_window();

extern int light_pos, need_update_lights ;

extern int checkmousepos(int x1, int y1, int x2, int y2);

extern char *hex2note(char *str,unsigned char note);
extern int zcmpi(char *s1, char *s2);

extern int check_ext(const char *str, const char *ext);

extern int file_changed;

extern int load_lock,save_lock;

extern void do_save(void);  
extern int already_changed_default_directory;
void draw_status_vars(ZTDrawable *S); 
void begin_save(void);
//extern LPSTR cur_dir;

extern int pe_modification;
extern ZTDrawable * pe_buf;

extern int calcSongSeconds(int cur_row = -1, int cur_ord = -1);

#endif