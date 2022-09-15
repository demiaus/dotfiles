/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;
static int fuzzy  = 1;
static const char *fonts[] = { "CozetteVector Nerd Font:size=14" };
static const char *prompt = NULL;
static const char *colors[SchemeLast][2] = {
	/* Rosé Pine https://rosepinetheme.com/palette */
	/*                         fg         bg       */
	[SchemeNorm]          = { "#ebbcba", "#26233a" }, /* rose, overlay  */
	[SchemeSel]           = { "#9ccfd8", "#26233a" }, /* foam, base     */
	[SchemeSelHighlight]  = { "#9ccfd8", "#6e6a86" }, /* foam, muted    */
	[SchemeNormHighlight] = { "#ebbcba", "#6e6a86" }, /* rose, muted    */
	[SchemeOut]           = { "#191724", "#9ccfd8" }, /* base, foam     */
};
static unsigned int lines          = 0;
static unsigned int lineheight     = 48;
static unsigned int min_lineheight = 8;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = "/[]{}()\"\'  ";
