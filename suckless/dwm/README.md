<!-- badges: start -->
![License](https://img.shields.io/badge/license-MIT-brightgreen)
<!-- badges: end -->

# krumeluu's suckless [dwm](https://dwm.suckless.org/) build

### Patches
- [alwayscenter](https://dwm.suckless.org/patches/alwayscenter/)
- [bar height (spacing)](https://dwm.suckless.org/patches/bar_height/)
- [centeredwindowname](https://dwm.suckless.org/patches/centeredwindowname/)
- [fadeinactive](https://dwm.suckless.org/patches/fadeinactive/)
- [focusmaster](https://dwm.suckless.org/patches/focusmaster/)
- [fullgaps](https://dwm.suckless.org/patches/fullgaps/)
- [notallowed](https://dwm.suckless.org/patches/notallowed/)
- [pertag](https://dwm.suckless.org/patches/pertag/)
- [rotatestack](https://dwm.suckless.org/patches/rotatestack/)
- [shiftviewclients](https://github.com/bakkeby/patches/blob/master/dwm/dwm-shiftviewclients-6.2.diff)
- [swallow](https://dwm.suckless.org/patches/swallow/)
- [switchtotag](https://dwm.suckless.org/patches/switchtotag/)

### Requirements
- [dmenu](https://tools.suckless.org/dmenu/)
- [Nerd Fonts patched Cozette font](https://aur.archlinux.org/packages/nerd-fonts-cozette-ttf), or change the font in config.def.h
- [They say](https://wiki.archlinux.org/title/st#Crashes_if_page_contains_emoji_characters) colour emoji in the title bar will crash dwm. As per Arch Wiki, you can install [Symbola](https://aur.archlinux.org/packages/ttf-symbola) font to fix this

## Official README by suckless:

```
dwm - dynamic window manager
============================
dwm is an extremely fast, small, and dynamic window manager for X.


Requirements
------------
In order to build dwm you need the Xlib header files.


Installation
------------
Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

    make clean install


Running dwm
-----------
Add the following line to your .xinitrc to start dwm using startx:

    exec dwm

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

    DISPLAY=foo.bar:1 exec dwm

(This will start dwm on display :1 of the host foo.bar.)

In order to display status info in the bar, you can do something
like this in your .xinitrc:

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm


Configuration
-------------
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.
```
