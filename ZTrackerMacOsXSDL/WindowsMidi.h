//
//  WindowsMidi.h
//  ZTrackerMacOsXSDL
//
//  Created by Robert on 4/28/15.
//  Copyright (c) 2015 Aardbei. All rights reserved.
//

#ifndef __ZTrackerMacOsXSDL__WindowsMidi__
#define __ZTrackerMacOsXSDL__WindowsMidi__

#include <stdio.h>

const DWORD MMSYSERR_NOERROR    = 0;
const DWORD     MMSYSERR_ERROR      = 1;
const DWORD     MMSYSERR_BADDEVICEID    = 2;
const DWORD     MMSYSERR_NOTENABLED     = 3;
const DWORD     MMSYSERR_ALLOCATED      = 4;
const DWORD     MMSYSERR_INVALHANDLE    = 5;
const DWORD     MMSYSERR_NODRIVER       = 6;
const DWORD     MMSYSERR_NOMEM      = 7;
const DWORD     MMSYSERR_NOTSUPPORTED   = 8;
const DWORD     MMSYSERR_BADERRNUM      = 9;
const DWORD     MMSYSERR_INVALFLAG      = 10;
const DWORD     MMSYSERR_INVALPARAM     = 11;
const DWORD     MMSYSERR_HANDLEBUSY     = 12;
const DWORD     MMSYSERR_INVALIDALIAS   = 13;
const DWORD     MMSYSERR_BADDB      = 14;
const DWORD     MMSYSERR_KEYNOTFOUND    = 15;
const DWORD     MMSYSERR_READERROR      = 16;
const DWORD     MMSYSERR_WRITEERROR     = 17;
const DWORD     MMSYSERR_DELETEERROR    = 18;
const DWORD     MMSYSERR_VALNOTFOUND    = 19;
const DWORD     MMSYSERR_NODRIVERCB     = 20;
const DWORD     WAVERR_BADFORMAT    = 32;
const DWORD     WAVERR_STILLPLAYING     = 33;
const DWORD     WAVERR_UNPREPARED       = 34;

const int CALLBACK_FUNCTION = 0x30000;
const int CALLBACK_NULL = 0;
const int MIM_OPEN = 0x3C1; //961
const int MIM_CLOSE = 0x3C2; //962
const int MIM_DATA = 0x3C3; //963
const int MIM_LONGDATA = 0x3C4; //964
const int MIM_ERROR = 0x3C5;
const int MIM_LONGERROR = 0x3C6;
const int MIM_MOREDATA = 0x3C7;

const int MIDIERR_NODEVICE = 1;

typedef unsigned int HMIDIIN;

typedef struct
{
    int wMid;
    int      wPid;
    int vDriverVersion;
    char szPname[1024];
    int     dwSupport;
} MIDIINCAPS;

typedef struct
{
    int      wMid;
    int      wPid;
    int vDriverVersion;
    char     szPname[1024];
    int      wTechnology;
    int      wVoices;
    int      wNotes;
    int      wChannelMask;
    DWORD     dwSupport;
} MIDIOUTCAPS;

typedef struct midihdr_tag {
    LPSTR              lpData;
    DWORD              dwBufferLength;
    DWORD              dwBytesRecorded;
    DWORD          *dwUser;
    DWORD              dwFlags;
    struct midihdr_tag  *lpNext;
    DWORD          *reserved;
    DWORD              dwOffset;
    DWORD          *dwReserved[4];
} MIDIHDR, *LPMIDIHDR;

extern MMRESULT midiInGetDevCaps(DWORD deviceID, MIDIINCAPS *lpMidiInCaps, DWORD cbMidiInCaps);

extern MMRESULT midiInOpen(HMIDIIN *lphMidiIn, UINT      uDeviceID, DWORD *dwCallback, DWORD *dwCallbackInstance, DWORD dwFlags);

extern MMRESULT midiInClose(HMIDIIN hMidiIn);

extern MMRESULT midiInPrepareHeader(HMIDIIN MidiIn, MIDIHDR *lpMidiInHdr, UINT cbMidiInHdr);

extern MMRESULT midiInUnprepareHeader(HMIDIIN hMidiIn, LPMIDIHDR lpMidiInHdr, UINT cbMidiInHdr);

extern MMRESULT midiInAddBuffer(HMIDIIN   hMidiIn,
                         LPMIDIHDR lpMidiInHdr,
                         UINT      cbMidiInHdr);

extern MMRESULT midiInStart(HMIDIIN hMidiIn);

extern MMRESULT midiInReset(HMIDIIN hMidiIn);

extern MMRESULT midiInGetErrorText(MMRESULT wError,
                            PSTR   lpText,
                            UINT     cchText);
extern UINT midiInGetNumDevs();


extern MMRESULT midiOutGetDevCaps(DWORD uDeviceID, MIDIOUTCAPS *lpMidiOutCaps, UINT cbMidiOutCaps);

extern MMRESULT midiOutOpen(HMIDIOUT *lphmo, UINT uDeviceID, DWORD *dwCallback, DWORD *dwCallbackInstance, DWORD dwFlags);

extern UINT midiOutGetNumDevs();

#endif /* defined(__ZTrackerMacOsXSDL__WindowsMidi__) */
