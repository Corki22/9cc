#!/bin/bash

#set -u
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim

DOT_DIRECTORY="${HOME}/dotfiles"

cd $THIS_DIR
git submodule init
git submodule update

echo "start setup"

for f in .??*; do
	ln -snfv ${DOT_DIRECTORY}/${f} ${HOME}/${f}
done

mkdir -p .vim/colors
cp .vim/colors/lucario.vim ~/.vim/colors
vim +PluginInstall +qall
