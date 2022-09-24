#!/bin/sh

ID=$(xinput | grep -i Stick | cut -f 2 | cut -d "=" -f 2)

xinput --disable $ID
