
all:	clean zombi

zombi:
	@echo -n '' # running zombi now.
	@gcc zombi.c
	@./a.out

tested_0:
	@echo "\t\ttesting 'gforth -e 'decimal 22 2 base ! . cr bye'"
	@echo -n "\t\t"
	@gforth -e 'decimal 22 2 base ! . cr bye'
	@echo "\t\ttesting 'gforth -e '2 base !  10110  dup . dup decimal . hex . cr bye'"
	@echo -n "\t\t"
	@gforth -e '2 base !  10110  dup . dup decimal . hex . cr bye'

t0:	tested_0

# if a.out exists, rm it:

clean:
	@echo -n '' # running clean now.
	@if test -e a.out ; then rm ./a.out; fi

