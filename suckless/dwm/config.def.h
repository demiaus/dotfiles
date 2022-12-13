/* See LICENSE file for copyright and license details. */

/* include keysyms for volume keys */
#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int rmaster            = 1;        /* 1 means master-area is initially on the right */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 2;        /* 2 is the default spacing around the bar's font */
static const double defaultopacity  = 1.0f; 
static const double activeopacity   = 1.0f;     /* Window opacity when it's focused (0 <= opacity <= 1) */
static const double inactiveopacity = 0.875f;   /* Window opacity when it's inactive (0 <= opacity <= 1) */
static       Bool   bUseOpacity     = True;     /* Starts with opacity on any unfocused windows */

/* https://aur.archlinux.org/packages/nerd-fonts-cozette-ttf */
static const char *fonts[]               = { "CozetteVector Nerd Font:size=12:antialias=true:autohint=true", "DejaVu Sans Mono:size=12:antialias=true:autohint=true", };
static const char dmenufont[]            =   "CozetteVector Nerd Font:size=10:antialias=true:autohint=true" ;

/* Rosé Pine https://rosepinetheme.com/palette */
static const char col_base[]            = "#191724";
static const char col_surface[]         = "#1f1d2e";
static const char col_overlay[]         = "#26233a";
static const char col_iris[]            = "#c4a7e7";
static const char col_rose[]            = "#ebbcba";
static const char col_foam[]            = "#9ccfd8";
static const char col_muted[]           = "#6e6a86";
static const char col_subtle[]          = "#908caa";
static const char col_hiL[]             = "#21202e";
static const char col_hiM[]             = "#403d52";
static const char col_hiH[]             = "#524f67";
static const char *colors[][3]          = {
  /*               fg        bg        border      */
  [SchemeNorm] = { col_rose, col_base, col_surface },
  [SchemeSel]  = { col_foam, col_base, col_foam    },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
    /* class                instance  title            tags mask  switchtotag  isfloating  isterminal  noswallow  opacity  monitor  notallowed */
    { "st",                 NULL,     NULL,            1,         1,           0,          1,          0,         1,       -1,      0          },
    { "trayer",             NULL,     NULL,            1 << 8,    0,           0,          0,          0,         0,       -1,      0          },
    { "Gimp",               NULL,     NULL,            1 << 2,    1,           1,          0,          0,         1,       -1,      0          },
    { "LibreWolf",          NULL,     NULL,            1 << 1,    1,           0,          0,          0,         1,       -1,      0          },
    { "qutebrowser",        NULL,     NULL,            1 << 1,    1,           0,          0,          0,         1,       -1,      0          },
    { "Brave-browser-beta", NULL,     NULL,            1 << 1,    1,           0,          0,          0,         1,       -1,      0          },
    { "Brave-browser",      NULL,     NULL,            1 << 1,    1,           0,          0,          0,         1,       -1,      0          },
    { "mpv",                NULL,     NULL,            1 << 3,    0,           0,          0,          0,         1,       -1,      0          },
    { "MuseScore3",         NULL,     NULL,            1 << 8,    1,           0,          0,          0,         1,       -1,      0          },
    { "Signal",             NULL,     NULL,            1 << 6,    1,           0,          0,          0,         1,       -1,      0          },
    { "TelegramDesktop",    NULL,     NULL,            1 << 6,    1,           0,          0,          0,         1,       -1,      0          },
    { "KotatogramDesktop",  NULL,     NULL,            1 << 6,    1,           0,          0,          0,         1,       -1,      0          },
    { "Anki",               "anki",   NULL,            1 << 7,    1,           0,          0,          0,         1,       -1,      0          },
    { "Anki",               "anki",   "Browse",        1 << 7,    0,           1,          0,          0,         1,       -1,      0          },
    { "Anki",               "anki",   "Add-ons",       1 << 7,    0,           1,          0,          0,         1,       -1,      0          },
    { "Steam",              "Steam",  "Steam",         1 << 5,    1,           1,          0,          0,         1,       -1,      0          },
    { "Steam",              "Steam",  "Steam - News",  1 << 5,    0,           1,          0,          0,         1,       -1,      0          },
    { NULL,                 NULL,     "Event Tester",  0,         0,           0,          0,          1,         1,       -1,      0          }, /* xev */
};

