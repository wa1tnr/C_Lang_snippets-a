// empty .ino file

/* quitting time: Wed  5 Jun 04:45:19 UTC 2024 */

/* Fred Flintstone 5 pm work-gets-out whistle just blew */

/* yabba dabba doo! */



/* needs simplfication so that massive redundant code disappears from the human eye. */

/* cpp macros are being considered as a quick fix there. ;) */

#if 0
#define print_faked() \
  print_me(); \
  buf_ptr =(char *) &buffer; \
  pushed = (int) buf_ptr; \
  push(pushed - POFFSET); \
  rdumps(); \
  tossed = pop(); \
  if (tossed == -715) Serial.println("NEVER");
#endif
