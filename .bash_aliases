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
alias tridactylrc='vim ~/.config/tridactyl/tridactylrc'
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
alias mauku="ssh $USER@mauku"
alias toxic="killall toxic && sleep 1 && toxic"
alias datetime='date +"%d.%m.%Y %M:%H"'
alias test="vim ~/testing/test.txt"

# Make some noise
alias whitenoise='play -n synth whitenoise'
alias pinknoise='play -n synth pinknoise'
alias brownnoise='play -n synth brownnoise'

echo "$(date +%T) close ~/.bash_aliases" >> ~/.log/rc.log

