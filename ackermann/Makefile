output: ackermann.c
	gcc -o Ackermann ackermann.c

ackermann.o: ackermann.c
	gcc -c ackermann.c

ackermann.s: ackermann.c
	gcc -S ackermann.c

clean:
	rm Ackermann *.o *.s
