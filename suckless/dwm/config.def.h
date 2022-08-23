/* See LICENSE file for copyright and license details. */

/* include keysyms for volume keys */
#include <X11/XF86keysym.h>
#include "tatami.c"

/* appearance */
static const unsigned int borderpx       = 0;      /* border pixel of windows */
static const unsigned int gappx          = 8;      /* gaps between windows */
static const unsigned int snap           = 32;     /* snap pixel */
static const int swallowfloating         = 0;      /* 1 means swallow floating windows by default */
static const int showbar                 = 1;      /* 0 means no bar */
static const int topbar                  = 1;      /* 0 means bottom bar */
static const double activeopacity        = 1.0f;   /* Window opacity when it's focused (0 <= opacity <= 1) */
static const double inactiveopacity      = 0.925f; /* Window opacity when it's inactive (0 <= opacity <= 1) */
static Bool bUseOpacity                  = True;   /* Starts with opacity on any unfocused windows */
static const int user_bh                 = 6;      /* 2 is the default spacing around the bar's font */
 
/* https://aur.archlinux.org/packages/nerd-fonts-cozette-ttf */
static const char *fonts[]               = { "CozetteVector Nerd Font:size=16" };
static const char dmenufont[]            = "CozetteVector Nerd Font:size=16";

/* Rosé Pine https://rosepinetheme.com/palette */
static const char col_base[]            = "#191724";
static const char col_surface[]         = "#1f1d2e";
static const char col_rose[]            = "#ebbcba";
static const char col_foam[]            = "#9ccfd8";
static const char *colors[][3]          = {
  /*               fg         bg         border   */
  [SchemeNorm] = { col_rose, col_base, col_surface },
  [SchemeSel]  = { col_foam, col_base,  col_base  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
  /* xprop(1):
   *  WM_CLASS(STRING) = instance, class
   *  WM_NAME(STRING) = title
   */
  /* class             instance     title           tags mask  switchtotag  isfloating  isterminal  noswallow  monitor  notallowed */
  { "Gimp",            NULL,        NULL,           0,         1,           1,          0,          0,          -1,     0 },
  { "st",              NULL,        NULL,           1,         1,           0,          1,          0,          -1,     0 },
  { "librewolf",       "Navigator", NULL,           1 << 1,    1,           0,          0,          0,          -1,     0 },
  { "MuseScore3",      "musescore", NULL,           1 << 8,    1,           0,          0,          0,          -1,     0 },
  { NULL,              NULL,        "Event Tester", 0,         0,           0,          0,          1,          -1,     0 },

  { "Signal",          NULL,        NULL,           1 << 6,    0,           0,          0,          0,          -1,     0 },
  { "TelegramDesktop", NULL,        NULL,           1 << 6,    0,           0,          0,          0,          -1,     0 },

  { "Anki",            "anki",      NULL,           1 << 7,    1,           0,          0,          0,          -1,     0 },
  { "Anki",            "anki",      "Browse",       1 << 7,    1,           1,          0,          0,          -1,     0 },
  { "Anki",            "anki",      "Add-ons",      1 << 7,    1,           1,          0,          0,          -1,     0 },

  { "Steam",           "Steam",     "Steam",        1 << 5,    1,           1,          0,          0,          -1,     0 },
};

/* layout(s) */
static const float mfact          = 0.55; /* factor of master area size [0.05..0.95] */
static const int   nmaster        = 1;    /* number of clients in master area */
static const int   resizehints    = 0;    /* 1 means respect size hints in tiled resizals */
static const int   lockfullscreen = 1;    /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "|+|",      tatami  }, /* first entry is default */
  { "[F]",      NULL    }, /* no layout function means floating behavior */
  { "[M]",      monocle },
  /* { "[T]",      tile    }, */
};

