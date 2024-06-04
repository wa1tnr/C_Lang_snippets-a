
zombi:
	gcc zombi.c
	./a.out

# if a.out exists, rm it:

clean:
	@if test -e a.out ; then rm ./a.out; fi

