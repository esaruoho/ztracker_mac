# zTracker for macOS / OS X


A port of cmicali's zTracker (originally available for Windows only) - port started by CrossProd but then I guess it never finished.

* https://github.com/cmicali/ztracker

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