/* key definitions */
#define MODKEY  Mod4Mask
#define MODKEY2 Mod1Mask
#define TERMMOD ControlMask|ShiftMask
#define TAGKEYS(KEY,TAG) \
  { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
  { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */

/* custom commands */
/* apps */
static const char *dmenucmd[]          = { "dmenu_run",
                                            "-m",  dmenumon,
                                            "-fn", dmenufont,
                                            "-nb", col_base,
                                            "-nf", col_rose,
                                            "-sb", col_base,
                                            "-sf", col_foam,
                                            NULL };

static const char *termcmd[]           = { "/usr/local/bin/st",  NULL };
static const char *browsercmd[]        = { "/usr/bin/librewolf", NULL };
/* volume */
static const char *volmutetogglecmd[]  = { "vol.sh", "mute", NULL };
static const char *voldowncmd[]        = { "vol.sh", "down", NULL };
static const char *volupcmd[]          = { "vol.sh", "up",   NULL };
/* screen */
static const char *brightnessupcmd[]   = { "brightness.sh", "up",   NULL };
static const char *brightnessdowncmd[] = { "brightness.sh", "down", NULL };
static const char *screenclipcmd[]     = { "screenshot.sh", "clip", NULL };
static const char *screensavecmd[]     = { "screenshot.sh", "save", NULL };
static const char *screenopencmd[]     = { "screenshot.sh", "open", NULL };
/* zoom / magnify */
static const char *crosshaircmd[]      = { "/usr/bin/slop", "-r", "crosshair", NULL };
static const char *boxzoomcmd[]        = { "/usr/bin/slop", "-r", "boxzoom",   NULL };
/* power */
static const char *shutdowncmd[]       = { "systemctl", "poweroff", NULL };
static const char *rebootcmd[]         = { "systemctl", "reboot",   NULL };
/* rofi */
static const char *passcmd[]           = { "rofi-rbw", NULL };
static const char *roficmd[]           = { "rofi", "-show", "combi", "-modes", "combi", "-combi-modes", "window,drun,run", NULL };

static Key keys[] = {
  /* modifier                     key                       function          argument */
  /* custom scripts' bindings */
  { 0,                            XK_Print,                 spawn,            {.v = screenclipcmd     } },
  { 0|ShiftMask,                  XK_Print,                 spawn,            {.v = screensavecmd     } },
  { MODKEY|ShiftMask,             XK_Print,                 spawn,            {.v = screenopencmd     } },
  { 0,                            XF86XK_AudioMute,         spawn,            {.v = volmutetogglecmd  } },
  { 0,                            XF86XK_AudioLowerVolume,  spawn,            {.v = voldowncmd        } },
  { 0,                            XF86XK_AudioRaiseVolume,  spawn,            {.v = volupcmd          } },
  { 0,                            XF86XK_MonBrightnessUp,   spawn,            {.v = brightnessupcmd   } },
  { 0,                            XF86XK_MonBrightnessDown, spawn,            {.v = brightnessdowncmd } },
  { MODKEY,                       XK_z,                     spawn,            {.v = crosshaircmd      } },
  { MODKEY|ShiftMask,             XK_z,                     spawn,            {.v = boxzoomcmd        } },
  { MODKEY|ShiftMask,             XK_b,                     spawn,            {.v = browsercmd        } },
  { TERMMOD,                      XK_9,                     spawn,            {.v = passcmd           } },
  { TERMMOD,                      XK_p,                     spawn,            {.v = roficmd           } },
  { TERMMOD,                      XK_BackSpace,             spawn,            {.v = rebootcmd         } },
  { TERMMOD,                      XK_Delete,                spawn,            {.v = shutdowncmd       } },
  /* end of custom scripts' bindings */

  { MODKEY,                       XK_p,                     spawn,            {.v = dmenucmd } },
  { TERMMOD,                      XK_Return,                spawn,            {.v = termcmd } },
  { MODKEY|ControlMask,           XK_space,                 focusmaster,      {0} },
  { MODKEY,                       XK_b,                     togglebar,        {0} },
  { MODKEY,                       XK_j,                     focusstack,       {.i = +1 } },
  { MODKEY,                       XK_k,                     focusstack,       {.i = -1 } },
  { MODKEY|ShiftMask,             XK_j,                     rotatestack,      {.i = +1 } },
  { MODKEY|ShiftMask,             XK_k,                     rotatestack,      {.i = -1 } },
  { MODKEY,                       XK_h,                     setmfact,         {.f = -0.05} },
  { MODKEY,                       XK_l,                     setmfact,         {.f = +0.05} },
  { MODKEY,                       XK_i,                     incnmaster,       {.i = +1 } },
  { MODKEY,                       XK_d,                     incnmaster,       {.i = -1 } },
  { MODKEY,                       XK_Return,                zoom,             {0} },
  { MODKEY,                       XK_Tab,                   view,             {0} },
  { MODKEY2,                      XK_Tab,                   shiftviewclients, {.i = +1} },
  { MODKEY2|ShiftMask,            XK_Tab,                   shiftviewclients, {.i = -1} },
  { MODKEY,                       XK_a,                     toggleopacity,    {0} },
  { MODKEY,                       XK_q,                     killclient,       {0} },
  { MODKEY,                       XK_t,                     setlayout,        {.v = &layouts[0]} },
  { MODKEY,                       XK_f,                     setlayout,        {.v = &layouts[1]} },
  { MODKEY,                       XK_m,                     setlayout,        {.v = &layouts[2]} },
  { MODKEY,                       XK_space,                 setlayout,        {0} },
  { MODKEY|ShiftMask,             XK_space,                 togglefloating,   {0} },
  { MODKEY,                       XK_0,                     view,             {.ui = ~0 } },
  { MODKEY|ShiftMask,             XK_0,                     tag,              {.ui = ~0 } },
  { MODKEY,                       XK_minus,                 setgaps,          {.i = -1 } },
  { MODKEY,                       XK_equal,                 setgaps,          {.i = +1 } },
  { MODKEY|ShiftMask,             XK_equal,                 setgaps,          {.i = 0  } },
  TAGKEYS(                        XK_1,                                       0)
  TAGKEYS(                        XK_2,                                       1)
  TAGKEYS(                        XK_3,                                       2)
  TAGKEYS(                        XK_4,                                       3)
  TAGKEYS(                        XK_5,                                       4)
  TAGKEYS(                        XK_6,                                       5)
  TAGKEYS(                        XK_7,                                       6)
  TAGKEYS(                        XK_8,                                       7)
  TAGKEYS(                        XK_9,                                       8)
  { MODKEY|ShiftMask,             XK_r,                     quit,             {0} }, /* "Reload" */
};

/* extra keysyms to be mapped?
XF86XK_AudioPlay
XF86XK_AudioStop
XF86XK_AudioPrev
XF86XK_AudioNext
XF86XK_MonBrightnessUp
XF86XK_MonBrightnessDown
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

