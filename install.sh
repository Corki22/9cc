#!/bin/bash

#set -u

DOT_DIRECTORY="${HOME}/dotfiles"

cd $THIS_DIR
git submodule init
git submodule update

echo "start setup"

for f in .??*; do
	ln -snfv ${DOT_DIRECTORY}/${f} ${HOME}/${f}
done

mkdir -p .vim/colors
cp lucario.vim ~/.vim/colors

