CFLAG=-Wall #-Wshadow                                            
nomePrograma=trab

all: main.o ordenacao.o
	gcc $(CFLAG) main.o ordenacao.o -o $(nomePrograma)

main.o: main.c
	gcc $(CFLAG) -c main.c

ordenacao.o: ordenacao.h ordenacao.c
	gcc $(CFLAG) -c ordenacao.c 

clean:
	rm -f *.o *.gch $(nomePrograma)