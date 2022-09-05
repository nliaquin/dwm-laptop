# dwm-laptop
My configuration files for dwm on laptop. The only difference now between this and my laptop repo is the blocks.def.h configuration.

There are configuration files for dwm and dwmblocks. Place config.def.h in the *dwm* folder before compilation. Pleace blocks.def.h in the *dwmblocks* directory before compilation. If you need guides on how to install dwm and it's companion software, check out my guides at https://github.com/nliaquin/linux-guides/tree/main/suckless-software

Here are the main changes to the bindings:
 - dmenu = **alt + return**
 - alacritty = **alt + shift + return**
 - quit program = **alt + q**
 - quit dwm = **alt + shift + q** (be very careful not to confuse this with *quit program*
 - lock screen (dependent on slock) = **alt + l**

## Dependencies
You will need to install the following packages (or change config.def.h to use a different font & terminal):
alacritty
ttf-liberation
