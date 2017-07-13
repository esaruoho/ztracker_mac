# zTracker for macOS / OS X

A port of cmicali's zTracker (originally available for Windows only) - port started by CrossProd but then I guess it never finished.

You can find the original repo at 
* https://github.com/cmicali/ztracker
But you can also find this, more-up-to-date repo at
* https://github.com/m6502/ztrackerprime/

in theory, someone could combine them into the future zTracker for macOS / OS X version. Anyway.

## Cheer up, it's not impossible! According to random guy on Facebook.
*Coding is apparently not required for this project. Cross-platform library is used for system-dependent parts. It's only a matter of compilation SDL (which I did) and the app itself (I didn't go that far). There is a bit of a pain to resolve dependencies, though. I hope you can do it yourself.*

## Prerequisites (according to @CrossProd)
You will need X11 and SDL v1.2

1. X11 installed
    1.1 Download and install http://xquartz.macosforge.org/landing/

2. SDL v1.2
    2.1 Download framework from https://www.libsdl.org/download-1.2.php
    2.2 Copy to /Library/Frameworks

This should be it for now but I might have missed something. Please let me know.

Optional for 32 bit support:
1. Libpng 1.5 is needed. I have included the compiled libs for now so no need to do anything. These only include 64 bit at the moment.
   If needed one can compile 32 bit instead or both


## zTracker.sourceforge.net historical writeup: description

cmicali described his zTracker like this:
**zTracker is a win32 only MIDI tracker/sequencer modeled after Impulse Tracker.
The project is currently closed but the source is archived here.**

Some content excerpted from http://ztracker.sourceforge.net:
**A win32 MIDI tracker being developed in C++ (MSVC6) using SDL. Interface is almost 1:1 clone of the popular Impulse Tracker DOS tracking software. Multiple out-devices, 64 midi tracks (expandable to 256), .mid export, parameter drawing, 96ppqn, and muc**
## zTracker.sourceforge.net historical writeup: Features


* 1:1 copy of Impulse Tracker interface
* 64 track sequencer with variable 32-256 rows/pattern, 256 total patterns
* easy use of multiple machines across multiple MIDI devices/interfaces
* rock solid timing that tested as good as cubase (3/496ppqn error)
* load/save compressed .zt files
* volume/effect curve drawing in pattern editor
* IT importing (thanks to lipid)
* auto sync via midi-clock
* .mid export
* intelligent midi-in w/ slave to external sync
* *planned:* realtime pattern player (a-la-rebirth)

## zTracker.sourceforge.net historical writeup: FAQ

**Q:** Who is responsible for this?
**A:** Chris Micali, Nicolas Soudee, Austin Luminais and Daniel Kahlin.
**Q:** Why are there so many bugs.. this thing sucks, I cant use this to make music!
**A:** Lots of people already do. We do. If it doesnt work for you, use something else, or better, download the source, fix it and make it suite you, then send us the changes.
**Q:** What is the deal with this.. how is it being done?
**A:** zt is written in C++ with MSVC7. It uses the great libSDL. It runs in any 32bit resolution equal to or larger than 640x480, but it loads impulse tracker fonts and using custom font routines, it tries to trick you into thinking you're in text mode. Why? We're stuck in the past.
**Q:** Will there be sample support? When will it be implemented??
**A:** There will never be sample support. You can use a sampler, or use virtual sampler w/ an ASIO card. If we wanted sampling ability, we'd be using buzz.
**Q:** Where can I get the source code?
**A:** https://github.com/cmicali/ztracker
**Q:** What do I need to use zt?
**A:** Any modern PC running windows.
**Q:** How can I help?
**A:** The project is closed now, but you can always make some nice music.
**Q:** How do I use zt?
**A:** Check the PDF manual included in the download.
**Q:** The ( interface | design | program ) is ( ugly | lame | slow | poor | unusable )
**A:** Ableton Live is great
**Q:** The ( interface | design | program ) is ( awesome | great | lifechanging )
**A:** Great! Glad you like it! Thanks!

## zTracker was originally created by:
cmicali = **Chris Micali** ( http://github.com/cmicali )
jcl_roolz = **Javier Campos** ( https://sourceforge.net/u/jcl_roolz/profile/ )
lipid = **Austin Luminais** ( https://sourceforge.net/u/lipid/profile/ )
tlr = **Daniel Kahlin** ( https://sourceforge.net/u/tlr/profile/ )

