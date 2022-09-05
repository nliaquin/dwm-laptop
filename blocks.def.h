//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
    {"MEM:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g", 30, 0},

    {"BAT:", "cat /sys/class/power_supply/BAT0/capacity", 30, 0},

    {"", "cat /sys/class/power_supply/BAT0/status", 5, 0},

    {"", "date '+%d/%m/%y'", 0, 0},

    {"", "date '+%H:%M'", 1, 0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
