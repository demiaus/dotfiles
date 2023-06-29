#
# ~/.bash_aliases
#

echo "$(date +%T) open  ~/.bash_aliases" >> ~/.log/rc.log

if [ -x /usr/bin/dircolors ];then
  if [ -x /usr/bin/exa ];then
    alias ls='exa --color=auto --group-directories-first'
    alias lsd='exa --color=auto --group-directories-first --only-dirs'
  else
    alias ls='ls --color=auto --group-directories-first'
  fi
  alias diff='diff --color=auto'
  alias grep='grep --color=auto'
  alias ip='ip -color=auto'
fi

alias config='/usr/bin/git --git-dir=$HOME/.cfg/ --work-tree=$HOME'
alias vimrc='vim ~/.vim/vimrc'
alias tridactylrc='vim ~/.config/tridactyl/tridactylrc'
alias ww='vim ~/vimwiki/index.md'
alias v='vim --servername VIMSERVER --remote-silent'
alias b='vim --servername VIMSERVER --remote-silent ~/buffer'
alias :q='exit'
alias :wq='exit'
alias destroy='shred -zu'
alias o='xdg-open'
alias yt='yt-dlp'
alias dl='yt-dlp'
alias yta='yt-dlp -x'
alias myip='curl ipinfo.io'
alias isup='ps aux | grep'
alias sää="curl wttr.in/$LOC?M"
alias mv='mv -v'
alias rm='rm -v'
alias cp='cp -v'
alias rmdir='rmdir -v'
alias mauku="ssh $USER@mauku"
alias toxic='killall toxic && sleep 1 && toxic'
alias datetime='date +"%d.%m.%Y %H:%M"'
alias re='protonvpn-cli d; protonvpn-cli c -f'
alias BTR011="bluetoothctl connect $MAC_BTR011"
alias nura="bluetoothctl connect $MAC_NURA"
alias dic='sdcv'
alias keyb=". ~/.xprofile"
alias dic='sdcv'
alias pacman='pacman --needed'
alias yay='yay --needed'

# Make some noise
alias whitenoise='play -n synth whitenoise'
alias pinknoise='play -n synth pinknoise'
alias brownnoise='play -n synth brownnoise'

echo "$(date +%T) close ~/.bash_aliases" >> ~/.log/rc.log

