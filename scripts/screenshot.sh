#!/bin/bash

if [ ! $# = 1 ]; then
        echo "Usage:"
        echo "$0 <clip|save|open>"
        exit 1;
fi

case $1 in
'clip')
        file=$(date +%s).png
        maim -su | tee /tmp/$file | xclip -selection clipboard -t image/png
        #dunstify -r 69 -u low "Screenshot taken to clipboard"
        ;;
'save')
        filename=$(date +%s)
        path=~/Pictures/screenshots
        maim -su ~/Pictures/screenshots/$filename.png
        #dunstify -r 69 -u low "Screenshot saved to $path/$filename.png"
        ;;
'open')
        echo "This would open screenshot for editing" ;;
*)
        echo "parsing error"
        exit 1
        ;;
esac

#canberra-gtk-play -i camera-shutter > /dev/null

exit 0
