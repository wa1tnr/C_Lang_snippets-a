
all:	clean zombi
zombi:
	@echo; ls -la; echo
	@gcc zombi.c
	@./a.out

# if a.out exists, rm it:

clean:
	@if test -e a.out ; then rm ./a.out; fi

