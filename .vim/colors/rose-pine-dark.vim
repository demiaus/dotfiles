hi clear
syntax reset
let g:colors_name = "rose-pine-dark"
set background=dark
set t_Co=256

hi Normal                guifg=#e0def4 guibg=NONE    gui=NONE     cterm=NONE
hi ErrorMsg              guifg=#eb6f92 guibg=NONE
hi WarningMsg            guifg=#eb6f92 guibg=NONE
hi DiffText              guifg=#eb6f92 guibg=NONE
hi PreProc               guifg=#eb6f92 guibg=NONE
hi Exception             guifg=#eb6f92 guibg=NONE
hi Error                 guifg=#eb6f92 guibg=NONE
hi DiffDelete            guifg=#eb6f92 guibg=NONE
hi GitGutterDelete       guifg=#eb6f92 guibg=NONE
hi GitGutterChangeDelete guifg=#eb6f92 guibg=NONE
hi cssIdentifier         guifg=#eb6f92 guibg=NONE
hi cssImportant          guifg=#eb6f92 guibg=NONE
hi Function              guifg=#ebbcba guibg=NONE
hi Type                  guifg=#ebbcba guibg=NONE
hi op_lv14               guifg=#eb6f92 guibg=NONE
hi op_lv15               guifg=#eb6f92 guibg=NONE
hi Identifier            guifg=#9ccfd8 guibg=NONE
hi PMenuSel              guifg=#9ccfd8 guibg=NONE
hi Constant              guifg=#9ccfd8 guibg=NONE
hi Repeat                guifg=#9ccfd8 guibg=NONE
hi DiffAdd               guifg=#9ccfd8 guibg=NONE
hi GitGutterAdd          guifg=#9ccfd8 guibg=NONE
hi cssIncludeKeyword     guifg=#9ccfd8 guibg=NONE
hi Keyword               guifg=#9ccfd8 guibg=NONE
hi op_lv16               guifg=#9ccfd8 guibg=NONE
hi lv16c                 guifg=#9ccfd8 guibg=NONE
hi Conceal               guifg=#9ccfd8 guibg=NONE
hi Number                guifg=#31748f guibg=NONE
hi IncSearch             guifg=#c4a7e7 guibg=NONE
hi Title                 guifg=#c4a7e7 guibg=NONE
hi PreCondit             guifg=#c4a7e7 guibg=NONE
hi Debug                 guifg=#c4a7e7 guibg=NONE
hi SpecialChar           guifg=#c4a7e7 guibg=NONE
hi Conditional           guifg=#c4a7e7 guibg=NONE    gui=italic   cterm=italic
hi Todo                  guifg=#c4a7e7 guibg=NONE
hi Special               guifg=#c4a7e7 guibg=NONE
hi Label                 guifg=#c4a7e7 guibg=NONE
hi Delimiter             guifg=#c4a7e7 guibg=NONE
hi CursorLineNR          guifg=#c4a7e7 guibg=NONE
hi Define                guifg=#c4a7e7 guibg=NONE
hi MoreMsg               guifg=#c4a7e7 guibg=NONE
hi Tag                   guifg=#c4a7e7 guibg=NONE
hi MatchParen            guifg=#eb6f92 guibg=NONE
hi DiffChange            guifg=#c4a7e7 guibg=NONE
hi GitGutterChange       guifg=#c4a7e7 guibg=NONE
hi cssColor              guifg=#c4a7e7 guibg=NONE
hi Folded                guifg=#c4a7e7 guibg=#26233a
hi FoldColumn            guifg=#c4a7e7 guibg=NONE
hi Macro                 guifg=#c4a7e7 guibg=NONE
hi op_lv0                guifg=#c4a7e7 guibg=NONE
hi Directory             guifg=#c4a7e7 guibg=NONE
hi markdownLinkText      guifg=#c4a7e7 guibg=NONE
hi javaScriptBoolean     guifg=#c4a7e7 guibg=NONE
hi Include               guifg=#c4a7e7 guibg=NONE
hi Storage               guifg=#c4a7e7 guibg=NONE
hi cssClassName          guifg=#c4a7e7 guibg=NONE
hi cssClassNameDot       guifg=#c4a7e7 guibg=NONE
hi Function              guifg=#c4a7e7 guibg=NONE
hi String                guifg=#ebbcba guibg=NONE
hi Statement             guifg=#9ccfd8 guibg=NONE    gui=italic   cterm=italic
hi Operator              guifg=#ebbcba guibg=NONE
hi cssAttr               guifg=#ebbcba guibg=NONE
hi SignColumn            guifg=#eb6f92 guibg=NONE
hi NonText               guifg=#403d52 guibg=NONE
hi SpecialKey            guifg=#403d52 guibg=NONE
hi Whitespace            guifg=#403d52 guibg=NONE
hi SpecialComment        guifg=#26233a guibg=#191724 gui=italic   cterm=italic
hi Search                guibg=#31748f guifg=#f6c177
hi Title                 guifg=#e0def4
hi Pmenu                 guifg=#e0def4 guibg=#706e86
hi PmenuSbar             guifg=#e0def4 guibg=#706e86
hi PmenuThumb            guifg=#e0def4 guibg=#706e86
hi Comment               guifg=#706e86 gui=italic    cterm=italic
hi CursorLine            guibg=#26233a gui=NONE      cterm=NONE
hi CursorColumn          guibg=#26233a
hi VertSplit             guifg=#191724 guibg=#c4a7e7
hi Visual                guifg=NONE    guibg=#706e86
hi TabLine               guifg=#31748f guibg=#191724
hi TabLineFill           guifg=#191724 guibg=#706e86
hi TabLineSel            guifg=#9ccfd8 guibg=#191724
hi LineNr                guifg=#c4a7e7 guibg=NONE
hi CursorLineNr          guifg=#9ccfd8 guibg=NONE
hi ColorColumn           guifg=#eb6f92 guibg=NONE

hi SpellBad              guifg=NONE    guibg=#191724 cterm=underline
hi SpellCap              guifg=NONE    guibg=#191724 cterm=underline
hi SpellLocal            guifg=NONE    guibg=#191724 cterm=underline
hi SpellRare             guifg=NONE    guibg=#191724 cterm=underline

hi StatusLine            guifg=#1f1d2e guibg=#9ccfd8 gui=bold     cterm=bold
hi StatusLineNC          guifg=#9ccfd8 guibg=#403d52 gui=NONE     cterm=NONE
hi StatusLineTermNC      guifg=#191724 guibg=#9ccfd8 gui=bold     cterm=bold
hi StatusLineTerm        guifg=#31748f guibg=#191724 gui=NONE     cterm=NONE

" Vimwiki colors
hi def link VimwikiWeblink1 String
hi def link VimwikiLink String
