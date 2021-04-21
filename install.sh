#!/bin/bash
sudo cp dwm.desktop /usr/share/xsessions/
cp startup.sh ~/.startup.sh
cp xsession ~/.xsession
cp -r suckless/ ~/.suckless
cd ~/.suckless/dmenu/
sudo make clean install
cd ../dwm/
sudo make clean install
cd ../dwmblocks/
sudo make clean install
