#!/bin/bash

if	[ "$(id -u)" -eq 0 ]; then # if root
	# append to the end of 'Exec' line
    sed -i '/^Exec/ {/--use-tray-icon/ !s/$/ --use-tray-icon/}' /usr/share/applications/signal-desktop.desktop
    exit 0
else
    echo 'Must run as sudo' >&2
    exit 1
fi
