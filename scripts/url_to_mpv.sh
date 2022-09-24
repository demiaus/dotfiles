#!/bin/bash

url=$1
if [ $# != 1 ];then
        echo -e "Usage:\n$0 <URL>"
        exit 1
else
        streamlink --player mpv --player-args '--no-border --no-keepaspect-window' $1 best
fi