/* layout(s) */
static const float mfact        = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster        = 1;    /* number of clients in master area */
static const int resizehints    = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1;    /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[T]",      tile },    /* first entry is default */
    { "[F]",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle },
};

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[]          = { "dmenu_run_history", "-l", "3", NULL };

static const char *termcmd[]           = { "/home/ami/.local/bin/terminal", NULL };
static const char *browsercmd[]        = { "/home/ami/.local/bin/browser",  NULL };
/* volume */
static const char *volmutetogglecmd[]  = { "vol.sh", "mute", NULL };
static const char *voldowncmd[]        = { "vol.sh", "down", NULL };
static const char *volupcmd[]          = { "vol.sh", "up",   NULL };
/* screen */
static const char *brightnessupcmd[]   = { "brightness.sh", "up",   NULL };
static const char *brightnessdowncmd[] = { "brightness.sh", "down", NULL };
static const char *screenclipcmd[]     = { "screenshot.sh", "clip", NULL };
static const char *screensavecmd[]     = { "screenshot.sh", "save", NULL };
static const char *screeneditcmd[]     = { "screenshot.sh", "edit", NULL };
static const char *ocrcmd[]            = { "OCR.sh", NULL };
/* zoom / magnify */
static const char *crosshaircmd[]      = { "/usr/bin/slop", "-r", "crosshair", NULL };
static const char *boxzoomcmd[]        = { "/usr/bin/slop", "-r", "boxzoom",   NULL };
/* power */
static const char *shutdowncmd[]       = { "systemctl", "poweroff", NULL };
static const char *rebootcmd[]         = { "systemctl", "reboot",   NULL };
/* input */
static const char *emojicmd[]          = { "dmenu-emoji.sh", NULL };

/* key definitions */
#define MODKEY  Mod4Mask
#define MODKEY2 Mod1Mask
#define TERMMOD ControlMask|ShiftMask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define XK_Mute  XF86XK_AudioMute
#define XK_VolDn XF86XK_AudioLowerVolume
#define XK_VolUp XF86XK_AudioRaiseVolume
#define XK_ScrUp XF86XK_MonBrightnessUp
#define XK_ScrDn XF86XK_MonBrightnessDown

