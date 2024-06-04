
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

#  11010100
#  11010100

tested_1:
	@echo "\t\ttesting 'gforth -e 'char b emit 2 base !  11010100  dup . dup decimal . hex 24 emit . cr bye'"
	@echo -n "\t\t"
	@gforth -e 'char b emit 2 base !  11010100  dup . dup decimal . hex 24 emit . cr bye'

t1:	tested_1

# if a.out exists, rm it:

# find all tabs and remove them in the status, to help form .gitignore entries
git_status:
	@git status | cat | tr -d '\t'

clean:
	@echo -n '' # running clean now.
	@if test -e a.out ; then rm ./a.out; fi

