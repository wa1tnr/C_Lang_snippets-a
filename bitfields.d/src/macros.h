/* macros.h */
/* Sun 19 Jan 19:18:49 UTC 2025 */

/* TOS is Top Of Stack */
#define TOS stack[p]

static const int STKSIZE = 8;
static const int STKMASK = 7;
static const byte pinMIN = '\002'; // for D2

// RAM:   [==        ]  16.1% (used 329 bytes from 2048 bytes)
// Flash: [=         ]  11.8% (used 3818 bytes from 32256 bytes)
