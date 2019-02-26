set nocompatible              
filetype off                  

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'VundleVim/Vundle.vim'
Plugin 'tpope/vim-fugitive'
Plugin 'git://git.wincent.com/command-t.git'
Plugin 'rstacruz/sparkup'
Plugin 'scrooloose/nerdtree'
Plugin 'nathanaelkane/vim-indent-guides'
Plugin 'davidhalter/jedi-vim'
Plugin 'ervandew/supertab'
"Plugin 'ascenator/L9', {'name': 'newL9'}

call vundle#end()            
filetype plugin indent on   


set nu
imap jj <Esc>
set ts=4
set incsearch
set mouse=a
cs add /usr/src/cscope.out
syntax enable
colo lucario
set shiftwidth=4
set autoindent
set ignorecase          
set smartcase  
set showmatch           
set matchtime=2 
let mapleader = "\<Space>"
let g:indent_guides_enable_on_vim_startup = 1
autocmd FileType python setlocal completeopt-=preview
let g:jedi#popup_select_first = 0
