" 
" ~/.config/nvim/plugins.vim
" 

" "VIM-PLUG AUTO-INSTALL"

 let data_dir = has('nvim') ? stdpath('data') . '/site' : '~/.vim'
 if empty(glob(data_dir . '/autoload/plug.vim'))
     silent execute '!curl -fLo '.data_dir.'/autoload/plug.vim --create-dirs 
         \ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'
     autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
 endif


 call plug#begin()
    Plug 'mattn/calendar-vim'
    Plug 'mbbill/undotree'
    " Plug 'mg979/vim-visual-multi'
    Plug 'tpope/vim-characterize'
    " Plug 'tpope/vim-fugitive'
    Plug 'Exafunction/codeium.vim'
    Plug 'amadeus/vim-convert-color-to'
    Plug 'cespare/vim-toml', { 'branch': 'main' }
    Plug 'chrisbra/colorizer'
    Plug 'chrisbra/unicode.vim'
    Plug 'christoomey/vim-titlecase'
    Plug 'dense-analysis/ale'
    Plug 'fatih/vim-go', { 'do': ':GoUpdateBinaries' }
    Plug 'glts/vim-magnum'
    Plug 'glts/vim-radical'
    Plug 'iamcco/markdown-preview.nvim', { 'do': 'cd app && npx --yes yarn install' }
    Plug 'itchyny/lightline.vim'
    Plug 'jorengarenar/vim-mvvis'
    Plug 'junegunn/fzf', { 'do': { -> fzf#install() } }
    Plug 'junegunn/fzf.vim'
    Plug 'junegunn/goyo.vim'
    Plug 'junegunn/limelight.vim'
    Plug 'junegunn/vim-easy-align'
    Plug 'mcchrish/nnn.vim'
    Plug 'mhinz/neovim-remote'
    Plug 'othree/html5.vim'
    Plug 'pangloss/vim-javascript'
    Plug 'preservim/nerdtree'
    Plug 'psliwka/vim-smoothie'
    Plug 'rhysd/rust-doc.vim'
    Plug 'romainl/vim-cool'
    Plug 'rose-pine/vim'
    Plug 'rust-lang/rust.vim'
    Plug 'sheerun/vim-polyglot'
    Plug 'svermeulen/vim-subversive'
    Plug 'svermeulen/vim-yoink'
    Plug 'tommcdo/vim-exchange'
    Plug 'tpope/vim-abolish' " required by VIM-SUBVERSIVE
    Plug 'tpope/vim-commentary'
    Plug 'tpope/vim-repeat'
    Plug 'tpope/vim-surround'
    Plug 'tridactyl/vim-tridactyl'
    Plug 'vimwiki/vimwiki'
    Plug 'wsdjeg/vim-fetch'
 call plug#end()


" "VIMWIKI"
" Use .md files for vimwiki
let g:vimwiki_list = [{'path': '~/vimwiki/', 'syntax': 'markdown', 'ext': '.md'}]
" Make vimwiki markdown links have extension .md for native vim navigation
let g:vimwiki_markdown_link_ext = 1

" "EASY-ALIGN"
" Also align comments
let g:easy_align_ignore_unmatched=0

" "VIM MARKDOWN PREVIEW"
let g:mkdp_echo_preview_url = 1
let vim_markdown_preview_toggle=2
let vim_markdown_preview_hotkey='<M-m>'
let vim_markdown_preview_browser='.local/bin/browser'

" "VIM-TITLECASE"
let g:titlecase_excluded_words = ["and", "as", "as if", "as long as", "at", "but", "by", "even if", "for", "from", "if", "if only", "in", "into", "like", "near", "now that", "nor", "of", "off", "on", "on top of", "once", "onto", "or", "out of", "over", "past", "so", "so that", "than", "that", "till", "to", "up", "upon", "with", "when", "yet"] 

" "COLORIZER"
let g:colorizer_colornames=0

" "YOINK"
let  g:yoinkIncludeDeleteOperations=1

" "RUSTFMT"
let g:rustfmt_autosave = 0

" "LIGHTLINE"
let g:lightline = { 'colorscheme': 'rosepine' }

function! CodeiumStatus()
   return codeium#GetStatusString()
endfunction

let g:lightline = {
      \ 'colorscheme': 'rosepine',
      \ 'active': {
      \   'left': [ [ 'mode', 'paste' ],
      \             [ 'readonly', 'filename', 'modified', 'codeium' ] ]
      \ },
      \ 'component_function': {
      \   'codeium': 'CodeiumStatus'
      \ },
      \ }


" "CODEIUM"
" All filetypes disabled by default
" let g:codeium_filetypes_disabled_by_default = v:true
" let g:codeium_enabled = v:false
" ...except for these
" let g:codeium_filetypes = {
"     \ "rust": v:true,
"     \ "typescript": v:true,
"     \ "python": v:true,
"     \ "go": v:true,
"     \ }

let g:codeium_manual = v:true

" "ALE"
" This keeps the 'gutter' always on so that window size keeps the same between errors/no errors
let g:ale_sign_column_always = 1

" "Goyo"
let g:goyo_width = 120
let g:goyo_height = 100
let g:goyo_linenr = 0

" "vim-go"
let g:go_fmt_autosave = 0
let g:go_auto_type_info = 1
