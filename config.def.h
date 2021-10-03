#include <X11/XF86keysym.h>

/* Theme */
// border pixel of windows
static const unsigned int borderpx = 1;

// snap pixel
static const unsigned int snap = 32;

// bar visibility (0 = invisible, 1 = visible)
static const int showbar = 1;

// bar location (0 = bottom, 1 = top)
static const int topbar = 1;

// bar font
static const char *fonts[] = { "arial:size=12" };

// dmenu font
static const char dmenufont[] = "arial:size=12";

// colors
static const char col_gray1[] = "#222222";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#eeeeee";
static const char col_red[] = "#a30306";
static const char *colors[][3] = {
    // fg, bg, border

    [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
    [SchemeSel] = { col_gray4, col_red, col_red },
};


/* Tags */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const Rule rules[] = {
    // class, instance, title, tag mask, isfloating, monitor

    { "mpv", NULL, NULL, 0, 1, -1 },
};


/* Layouts */
// factor of master area size [0.05..0.95]
static const float mfact = 0.55;

// number of clients in master area
static const int nmaster = 1;

// 1 means respect size hints in tiled resizals
static const int resizehints = 1;

// 1 will force focus on the fullscreen window
static const int lockfullscreen = 1;

static const Layout layouts[] = {
    // symbol, arrange function

    { "[ ]", tile },
    { "> <", NULL }, //means floating
    { "[M]", monocle },
};


/* Key Definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG) \
    { MODKEY, KEY, view, {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask, KEY, toggleview, {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask, KEY, tag, {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY, toggletag, {.ui = 1 << TAG} },
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }


/* Commands */
static char dmenumon[2] = "0";
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_red, "-sf", col_gray4, NULL };
static const char *termcmd[] = { "qterminal", NULL };
static const char *volup[] = { "/usr/bin/amixer", "set", "Master", "2%+", NULL };
static const char *voldn[] = { "/usr/bin/amixer", "set", "Master", "2%-", NULL };
static const char *prntscrn[] = { "/usr/bin/scrot", "%Y-%m-%d_%H-%M-%S_$wx$h.png", "-e 'mv $f /home/$USER/screenshots/'", NULL };
static Key keys[] = {
    /* modifier, key, function, argument */
    { MODKEY, XK_Return, spawn, {.v = dmenucmd } },
    { MODKEY, XK_slash, spawn, {.v = termcmd } },
    { MODKEY, XK_b, togglebar, {0} },
    { MODKEY, XK_j, focusstack, {.i = +1 } },
    { MODKEY, XK_k, focusstack, {.i = -1 } },
    { MODKEY, XK_i, incnmaster, {.i = +1 } },
    { MODKEY, XK_d, incnmaster, {.i = -1 } },
    { MODKEY, XK_h, setmfact, {.f = -0.05} },
    { MODKEY, XK_l, setmfact, {.f = +0.05} },
    { MODKEY, XK_z, zoom, {0} },
    { MODKEY, XK_Tab, view, {0} },
    { MODKEY, XK_q, killclient, {0} },
    { MODKEY, XK_t, setlayout, {.v = &layouts[0]} },
    { MODKEY, XK_f, setlayout, {.v = &layouts[1]} },
    { MODKEY, XK_m, setlayout, {.v = &layouts[2]} },
    { MODKEY, XK_space, setlayout, {0} },
    { MODKEY|ShiftMask, XK_space, togglefloating, {0} },
    { MODKEY, XK_0, view, {.ui = ~0 } },
    { MODKEY|ShiftMask, XK_0, tag, {.ui = ~0 } },
    { MODKEY, XK_comma, focusmon, {.i = -1 } },
    { MODKEY, XK_period, focusmon, {.i = +1 } },
    { MODKEY|ShiftMask, XK_comma,  tagmon, {.i = -1 } },
    { MODKEY|ShiftMask, XK_period, tagmon, {.i = +1 } },
    { 0, XF86XK_AudioRaiseVolume, spawn, {.v = volup } },
    { 0, XF86XK_AudioLowerVolume, spawn, {.v = voldn } },
    { 0, XK_Print, spawn, {.v = prntscrn } },
    TAGKEYS( XK_1, 0)
    TAGKEYS( XK_2, 1)
    TAGKEYS( XK_3, 2)
    TAGKEYS( XK_4, 3)
    TAGKEYS( XK_5, 4)
    TAGKEYS( XK_6, 5)
    TAGKEYS( XK_7, 6)
    TAGKEYS( XK_8, 7)
    TAGKEYS( XK_9, 8)
    { MODKEY|ShiftMask, XK_q, quit, {0} },
};


/* Button Definitions */
static Button buttons[] = {
    /* click, event mask, button, function, argument */
    { ClkLtSymbol, 0, Button1, setlayout, {0} },
    { ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]} },
    { ClkWinTitle, 0, Button2, zoom, {0} },
    { ClkStatusText, 0, Button2, spawn, {.v = termcmd } },
    { ClkClientWin, MODKEY, Button1, movemouse, {0} },
    { ClkClientWin, MODKEY, Button2, togglefloating, {0} },
    { ClkClientWin, MODKEY, Button3, resizemouse, {0} },
    { ClkTagBar, 0, Button1, view, {0} },
    { ClkTagBar, 0, Button3, toggleview, {0} },
    { ClkTagBar, MODKEY, Button1, tag, {0} },
    { ClkTagBar, MODKEY, Button3, toggletag, {0} },
};
