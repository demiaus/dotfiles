/* See LICENSE file for copyright and license details. */

/* include keysyms for volume keys */
#include <X11/XF86keysym.h>
#include "dwm.c"

/* appearance */
static const unsigned int borderpx       = 0;   /* border pixel of windows */
static const unsigned int gappx          = 8;   /* gaps between windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const double activeopacity        = 1.0f;     /* Window opacity when it's focused (0 <= opacity <= 1) */
static const double inactiveopacity      = 0.925f;   /* Window opacity when it's inactive (0 <= opacity <= 1) */
static Bool bUseOpacity                  = True;     /* Starts with opacity on any unfocused windows */
static const int user_bh                 = 6;   /* 2 is the default spacing around the bar's font */

/* https://aur.archlinux.org/packages/nerd-fonts-cozette-ttf */
static const char *fonts[]               = { "CozetteVector Nerd Font:size=16" };
static const char dmenufont[]            = "CozetteVector Nerd Font:size=16";

/* Rosé Pine https://rosepinetheme.com/palette */
static const char col_base[]            = "#191724";
static const char col_surface[]         = "#1f1d2e";
static const char col_rose[]            = "#ebbcba";
static const char col_foam[]            = "#9ccfd8";
static const char *colors[][3]      = {
        /*               fg         bg         border   */
        [SchemeNorm] = { col_rose, col_base, col_surface },
        [SchemeSel]  = { col_foam, col_base,  col_base  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
        /* xprop(1):
         *      WM_CLASS(STRING) = instance, class
         *      WM_NAME(STRING) = title
         */
  /* class             instance     title           tags mask     switchtotag    isfloating  isterminal  noswallow  monitor notallowed */
        { "Gimp",            NULL,        NULL,           0,            1,             1,          0,                            0,                               -1,     0 },
        { "st",              NULL,        NULL,           1,            1,             0,          1,                            0,                                     -1,     0 },
        { "alacritty",       NULL,        NULL,           1,            1,             0,          1,                            0,                                     -1,     0 },
        { "librewolf",       "Navigator", NULL,           1 << 1,       1,             0,          0,                            0,                                     -1,     0 },
        { "Steam",           "Steam",     "Steam",        1 << 5,       1,             0,          0,                            0,                                     -1,     0 },
        { "Steam",           "Steam",     "Steam - News", 1 << 5,       0,             1,          0,                            0,                                     -1,     1 },
        { "Steam",           "Steam",     "Friends List", 1 << 5,       0,             1,          0,                            0,                                     -1,     1 },
        { "Signal",          NULL,        NULL,           1 << 6,       1,             0,          0,                            0,                                     -1,     0 },
        { "TelegramDesktop", NULL,        NULL,           1 << 6,       1,             0,          0,                            0,                                     -1,     0 },
        { "Anki",            "anki",      NULL,           1 << 7,       1,             0,          0,                            0,                                     -1,     0 },
        { "Anki",            "anki",      "Browse",       1 << 7,       1,             1,          0,                            0,                                     -1,     0 },
        { "MuseScore3",      "musescore", NULL,           1 << 8,       1,             0,          0,                            0,                                     -1,     0 },
  { NULL,              NULL,        "Event Tester", 0,            0,             0,          0,          1,         -1,     0 },
};

/* layout(s) */
static const float mfact          = 0.55; /* factor of master area size [0.05..0.95] */
static const int   nmaster        = 1;    /* number of clients in master area */
static const int   resizehints    = 1;    /* 1 means respect size hints in tiled resizals */
static const int   lockfullscreen = 1;    /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
        /* symbol     arrange function */
        { "[T]",      tile    }, /* first entry is default */
        { "[F]",      NULL    }, /* no layout function means floating behavior */
        { "[M]",      monocle },
};

