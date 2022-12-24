#!/bin/bash

if [ ! $# = 1 ]; then
        echo "Usage:"
        echo "$0 <up|down|mute>"
        exit 1;
fi

case $1 in
'up')
        pamixer -i 5
        ;;
'down')
        pamixer -d 5
        ;;
'mute')
        pamixer -t ;;
*)
        echo "parsing error"
        exit 1
        ;;
esac

dunstify -r 69 -u low "$(pamixer --get-volume-human)"

exit 0
