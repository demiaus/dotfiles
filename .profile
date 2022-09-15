#
# ~/.profile
#

echo "" > ~/.log/rc.log
echo "$(date +%T) open  ~/.profile" >> ~/.log/rc.log

[ -f ~/.config/path/path.env ] && . ~/.config/path/path.env
[ -f ~/.bashrc ] && . ~/.bashrc

echo "$(date +%T) close ~/.profile" >> ~/.log/rc.log

