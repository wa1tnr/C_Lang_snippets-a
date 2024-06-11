# Tue 11 Jun 17:20:25 UTC 2024
# was: Wed  5 Jun 17:47:11 UTC 2024

# all: terse

all: verbose

.PHONY: all

verbose:	clean compile_verbose
	@sha1sum ./CURRENT.d/esp32-ee.ino.bin

terse:	clean compile_only
	@sha1sum ./CURRENT.d/esp32-ee.ino.bin

install:
	@./upload.sh

compile_verbose:
	@echo COMPILE VERBOSE
	@./compile_verbose.sh

compile_only:
	@echo COMPILE ONLY
	@./compile.sh

board:
	@arduino-cli board listall

comm:
	./cf-fastpico9t-esp32-vsc.sh /dev/ttyACM0

clean:
	rm -rf /tmp/arduino/cores ; rm -rf /tmp/arduino/sketches

# end.
