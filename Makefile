tp1: tp1.o
	gcc -o tp1 tp1.o

tp1.o: tp1.c
	gcc -c tp1.c

.PHONY: clean

clean:	
		rm *.o
		rm tp1		
