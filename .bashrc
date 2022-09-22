#
# ~/.bashrc
#

[[ $- != *i* ]] && return

echo "$(date +%T) open  ~/.bashrc" >> ~/.log/rc.log

[ -f ~/.bash_aliases                  ] && . ~/.bash_aliases
[ -f /usr/share/fzf/key-bindings.bash ] && . /usr/share/fzf/key-bindings.bash
[ -f /usr/share/fzf/completion.bash   ] && . /usr/share/fzf/completion.bash
[ -f ~/.config/fzf/rose-pine.fzf      ] && . ~/.config/fzf/rose-pine.fzf
[ -f /usr/share/doc/pkgfile/command-not-found.bash ] && . /usr/share/doc/pkgfile/command-not-found.bash

[[ "$(whoami)" = "root" ]] && return
[[ -z "$FUNCNEST" ]] && export FUNCNEST=100

f() {
    fff "$@"
    cd "$(cat "${XDG_CACHE_HOME:=${HOME}/.cache}/fff/.fff_d")"
}

set -o noclobber
set -o ignoreeof
shopt -s checkwinsize
bind Space:magic-space
shopt -s globstar 2> /dev/null

bind "set completion-map-case on"
bind "set show-all-if-ambiguous on"
bind "set mark-symlinked-directories on"

shopt -s histappend
shopt -s cmdhist
shopt -s dirspell 2> /dev/null
shopt -s cdspell 2> /dev/null
shopt -s cdable_vars
export anki="$HOME/.local/share/Anki2/addons21"

PROMPT_COMMAND='history -a'
HISTSIZE=500000
HISTFILESIZE=100000
HISTCONTROL="erasedups:ignoreboth"
HISTTIMEFORMAT='%F %T '

bind '"\e[A": history-search-backward'
bind '"\e[B": history-search-forward'
bind '"\e[C": forward-char'
bind '"\e[D": backward-char'

CDPATH="."

if [[ -t 0 && $- = *i* ]]
then
    stty -ixon
fi

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

echo "$(date +%T) close ~/.bashrc" >> ~/.log/rc.log

