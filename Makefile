
all:	clean zombi

zombi:
	@echo -n '' # running zombi now.
	@gcc zombi.c
	@./a.out

# if a.out exists, rm it:

clean:
	@echo -n '' # running clean now.
	@if test -e a.out ; then rm ./a.out; fi

