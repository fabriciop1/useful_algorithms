all: hash.exe

hash.exe: hash.o linkedList.o main.o
	gcc hash.o linkedList.o main.o -o hash.exe -lm

main.o: main.c
	gcc -c main.c -o main.o

linkedList.o: linkedList.c list.h
	gcc -c linkedList.c -o linkedList.o


clean:
	-rm -f *.o
	-rm -f hash.exe
