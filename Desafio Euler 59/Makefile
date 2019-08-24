CC = gcc
CFLAGS  = -g -Wall -ansi -pedantic

default: Euler_59

Euler_59:  Euler_59.o cripto.o
	$(CC) $(CFLAGS) -o Euler_59 Euler_59.o cripto.o -lm

Euler_59.o:  Euler_59.c cripto.h
	$(CC) $(CFLAGS) -c Euler_59.c

cripto.o:  cripto.c cripto.h 
	$(CC) $(CFLAGS) -c cripto.c -lm

teste_cripto:	teste_cripto.o cripto.o
	$(CC) $(CFLAGS) -o teste_cripto teste_cripto.o cripto.o -lm

teste_cripto.o:  teste_cripto.c cripto.h
	$(CC) $(CFLAGS) -c teste_cripto.c -lm

clean: 
	$(RM) Euler_59 *.o *~
