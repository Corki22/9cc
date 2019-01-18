set nocompatible              
filetype off                  

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'VundleVim/Vundle.vim'
Plugin 'tpope/vim-fugitive'
Plugin 'git://git.wincent.com/command-t.git'
Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Plugin 'ascenator/L9', {'name': 'newL9'}

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



