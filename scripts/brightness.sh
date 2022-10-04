#!/bin/bash

if [ ! $# = 1 ]; then
        echo "Usage:"
        echo "$0 <up|down>"
        exit 1;
fi

case $1 in
'up')
        brightnessctl set +5% ;;
'down')
        brightnessctl set 5%- ;;
*)
        echo "parsing error"
        exit 1 ;;
esac

# Wonky ceiling "func"
max=$(brightnessctl max)
cur=$(brightnessctl get)
mod=$((cur * 100 % max))
per=$(( (cur * 100 + (max - mod)) / max))

dunstify -r 69 -u low "$per %"

exit 0
