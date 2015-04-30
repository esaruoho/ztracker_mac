//
//  WindowsMidi.cpp
//  ZTrackerMacOsXSDL
//
//  Created by Robert on 4/28/15.
//  Copyright (c) 2015 Aardbei. All rights reserved.
//

#include "zt.h"

#import <CoreMidi/CoreMidi.h>
#import <Foundation/Foundation.h>

#include "WindowsMidi.h"

NSString *getDisplayName(MIDIObjectRef object)
{
    // Returns the display name of a given MIDIObjectRef as an NSString
    CFStringRef name = nil;
    
    if (noErr != MIDIObjectGetStringProperty(object, kMIDIPropertyDisplayName, &name))
    {
        return nil;
    }
    
    return (NSString *)name;
}


/// MIDI IN

// https://msdn.microsoft.com/en-us/library/windows/desktop/dd798453%28v=vs.85%29.aspx
MMRESULT midiInGetDevCaps(DWORD deviceID, MIDIINCAPS *lpMidiInCaps, DWORD cbMidiInCaps)
{
#warning MIDI TODO
    
    return 0;
}

// https://msdn.microsoft.com/en-us/library/windows/desktop/dd798458%28v=vs.85%29.aspx
MMRESULT midiInOpen(HMIDIIN *lphMidiIn, UINT uDeviceID, DWORD *dwCallback, DWORD *dwCallbackInstance, DWORD dwFlags)
{
#warning MIDI TODO
    
    OSStatus MIDIInputPortCreate ( MIDIClientRef client, CFStringRef portName, MIDIReadProc readProc, void *refCon, MIDIPortRef *outPort );
    
    return 0;
}

// https://msdn.microsoft.com/en-us/library/windows/desktop/dd798452%28v=vs.85%29.aspx
MMRESULT midiInClose(HMIDIIN hMidiIn)
{
#warning MIDI TODO
    
    return 0;
}

// https://msdn.microsoft.com/en-us/library/windows/desktop/dd798459%28v=vs.85%29.aspx
MMRESULT midiInPrepareHeader(HMIDIIN MidiIn, MIDIHDR *lpMidiInHdr, UINT cbMidiInHdr)
{
#warning MIDI TODO
    
    return 0;
}

// https://msdn.microsoft.com/en-us/library/windows/desktop/dd798464%28v=vs.85%29.aspx
MMRESULT midiInUnprepareHeader(HMIDIIN hMidiIn, LPMIDIHDR lpMidiInHdr, UINT cbMidiInHdr)
{
#warning MIDI TODO
    
    return 0;
}

// https://msdn.microsoft.com/en-us/library/windows/desktop/dd798450%28v=vs.85%29.aspx
MMRESULT midiInAddBuffer(HMIDIIN   hMidiIn,
                         LPMIDIHDR lpMidiInHdr,
                         UINT      cbMidiInHdr)
{
#warning MIDI TODO
    
    return 0;
}

// https://msdn.microsoft.com/en-us/library/windows/desktop/dd798462%28v=vs.85%29.aspx
MMRESULT midiInStart(HMIDIIN hMidiIn)
{
#warning MIDI TODO
    
    return 0;
    
}

// https://msdn.microsoft.com/en-us/library/windows/desktop/dd798461%28v=vs.85%29.aspx
MMRESULT midiInReset(HMIDIIN hMidiIn)
{
#warning MIDI TODO
    
    return 0;
    
}

// https://msdn.microsoft.com/en-us/library/windows/desktop/dd798454%28v=vs.85%29.aspx
MMRESULT midiInGetErrorText(MMRESULT wError,
                            PSTR   lpText,
                            UINT     cchText)
{
#warning MIDI TODO
    
    return 0;
    
}

// https://msdn.microsoft.com/en-us/library/windows/desktop/dd798456%28v=vs.85%29.aspx
UINT midiInGetNumDevs()
{
    ItemCount sourceCount = MIDIGetNumberOfSources();
    
    for (ItemCount i = 0 ; i < sourceCount ; ++i)
    {
        MIDIEndpointRef source = MIDIGetSource(i);
        
        if (source != 0)
        {
            NSLog(@"  Source: %@", getDisplayName(source));
        }
    }
    
    return (UINT)sourceCount;
    
}

MMRESULT midiOutGetDevCaps(DWORD uDeviceID, MIDIOUTCAPS *lpMidiOutCaps, UINT cbMidiOutCaps)
{
    MIDIEndpointRef device = MIDIGetDestination(uDeviceID);

    if (device == 0)
    {
        return -1;
    }
    
    [getDisplayName(device) getCString:lpMidiOutCaps->szPname maxLength:1024 encoding:NSASCIIStringEncoding];
    
    return 0;
}

MMRESULT midiOutOpen(HMIDIOUT *lphmo, UINT uDeviceID, DWORD *dwCallback, DWORD *dwCallbackInstance, DWORD dwFlags)
{
    return 0;
}

UINT midiOutGetNumDevs()
{
    ItemCount count = MIDIGetNumberOfDestinations();
    
    for (ItemCount i = 0 ; i < count ; ++i)
    {
        MIDIEndpointRef destination = MIDIGetDestination(i);
        
        if (destination != 0)
        {
            NSLog(@"  Destination: %@", getDisplayName(destination));
        }
    }
    
    return (UINT)count;

}
