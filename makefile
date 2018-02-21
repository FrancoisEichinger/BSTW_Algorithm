run: bstw

bstw.o : bstw.c
	gcc -Wall -std=c99 -c bstw.c -lm

utils.o : utils.c utils.h
	gcc -Wall -std=c99 -c utils.c -lm

bstw: utils.o bstw.o
	gcc utils.o bstw.o -o bstw -lm

clean :
	rm *.o bstw
	# All .o files have been removed.
