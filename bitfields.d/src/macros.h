/* macros.h */
/* Sun 19 Jan 16:43:22 UTC 2025 */

/* TOS is Top Of Stack */
#define TOS stack[p]

// upstream:
// stack.cpp:19:int STKMASK = 7;

static const int STKSIZE = 8;
static const int STKMASK = 7; // why doesn't this have to have a value?

// static const int STKMASK; // why doesn't this have to have a value?
                             // try without look for runtime error

// although for some reason it does compile 'cleanly'
// the program fails unmistakably - stack is in a
// disarray.  STMASK (as is obvious) needs to be set
// somewhere, but, if not set, the program will run
// to the extent that it can.

// summary: set it.

// RAM:   [==        ]  16.1% (used 329 bytes from 2048 bytes)
// Flash: [=         ]  11.5% (used 3700 bytes from 32256 bytes)
