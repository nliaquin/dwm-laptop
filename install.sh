#!/bin/bash

cp -rf suckless/ ~/.suckless
cd ~/.suckless/dmenu/
sudo make clean install
cd ../dwm/
sudo make clean install
cd ../dwmblocks/
sudo make clean install

