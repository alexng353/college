all: test1

test1: a3_superheroLookupSystem.c a3_superherolib.c
	gcc -Wall -std=c99 -o test1 a3_superheroLookupSystem.c a3_superherolib.c

run: a3_superheroLookupSystem.c a3_superherolib.c
	make test1 && ./test1

clean:
	rm -f test1
