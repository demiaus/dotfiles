# demiaus's suckless [st](https://st.suckless.org/) build

### Patches
- [alpha](https://st.suckless.org/patches/alpha/)
- [anysize](https://st.suckless.org/patches/anysize/)
- [blinking cursor](https://st.suckless.org/patches/blinking_cursor/)
- [copyurl (multiline)](https://st.suckless.org/patches/copyurl/)
- [vim-browse](meta-vim-full)
- [newterm (orphan)](https://st.suckless.org/patches/newterm/)
- [open_copied_url](https://st.suckless.org/patches/open_copied_url/)

### Requirements
- Compositor such as [picom](https://github.com/yshui/picom) to enable opacity by alpha patch
- Install [Symbola](https://aur.archlinux.org/packages/ttf-symbola) if emojis seem to crash your terminal

## Official README by suckless:
```
st - simple terminal
--------------------
st is a simple terminal emulator for X which sucks less.


Requirements
------------
In order to build st you need the Xlib header files.


Installation
------------
Edit config.mk to match your local setup (st is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install st (if
necessary as root):

    make clean install


Running st
----------
If you did not install st with make clean install, you must compile
the st terminfo entry with the following command:

    tic -sx st.info

See the man page for additional details.

Credits
-------
Based on Aurélien APTEL <aurelien dot aptel at gmail dot com> bt source code.
```
