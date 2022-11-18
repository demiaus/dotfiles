#
# ~/.bash_aliases
#

echo "$(date +%T) open  ~/.bash_aliases" >> ~/.log/rc.log

if [ -x /usr/bin/dircolors ];then
  if [ -x /usr/bin/exa ];then
    alias ls='exa --color=auto --group-directories-first --icons'
    alias lsd='exa --color=auto --group-directories-first --icons --only-dirs'
  else
    alias ls='ls --color=auto --group-directories-first'
  fi
  alias diff='diff --color=auto'
  alias grep='grep --color=auto'
  alias ip='ip -color=auto'
fi
alias config='/usr/bin/git --git-dir=$HOME/.cfg/ --work-tree=$HOME'
alias vimrc='vim ~/.vim/vimrc'
alias vim='vim --servername VIMSERVER --remote-tab-silent'
alias :q=exit
alias :wq=exit
alias destroy='shred -zu'
alias ww='vim ~/vimwiki/index.md'
alias o=xdg-open
alias yt=yt-dlp
alias yta='yt-dlp -x'
alias myip='curl ipinfo.io'
alias isup='ps aux | grep'
alias sää='curl wttr.in/Turku?M'
alias mv='mv -v'
alias rm='rm -v'
alias cp='cp -v'
alias rmdir='rmdir -v'
alias r='ranger'

echo "$(date +%T) close ~/.bash_aliases" >> ~/.log/rc.log

