
all:	clean zombi

zombi:
	@echo -n '' # running zombi now.
	@gcc zombi.c
	@./a.out

tested_0:
	@echo "\t\ttesting 'gforth -e 'char b emit 2 base !  10110  dup . dup decimal . hex 24 emit . cr bye'"
	@echo -n "\t\t"
	@gforth -e 'char b emit 2 base !  10110  dup . dup decimal . hex 24 emit . cr bye'

t0:	tested_0

# if a.out exists, rm it:

clean:
	@echo -n '' # running clean now.
	@if test -e a.out ; then rm ./a.out; fi

