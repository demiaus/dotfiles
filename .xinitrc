#!/bin/sh

echo "$(date +%T) open  ~/.xinitrc" >> ~/.log/rc.log

sysresources=/etc/X11/xinit/.Xresources
userresources=$HOME/.Xresources
sysmodmap=/etc/X11/xinit/.Xmodmap
usermodmap=$HOME/.Xmodmap
xprofile=$HOME/.xprofile

[ -f "$sysresources"  ] && xrdb -merge "$sysresources"
[ -f "$userresources" ] && xrdb -merge "$userresources"
[ -f "$sysmodmap"     ] && xmodmap "$sysmodmap"
[ -f "$usermodmap"    ] && xmodmap "$usermodmap"
[ -f "$xprofile"      ] && . "$xprofile"

if [ -d /etc/X11/xinit/xinitrc.d ]; then
    for f in /etc/X11/xinit/xinitrc.d/?*.sh; do
        [ -x "$f" ] && . "$f"
    done
    unset f
fi

################################################################################

# /etc/xdg/autostart & .config/autostart
dex -a

# screen
brightnessctl --restore
~/.fehbg
redshift &

# input
setxkbmap -config ~/.config/xkb/ficode.xkb
unclutter --jitter 5 --timeout 2 --start-hidden --ignore-scrolling &

# audio
pamixer --set-volume 50

# wm
slstatus &
exec dwm
