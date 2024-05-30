CC = gcc
all : grafos

%.o : %.c %.h
	$(CC) -c $^

grafos : grafos.o main.o
	$(CC) -o $@ $^

clean: 
	del *.o grafos.exe grafos.h.gch
