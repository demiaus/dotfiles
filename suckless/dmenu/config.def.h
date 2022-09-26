/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom */
static int fuzzy  = 1;                      /* -F  option; if 0, dmenu doesn't use fuzzy matching */
static const unsigned int alpha6 = 0x60;
static const unsigned int alpha8 = 0x80;
static const unsigned int alphaf = 0xf0;
static const char *prompt = NULL;
static const char *fonts[] = { "CozetteVector Nerd Font:size=14" };
static const char *colors[SchemeLast][2] = {
	/* Rosé Pine https://rosepinetheme.com/palette */
	/*                         fg         bg       */
	[SchemeNorm]          = { "#ebbcba", "#191724" }, /* rose, base */
	[SchemeSel]           = { "#9ccfd8", "#191724" }, /* foam, overlay */
	[SchemeSelHighlight]  = { "#9ccfd8", "#191724" }, /* foam, muted */
	[SchemeNormHighlight] = { "#ebbcba", "#191724" }, /* rose, muted */
};

static const unsigned int alphas[SchemeLast][2] = {
	[SchemeNorm]          = { OPAQUE, alphaf },
	[SchemeSel]           = { OPAQUE, alphaf },
	[SchemeSelHighlight]  = { OPAQUE, OPAQUE },
	[SchemeNormHighlight] = { OPAQUE, OPAQUE },
};

static unsigned int lines          = 0;
static unsigned int lineheight     = 48;
static unsigned int min_lineheight = 8;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = "/[]{}()\"\'  ";

