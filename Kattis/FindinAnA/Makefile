GS=-std=c99 -Wpedantic -g -Og

output: a.o
	gcc a.o -o output

a.o: a.c
	gcc -c a.c

a.s: a.c
	gcc -S a.c
clean:
	rm *.o *.s output
