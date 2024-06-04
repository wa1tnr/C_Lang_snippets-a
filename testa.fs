
: binary 2 base ! ;
binary
." 44 decimal is, in hex: " decimal 44 hex . cr
decimal
-44
4294967040 -
abs ( ? -- n )
binary
dup .  decimal
."  is: " dup .
4294967040 -
cr binary . cr

." 11111111111111111111111111010100  is: "
11111111111111111111111111010100 dup decimal . cr
dup hex . cr
dup binary . cr
." hex 0xD4 is: " hex D4 decimal . cr

bye 
