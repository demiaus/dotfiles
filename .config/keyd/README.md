
# ficode layout

### Default layer
```
,---,---,---,---,---,---,---,---,---,---,---,---,---,-------,
| ` | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = | <-    |
|---'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-----|
| ->| | q | w | e | r | t | y | u | i | o | p | [ | ] |     |
|-----',--',--',--',--',--',--',--',--',--',--',--',--'|    |
| Esc  | a | s | d | f | g | h | j | k | l | ö | ä | ' |    |
|----,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'---'----|
|    | < | z | x | c | v | b | n | m | , | . | / |          |
|----'-,-',--'--,'---'---'---'---'---'---'-,-'---',--,------|
| ctrl |  | alt |                          |altgr |  | ctrl |
'------'  '-----'--------------------------'------'  '------'
```

### Shift layer
```
,---,---,---,---,---,---,---,---,---,---,---,---,---,-------,
| ~ | ! | " | # | $ | % | ^ | & | * | ( | ) | _ | + | <-    |
|---'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-----|
| ->| | Q | W | E | R | T | Y | U | I | O | P | { | } |     |
|-----',--',--',--',--',--',--',--',--',--',--',--',--'|    |
| Esc  | A | S | D | F | G | H | J | K | L | Ö | Ä | ? |    |
|----,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'---'----|
|    | > | Z | X | C | V | B | N | M | ; | : | \ |          |
|----'-,-',--'--,'---'---'---'---'---'---'-,-'---',--,------|
| ctrl |  | alt |                          |altgr |  | ctrl |
'------'  '-----'--------------------------'------'  '------'
```

### AltGr layer  
```
,---,---,---,---,---,---,---,---,---,---,---,---,---,-------,
| ~ | ¡ | @ | £ | ¤ | ‰ | ^ |   |   |   | ° | - |   | <-    |
|---'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-----|
| ->| |   |   | € | ® | ™ |   |   |   | œ |   |   | ' |     |
|-----',--',--',--',--',--',--',--',--',--',--',--',--'|    |
| Esc  | å |   |   |   | g |   |   |   |   |   | æ | ` |    |
|----,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'---'----|
|    | | |   |   | © | v |   |   |   |   |   |   |          |
|----'-,-',--'--,'---'---'---'---'---'---'-,-'---',--,------|
| ctrl |  | alt |                          |altgr |  | ctrl |
'------'  '-----'--------------------------'------'  '------'
```

### Shifted AltGr layer  
```
,---,---,---,---,---,---,---,---,---,---,---,---,---,-------,
|   |   |   |   |   |   |   |   |   |   |   |   |   | <-    |
|---'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-----|
| ->| |   |   |   |   |   |   |   |   | Œ |   |   |   |     |
|-----',--',--',--',--',--',--',--',--',--',--',--',--'|    |
| Esc  | Å |   |   |   |   |   |   |   |   |   | Æ |   |    |
|----,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'-,-'---'----|
|    |   |   |   |   |   |   |   |   |   |   |   |          |
|----'-,-',--'--,'---'---'---'---'---'---'-,-'---',--,------|
| ctrl |  | alt |                          |altgr |  | ctrl |
'------'  '-----'--------------------------'------'  '------'
```

### CapsLock layer
- h - left
- j - down
- k - up
- l - right


### Shifted CapsLock layer
- h - ctrl-left
- j - ctrl-down
- k - ctrl-up
- l - ctrl-right

### Layers for acute, grave, macron, tilde, greek...
- TODO

# Setup

These should be about the steps to take to enable these mappings

## keyd

- Install `keyd`. (F.ex. from AUR `yay -S keyd`, or take a look at the [repo](https://github.com/rvaiya/keyd).)
- Make directory for keyd config and download the ficode config file
```
mkdir -p ~/.config/keyd && wget -O ~/.config/keyd/default.conf https://raw.githubusercontent.com/krumeluu/dotfiles/main/.config/keyd/default.conf
```
- Make symlink from default config to user config
```
ln -sf ~/.config/keyd/default.conf /etc/keyd/default.conf
```
- Link keyd compose file to enable composed characters
```
ln -s /usr/share/keyd/keyd.compose ~/.XCompose
sudo ln -s /usr/share/keyd/keyd.compose /usr/share/X11/locale/en_US.UTF-8/
```
(Only one of these should strictly be necessary, but I think both of these might be needed if you don't want to manually set the following xkb option every time you restart the daemon.)

## xkb
xkb composing option has be enabled via `setxkbmap` to render many of the characters not in the default us-keymap.
- Put `compose:menu` into xkb options locally by putting `setxkbmap -option compose:menu` in your startup script...
- ...and/or make it global by editing `/etc/X11/xorg.conf.d/00-keyboard.conf`
```
xdg-open /etc/X11/xorg.conf.d/00-keyboard.conf
```
```
Section "InputClass"
        Identifier "system-keyboard"
        MatchIsKeyboard "on"
        Option "XkbOptions" "compose:menu"
EndSection
```

## Enable keyd daemon
```
sudo systemctl enable --now keyd
```
Set the xkb option if it is not yet set
```
setxkbmap -option compose:menu
```

ficode layout should now be operational!
