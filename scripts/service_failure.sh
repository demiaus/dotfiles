#!/bin/env sh

echo "$(date +%T): $1 failed" >> ~/.log/service_fails.log
dunstify -u critical "$(date +%T): $1 failed"