/* key definitions */
#define MODKEY  Mod4Mask
#define MODKEY2 Mod1Mask
#define TAGKEYS(KEY,TAG) \
        { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
        { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
        { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
        { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static       char  dmenumon[2]    = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]     = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_base, "-nf", col_rose, "-sb", col_base, "-sf", col_foam, NULL };
static const char *termcmd[]      = { "/usr/local/bin/st", NULL };
static const char *crosshaircmd[] = { "/usr/bin/slop", "-r", "crosshair", NULL };
static const char *boxzoomcmd[]   = { "/usr/bin/slop", "-r", "boxzoom",   NULL };
static const char *trayercmd[]    = { "trayer", "--edge", "top", "--align", "right", "--widthtype", "request", "--SetDockType", "true", "--SetPartialStrut", "false", "--expand", "true", "--tint", "0x191724", "--heighttype", "request", NULL };

static Key keys[] = {
        /* modifier          key                       function          argument */
        { 0,                 XK_Print,                 spawn,            SHCMD("$HOME/scripts/screenshot clip") },
        { ShiftMask,         XK_Print,                 spawn,            SHCMD("$HOME/scripts/screenshot save") },
        { MODKEY|ShiftMask,  XK_Print,                 spawn,            SHCMD("$HOME/scripts/screenshot open") },
        { 0,                 XF86XK_AudioMute,         spawn,            SHCMD("$HOME/scripts/vol.sh mute") },
        { 0,                 XF86XK_AudioLowerVolume,  spawn,            SHCMD("$HOME/scripts/vol.sh down") },
        { 0,                 XF86XK_AudioRaiseVolume,  spawn,            SHCMD("$HOME/scripts/vol.sh up") },
        { 0,                 XF86XK_MonBrightnessUp,   spawn,            SHCMD("$HOME/scripts/brightness.sh up") },
        { 0,                 XF86XK_MonBrightnessDown, spawn,            SHCMD("$HOME/scripts/brightness.sh down") },
        { MODKEY,            XK_z,                     spawn,            {.v = crosshaircmd } },
        { MODKEY|ShiftMask,  XK_z,                     spawn,            {.v = boxzoomcmd } },
        { MODKEY,            XK_w,                     spawn,            SHCMD("librewolf") },
        { MODKEY,            XK_Delete,                spawn,            SHCMD("systemctl reboot") },
        { MODKEY|ShiftMask,  XK_Delete,                spawn,            SHCMD("systemctl poweroff") },
        { MODKEY,            XK_t,                     spawn,            {.v = trayercmd } },
        { MODKEY|ShiftMask,  XK_t,                     spawn,            SHCMD("killall trayer") },

        { MODKEY,            XK_p,                     spawn,            {.v = dmenucmd } },
        { MODKEY,            XK_Return,                spawn,            {.v = termcmd } },

        { MODKEY,            XK_m,                     focusmaster,      {0} },
        { MODKEY,            XK_b,                     togglebar,        {0} },
        { MODKEY,            XK_j,                     focusstack,       {.i = +1 } },
        { MODKEY,            XK_k,                     focusstack,       {.i = -1 } },
        { MODKEY,            XK_h,                     setmfact,         {.f = -0.05} },
        { MODKEY,            XK_l,                     setmfact,         {.f = +0.05} },
        { MODKEY,            XK_i,                     incnmaster,       {.i = +1 } },
        { MODKEY,            XK_d,                     incnmaster,       {.i = -1 } },
        { MODKEY,            XK_Tab,                   view,             {0} },
        { MODKEY,            XK_a,                     toggleopacity,    {0} },
        { MODKEY,            XK_q,                     killclient,       {0} },
        { MODKEY,            XK_t,                     setlayout,        {.v = &layouts[0]} },
        { MODKEY,            XK_f,                     setlayout,        {.v = &layouts[1]} },
        { MODKEY,            XK_m,                     setlayout,        {.v = &layouts[2]} },
        { MODKEY,            XK_space,                 setlayout,        {0} },
        { MODKEY,            XK_0,                     view,             {.ui = ~0 } },

        { MODKEY|ShiftMask,  XK_j,                     rotatestack,      {.i = +1 } },
        { MODKEY|ShiftMask,  XK_k,                     rotatestack,      {.i = -1 } },
        { MODKEY|ShiftMask,  XK_space,                 togglefloating,   {0} },
        { MODKEY|ShiftMask,  XK_0,                     tag,              {.ui = ~0 } },
        { MODKEY|ShiftMask,  XK_Return,                zoom,             {0} },
        { MODKEY|ShiftMask,  XK_r,                     quit,             {0} },

        { MODKEY2,           XK_Tab,                   shiftviewclients, {.i = +1} },
        { MODKEY2|ShiftMask, XK_Tab,                   shiftviewclients, {.i = -1} },
        TAGKEYS(             XK_1,                                       0)
        TAGKEYS(             XK_2,                                       1)
        TAGKEYS(             XK_3,                                       2)
        TAGKEYS(             XK_4,                                       3)
        TAGKEYS(             XK_5,                                       4)
        TAGKEYS(             XK_6,                                       5)
        TAGKEYS(             XK_7,                                       6)
        TAGKEYS(             XK_8,                                       7)
        TAGKEYS(             XK_9,                                       8)
};

/* extra keysyms
XF86XK_AudioPlay
XF86XK_AudioStop
XF86XK_AudioPrev
XF86XK_AudioNext
XF86XK_KbdLightOnOff
XF86XK_KbdBrightnessUp
*/

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
        /* click                event mask      button          function        argument */
        { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
        { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
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

