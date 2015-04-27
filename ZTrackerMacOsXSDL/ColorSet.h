//
//  ColorSet.h
//  ZTrackerMacOsXSDL
//
//  Created by Robert on 4/27/15.
//  Copyright (c) 2015 Aardbei. All rights reserved.
//

#ifndef __ZTrackerMacOsXSDL__ColorSet__
#define __ZTrackerMacOsXSDL__ColorSet__

class colorset
{
public:
    TColor Background;     // Background of the ztracker "panel"
    TColor Highlight;      // highlight of the ztracker "panel"
    TColor Lowlight;       // lowlight of the ztracker "panel"
    TColor Text;           // text that goes on the zracker "panel" and on muted track names
    TColor Data;           // text that is used for the info boxes at the top of the screen
    TColor Black;          // background of the top information boxes
    TColor EditText;       // text that is in the pattern editor and all other boxes except top info boxes
    TColor EditBG;         // background of the pattern editor and all other boxes except top info boxes
    TColor EditBGlow;      // background of pattern editor (lowlight)
    TColor EditBGhigh;     // background of pattern editor (highlight)
    TColor Brighttext;     // text that goes above each track when they are not muted
    TColor SelectedBGLow;  // background of pattern editor (selected not on a lowlight or highlight)
    TColor SelectedBGHigh; // background of pattern editor (selected ON a lowlight or highlight), also cursor row selected
    TColor LCDHigh;        // beat display at bottom left corner high color
    TColor LCDMid;         // beat display at bottom left corner hid color
    TColor LCDLow;         // beat display at bottom left corner low color
    TColor CursorRowHigh;  // cursor row on a lowlight or highlight
    TColor CursorRowLow;   // cursor row not on a lowlight or highlight
    
    colorset() {
        setDefaultColors();
    }
    
    TColor getColor(Uint8 Red, Uint8 Green, Uint8 Blue) {
        return (Blue + (Green<<8) + (Red<<16));
    }
    
    TColor get_color_from_hex(char *str, conf *ColorsFile) {
        unsigned char r,g,b;
        r = ColorsFile->getcolor(str,0);
        g = ColorsFile->getcolor(str,1);
        b = ColorsFile->getcolor(str,2);
        return getColor(r,g,b);
    }
    
    int load(char *file) {
        conf ColorsFile;
        if (!ColorsFile.load(file))
            return 0;
        Background =     get_color_from_hex("Background",&ColorsFile);
        Highlight=       get_color_from_hex("Highlight",&ColorsFile);
        Lowlight =       get_color_from_hex("Lowlight",&ColorsFile);
        Text =           get_color_from_hex("Text",&ColorsFile);
        Black =          get_color_from_hex("Black",&ColorsFile);
        Data =           get_color_from_hex("Data",&ColorsFile);
        EditText =       get_color_from_hex("EditText",&ColorsFile);
        EditBG   =       get_color_from_hex("EditBG",&ColorsFile);
        EditBGlow =      get_color_from_hex("EditBGlow",&ColorsFile);
        EditBGhigh =     get_color_from_hex("EditBGhigh",&ColorsFile);
        Brighttext =     get_color_from_hex("Brighttext",&ColorsFile);
        SelectedBGLow =  get_color_from_hex("SelectedBGLow",&ColorsFile);
        SelectedBGHigh = get_color_from_hex("SelectedBGHigh",&ColorsFile);
        LCDLow =         get_color_from_hex("LCDLow",&ColorsFile);
        LCDMid =         get_color_from_hex("LCDMid",&ColorsFile);
        LCDHigh =        get_color_from_hex("LCDHigh",&ColorsFile);
        CursorRowHigh =  get_color_from_hex("CursorRowHigh",&ColorsFile);
        CursorRowLow =   get_color_from_hex("CursorRowLow",&ColorsFile);
        return 1;
    }
    
    void setDefaultColors() {
        Background =     getColor(0xA4,0x90,0x54);
        Highlight=       getColor(0xFF,0xDC,0x84);
        Lowlight =       getColor(0x50,0x44,0x28);
        Text =           getColor(0x00,0x00,0x00);
        Black =          getColor(0x00,0x00,0x00);
        Data =           getColor(0x00,0xFF,0x00);
        EditText =       getColor(0x80,0x80,0x80);
        EditBG   =       Black;
        EditBGlow =      getColor(0x14,0x10,0x0C);
        EditBGhigh =     getColor(0x20,0x20,0x14);
        Brighttext =     getColor(0xcf,0xcf,0xcf);
        SelectedBGLow =  getColor(0x00,0x00,0x80);
        SelectedBGHigh = getColor(0x00,0x00,0xA8);
        LCDLow =         getColor(0x60,0x00,0x00);
        LCDMid =         getColor(0xA0,0x00,0x00);
        LCDHigh =        getColor(0xFF,0x00,0x00);
        CursorRowHigh =  getColor(0x20,0x20,0x20);
        CursorRowLow =   getColor(0x10,0x10,0x10);
    }
    
} ;

#endif /* defined(__ZTrackerMacOsXSDL__ColorSet__) */
