#
# ~/.profile
#

echo "" > ~/.log/rc.log
echo "$(date +%T) open  ~/.profile" >> ~/.log/rc.log

[ -f ~/.bashrc ] && . ~/.bashrc

export PATH="$HOME/.local/bin:$PATH"
export PATH="$HOME/.cargo/bin:$PATH"
export XDG_CONFIG_HOME="$HOME/.config" # This should be redundant, but some script authors don't know that
export XDG_CACHE_HOME="$HOME/.cache"
export GTK_USE_PORTAL=1
export EDITOR=vim
export VISUAL=$EDITOR
export SUDO_EDITOR=$EDITOR
export BROWSER=$HOME/.local/bin/browser
export TERMINAL=st
export LESS='-MRi#8j.5'
#             |||| `- center on search matches
#             |||`--- scroll horizontally 8 columns at a time
#             ||`---- case-insensitive search unless pattern contains uppercase
#             |`----- parse color codes
#             `------ show more information in prompt
export LESSHISTFILE=/dev/null
export PYTHONSTARTUP=~/.config/python/pythonrc

FZF_DEFAULT_COMMAND='find .'
FZF_IGNORE="
  .cache
  .cargo
  .cert
  .cfg
  .chromium
  .git
  .icons
  .librewolf
  .mozilla
  .pcloud
  tmp
  pCloudDrive
"
for dir in $FZF_IGNORE; do
  FZF_DEFAULT_COMMAND="$FZF_DEFAULT_COMMAND -name $dir -prune -o"
done
export FZF_ALT_C_COMMAND="$FZF_DEFAULT_COMMAND -type d -print"
export FZF_DEFAULT_COMMAND="$FZF_DEFAULT_COMMAND -type f -print"
export BW_CLIENTID="$(<~/.bw.client_id)"
export BW_CLIENTSECRET="$(<~/.bw.client_secret)"
export BW_SESSION="$(bw unlock --raw --passwordfile=$HOME/.bw.key)"
export MW_SESSION="$(<~/.mw.apikey)"

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

echo "$(date +%T) close ~/.profile" >> ~/.log/rc.log
~/.local/bin/greetings.sh login