static const Key keys[] = {
    /* modifier            key             function          argument */
    { MODKEY,              XK_Print,       spawn,            {.v = screenclipcmd     } },
    { MODKEY|ShiftMask,    XK_Print,       spawn,            {.v = screensavecmd     } },
    { MODKEY|TERMMOD,      XK_Print,       spawn,            {.v = screeneditcmd     } },
    { 0,                   XK_Mute,        spawn,            {.v = volmutetogglecmd  } },
    { 0,                   XK_VolDn,       spawn,            {.v = voldowncmd        } },
    { 0,                   XK_VolUp,       spawn,            {.v = volupcmd          } },
    { 0,                   XK_ScrUp,       spawn,            {.v = brightnessupcmd   } },
    { 0,                   XK_ScrDn,       spawn,            {.v = brightnessdowncmd } },
    { MODKEY,              XK_z,           spawn,            {.v = crosshaircmd      } },
    { MODKEY|ShiftMask,    XK_z,           spawn,            {.v = boxzoomcmd        } },
    { MODKEY|ShiftMask,    XK_b,           spawn,            {.v = browsercmd        } },
    { MODKEY|TERMMOD,      XK_BackSpace,   spawn,            {.v = rebootcmd         } },
    { MODKEY|TERMMOD,      XK_Delete,      spawn,            {.v = shutdowncmd       } },
    { MODKEY,              XK_p,           spawn,            {.v = dmenucmd          } },
    { MODKEY|ShiftMask,    XK_Return,      spawn,            {.v = termcmd           } },
    { MODKEY,              XK_e,           spawn,            {.v = emojicmd          } },
    { MODKEY,              XK_o,           spawn,            {.v = ocrcmd            } },
    { MODKEY,              XK_b,           togglebar,        {0} },
    { MODKEY|ShiftMask,    XK_j,           rotatestack,      {.i = +1 } },
    { MODKEY|ShiftMask,    XK_k,           rotatestack,      {.i = -1 } },
    { MODKEY,              XK_j,           focusstack,       {.i = +1 } },
    { MODKEY,              XK_k,           focusstack,       {.i = -1 } },
    { MODKEY,              XK_i,           incnmaster,       {.i = +1 } },
    { MODKEY,              XK_d,           incnmaster,       {.i = -1 } },
    { MODKEY,              XK_h,           setmfact,         {.f = -0.05} },
    { MODKEY,              XK_l,           setmfact,         {.f = +0.05} },
    { MODKEY,              XK_Return,      zoom,             {0} },
    { MODKEY,              XK_Tab,         view,             {0} },
    { MODKEY,              XK_q,           killclient,       {0} },
    { MODKEY,              XK_t,           setlayout,        {.v = &layouts[0]} },
    { MODKEY,              XK_f,           setlayout,        {.v = &layouts[1]} },
    { MODKEY,              XK_m,           setlayout,        {.v = &layouts[2]} },
    { MODKEY,              XK_space,       setlayout,        {0} },
    { MODKEY|ShiftMask,    XK_space,       togglefloating,   {0} },
    { MODKEY2,             XK_j,           moveresize,       {.v = "  0x  25y   0w   0h" } },
    { MODKEY2,             XK_k,           moveresize,       {.v = "  0x -25y   0w   0h" } },
    { MODKEY2,             XK_l,           moveresize,       {.v = " 25x   0y   0w   0h" } },
    { MODKEY2,             XK_h,           moveresize,       {.v = "-25x   0y   0w   0h" } },
    { MODKEY2|ShiftMask,   XK_h,           moveresize,       {.v = "  0x   0y -25w   0h" } },
    { MODKEY2|ShiftMask,   XK_j,           moveresize,       {.v = "  0x   0y   0w  25h" } },
    { MODKEY2|ShiftMask,   XK_k,           moveresize,       {.v = "  0x   0y   0w -25h" } },
    { MODKEY2|ShiftMask,   XK_l,           moveresize,       {.v = "  0x   0y  25w   0h" } },
    { MODKEY2|ControlMask, XK_h,           moveresizeedge,   {.v = "l"} },
    { MODKEY2|ControlMask, XK_j,           moveresizeedge,   {.v = "b"} },
    { MODKEY2|ControlMask, XK_k,           moveresizeedge,   {.v = "t"} },
    { MODKEY2|ControlMask, XK_l,           moveresizeedge,   {.v = "r"} },
    { MODKEY2|TERMMOD,     XK_h,           moveresizeedge,   {.v = "L"} },
    { MODKEY2|TERMMOD,     XK_j,           moveresizeedge,   {.v = "B"} },
    { MODKEY2|TERMMOD,     XK_k,           moveresizeedge,   {.v = "T"} },
    { MODKEY2|TERMMOD,     XK_l,           moveresizeedge,   {.v = "R"} },
    { MODKEY,              XK_0,           view,             {.ui = ~0 } },
    { MODKEY|ShiftMask,    XK_0,           tag,              {.ui = ~0 } },
    { MODKEY,              XK_comma,       focusmon,         {.i = -1 } },
    { MODKEY,              XK_period,      focusmon,         {.i = +1 } },
    { MODKEY|ShiftMask,    XK_comma,       tagmon,           {.i = -1 } },
    { MODKEY|ShiftMask,    XK_period,      tagmon,           {.i = +1 } },
    { MODKEY|ControlMask,  XK_space,       focusmaster,      {0} },
    { MODKEY2,             XK_Tab,         shiftviewclients, { .i = +1 } },
    { MODKEY2|ShiftMask,   XK_Tab,         shiftviewclients, { .i = -1 } },
    { MODKEY,              XK_r,           togglermaster,    {0} },
    { MODKEY|TERMMOD,      XK_q,           quit,             {0} },
    { MODKEY|TERMMOD,      XK_comma,       changeopacity,    {.f = -0.1}},
    { MODKEY|TERMMOD,      XK_period,      changeopacity,    {.f = +0.1}},
    { MODKEY,              XK_a,           toggleopacity,    {0} },
    TAGKEYS(               XK_1,           0)
    TAGKEYS(               XK_2,           1)
    TAGKEYS(               XK_3,           2)
    TAGKEYS(               XK_4,           3)
    TAGKEYS(               XK_5,           4)
    TAGKEYS(               XK_6,           5)
    TAGKEYS(               XK_7,           6)
    TAGKEYS(               XK_8,           7)
    TAGKEYS(               XK_9,           8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

