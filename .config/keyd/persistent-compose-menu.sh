#!/bin/bash
# Make xkb-option "compose:menu" apply system-wide
# so keyd can produce composed characters such as ä,ö and å.
# WARNING:
# This will mercilessly overwrite 00-keyboard.conf if it's already present.

f="$HOME/.config/keyd/00-keyboard.conf" 

sudo cp -u "$f" /etc/X11/xorg.conf.d/00-keyboard.conf
