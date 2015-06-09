all: hash.exe

hash.exe: hash.o main.o
	gcc hash.o main.o -o hash.exe

main.o: main.c
	gcc -c main.c -o main.o


clean:
	-rm -f *.o
	-rm -f hash.exe
