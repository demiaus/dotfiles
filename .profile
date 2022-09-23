#
# ~/.profile
#

echo "" > ~/.log/rc.log
echo "$(date +%T) open  ~/.profile" >> ~/.log/rc.log

export EDITOR=/usr/bin/vim
export VISUAL=$EDITOR
export SUDO_EDITOR=$EDITOR
export BROWSER=/usr/bin/qutebrowser
export TERMINAL=/usr/local/st
export LESS='-MRi#8j.5'
#             |||| `- center on search matches
#             |||`--- scroll horizontally 8 columns at a time
#             ||`---- case-insensitive search unless pattern contains uppercase
#             |`----- parse color codes
#             `------ show more information in prompt
export LESSHISTFILE=/dev/null
export PYTHONSTARTUP=~/.config/python/pythonrc

[ -f ~/.config/path/path.env ] && . ~/.config/path/path.env

#!/bin/sh
if [ "$TERM" = "linux" ]; then
  /bin/echo -e "
  \e]P0191724
  \e]P1eb6f92
  \e]P29ccfd8
  \e]P3f6c177
  \e]P431748f
  \e]P5c4a7e7
  \e]P6ebbcba
  \e]P7e0def4
  \e]P826233a
  \e]P9eb6f92
  \e]PA9ccfd8
  \e]PBf6c177
  \e]PC31748f
  \e]PDc4a7e7
  \e]PEebbcba
  \e]PFe0def4
  "
  clear
fi

echo "$(date +%T) close ~/.config/env/env.conf" >> ~/.log/rc.log

