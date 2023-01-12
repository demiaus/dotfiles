#
# ~/.config/qutebrowser/bindings.py
#

config.bind('<Ctrl-Shift-e>', 'edit-text')

# Normal mode
config.bind('<Ctrl-m>',       'hint links spawn mpv {hint-url}', mode='normal')
config.bind('yo',             'yank inline [{title}]({url})', mode='normal')
config.bind('Ctrl+z',         'hint links spawn st -e yt-dlp {hint-url}')
config.bind('xt',             'config-cycle tabs.show always switching')
config.bind('xb',             'config-cycle statusbar.show always never')
config.bind('xx',             'config-cycle statusbar.show always never ;; config-cycle tabs.show always switching')
config.bind('go',             'download-open')
config.bind('<Ctrl-Shift-u>', 'spawn --userscript qute-bitwarden')

# Insert mode
config.bind('gi', 'mode-enter insert ;; jseval --quiet var inputs = document.getElementsByTagName("input"); for(var i = 0; i < inputs.length; i++) { var hidden = false; for(var j = 0; j < inputs[i].attributes.length; j++) { hidden = hidden || inputs[i].attributes[j].value.includes("hidden"); }; if(!hidden) { inputs[i].focus(); break; } }')
config.bind('<Ctrl-Shift-a>', 'fake-key <Home><Shift-End>',        mode='insert')
config.bind('<Ctrl-a>',       'fake-key <Home>',                   mode='insert')
config.bind('<Ctrl-e>',       'fake-key <End>',                    mode='insert')
config.bind('<Ctrl-d>',       'fake-key <Delete>',                 mode='insert')
config.bind('<Ctrl-h>',       'fake-key <BackSpace>',              mode='insert')
config.bind('<Ctrl-k>',       'fake-key <Ctrl-Delete>',            mode='insert')
config.bind('<Ctrl-u>',       'fake-key <Ctrl-BackSpace>',         mode='insert')
config.bind('<Ctrl-w>',       'fake-key <Ctrl-BackSpace>',         mode='insert')
config.bind('<Ctrl-f>',       'fake-key <Right>',                  mode='insert')
config.bind('<Ctrl-b>',       'fake-key <Left>',                   mode='insert')
config.bind('<Alt-d>',        'fake-key <Ctrl-Delete>',            mode='insert')
config.bind('<Alt-b>',        'fake-key <Ctrl-Left>',              mode='insert')
config.bind('<Alt-f>',        'fake-key <Ctrl-Right>',             mode='insert')
config.bind('<Alt-f>',        'fake-key <Ctrl-Right>',             mode='insert')
config.bind('<Ctrl-Shift-l>', 'spawn --userscript qute-bitwarden', mode='insert')

# Visual mode
config.bind('<Ctrl-Shift-p>', 'spawn --userscript get_pron.py QUTE_SELECTED_TEXT', mode='caret')

# Command mode
config.bind('<Ctrl-n>', 'completion-item-focus next', mode='command')
config.bind('<Ctrl-p>', 'completion-item-focus prev', mode='command')

# Functions
config.bind(' kp', 'jseval (function () { '+
'  var i, elements = document.querySelectorAll("body *");'+
''+
'  for (i = 0; i < elements.length; i++) {'+
'    var pos = getComputedStyle(elements[i]).position;'+
'    if (pos === "fixed" || pos == "sticky") {'+
'      elements[i].parentNode.removeChild(elements[i]);'+
'    }'+
'  }'+
'})();');
