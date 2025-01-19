/* macros.h */
/* Sun 19 Jan 19:33:41 UTC 2025 */

/* TOS is Top Of Stack */
#define TOS stack[p]

static const int STKSIZE = 8;
static const int STKMASK = 7;

static const char pinMAX = '\011'; // for D9
static const char pinMIN = '\002'; // for D2

// RAM:   [==        ]  16.1% (used 329 bytes from 2048 bytes)
// Flash: [=         ]  11.8% (used 3810 bytes from 32256 bytes)
