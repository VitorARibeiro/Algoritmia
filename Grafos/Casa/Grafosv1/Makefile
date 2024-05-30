CC = gcc
all : grafos

%.o : %.c %.h
	$(CC) -c $^

grafos : grafos.o main.o
	$(CC) -o $@ $^

clean: 
	rm -f *.o grafos
