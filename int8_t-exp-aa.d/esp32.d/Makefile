# Wed  5 Jun 17:47:11 UTC 2024

all: targettte
	@echo targettt is being made - has clean and compile_verbose
	@echo;date;sleep 3;date;echo

.PHONY: all

targettte:	clean compile_verbose
	@echo
	@date
	@echo
	@sha1sum ./CURRENT.d/esp32-ee.ino.bin
	@echo

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
