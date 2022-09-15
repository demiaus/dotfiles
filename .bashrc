#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

echo "$(date +%T) open  ~/.bashrc" >> ~/.log/rc.log

[ -f ~/.bash_aliases                  ] && . ~/.bash_aliases
[ -f ~/.config/env/env.conf           ] && . ~/.config/env/env.conf
[ -f /usr/share/fzf/key-bindings.bash ] && . /usr/share/fzf/key-bindings.bash
[ -f /usr/share/fzf/completion.bash   ] && . /usr/share/fzf/completion.bash
[ -f ~/.config/fzf/rose-pine.fzf      ] && . ~/.config/fzf/rose-pine.fzf

[[ "$(whoami)" = "root" ]] && return

[[ -z "$FUNCNEST" ]] && export FUNCNEST=100          # limits recursive functions, see 'man bash'

# fff
f() {
    fff "$@"
    cd "$(cat "${XDG_CACHE_HOME:=${HOME}/.cache}/fff/.fff_d")"

}

# https://github.com/mrzool/bash-sensible/blob/master/sensible.bash

## GENERAL OPTIONS ##

# Prevent file overwrite on stdout redirection
# Use `>|` to force redirection to an existing file
set -o noclobber

# Update window size after every command
shopt -s checkwinsize

# Automatically trim long paths in the prompt (requires Bash 4.x)
PROMPT_DIRTRIM=2

# Enable history expansion with space
# E.g. typing !!<space> will replace the !! with your last command
bind Space:magic-space

# Turn on recursive globbing (enables ** to recurse all directories)
shopt -s globstar 2> /dev/null

## SMARTER TAB-COMPLETION (Readline bindings) ##

# Treat hyphens and underscores as equivalent
bind "set completion-map-case on"

# Display matches for ambiguous patterns at first tab press
bind "set show-all-if-ambiguous on"

# Immediately add a trailing slash when autocompleting symlinks to directories
bind "set mark-symlinked-directories on"

## SANE HISTORY DEFAULTS ##

# Append to the history file, don't overwrite it
shopt -s histappend

# Save multi-line commands as one command
shopt -s cmdhist

# Record each line as it gets issued
PROMPT_COMMAND='history -a'

# Huge history. Doesn't appear to slow things down, so why not?
HISTSIZE=500000
HISTFILESIZE=100000

# Avoid duplicate entries
HISTCONTROL="erasedups:ignoreboth"

# Use standard ISO 8601 timestamp
# %F equivalent to %Y-%m-%d
# %T equivalent to %H:%M:%S (24-hours format)
HISTTIMEFORMAT='%F %T '

# Enable incremental history search with up/down arrows (also Readline goodness)
# Learn more about this here: http://codeinthehole.com/writing/the-most-important-command-line-tip-incremental-history-searching-with-inputrc/
bind '"\e[A": history-search-backward'
bind '"\e[B": history-search-forward'
bind '"\e[C": forward-char'
bind '"\e[D": backward-char'

## BETTER DIRECTORY NAVIGATION ##

# Correct spelling errors during tab-completion
shopt -s dirspell 2> /dev/null
# Correct spelling errors in arguments supplied to cd
shopt -s cdspell 2> /dev/null

# This defines where cd looks for targets
# Add the directories you want to have fast access to, separated by colon
# Ex: CDPATH=".:~:~/projects" will look for targets in the current working directory, in home and in the ~/projects folder
CDPATH="."

# This allows you to bookmark your favorite places across the file system
# Define a variable containing a path and you will be able to cd into it regardless of the directory you're in
shopt -s cdable_vars
export anki="$HOME/.local/share/Anki2/addons21"

# Disable CTRL-S
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
  # get rid of artifacts
  clear
fi

echo "$(date +%T) close ~/.bashrc" >> ~/.log/rc.log

