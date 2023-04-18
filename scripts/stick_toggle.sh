#!/bin/sh

ID=$(xinput | grep -i "Stick" | cut -f 2 | cut -d "=" -f 2)

if [ $(xinput list-props $ID | grep "Device Enabled" | cut -f 3) -eq "1" ]; then
	xinput --disable $ID
else
	xinput --enable $ID
fi
