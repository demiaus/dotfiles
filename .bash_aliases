# 
# ~/.bash_aliases
# 

alias ls='exa --color=auto --group-directories-first'
alias diff='diff --color=auto'
alias grep='grep --color=auto'
alias ip='ip -color=auto'
alias config='/usr/bin/git --git-dir=$HOME/.cfg/ --work-tree=$HOME'
alias vimrc="vim ~/.vim/vimrc"
alias vim="vim --servername VIMSERVER --remote-tab-silent"
alias :q=exit
alias destroy="shred -zu"
alias ww="vim ~/vimwiki/index.md"
alias o="xdg-open"

echo "~/.bash_aliases $(date +%T)" >> ~/.log/rc.log

