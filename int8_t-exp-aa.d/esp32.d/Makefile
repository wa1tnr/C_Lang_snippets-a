# Wed  5 Jun 17:47:11 UTC 2024

targettte:	clean compile_verbose
	@echo
	@date
	@echo
	@sha1sum ./CURRENT.d/esp32-ee.ino.bin
	@echo

all:

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
