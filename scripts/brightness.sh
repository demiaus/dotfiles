#!/bin/bash

if [ ! $# = 1 ]; then
        echo "Usage:"
        echo "$0 <up|down>"
        exit 1;
fi

case $1 in
'up')
        brightnessctl set +5% save;;
'down')
        brightnessctl set 5%- save;;
*)
        echo "parsing error"
        exit 1 ;;
esac

exit 0
