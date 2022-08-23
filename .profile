#
# ~/.profile
#

echo "" > ~/.log/rc.log

[ -f ~/.config/path/path.env ] && source ~/.config/path/path.env

echo "~/.profile $(date +%T)" >> ~/.log/rc.log

