#!/bin/bash

if [ ! $# = 1 ]; then
        echo "Usage:"
        echo "$0 <up|down|mute>"
        exit 1;
fi

case $1 in
'up')
        pamixer -i 5
        canberra-gtk-play -i device-added   -d "changeVolume" > /dev/null ;;
'down')
        pamixer -d 5
        canberra-gtk-play -i device-removed -d "changeVolume" > /dev/null ;;
'mute')
        canberra-gtk-play -i device-removed -d "changeVolume" > /dev/null
        pamixer -t ;;
*)
        echo "parsing error"
        exit 1 ;;
esac

dunstify -r 69 -u low "$(pamixer --get-volume) %"

exit 0
