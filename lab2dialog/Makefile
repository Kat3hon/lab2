CC=g++ -std=c++20
CFLAGS=-c -Wall
LDFLAGS=

all: exe

exe: main.o dialog.o help.o
	$(CC) main.o dialog.o help.o -o exe

main.o: main.cpp archSpiral.h
	$(CC) $(CFLAGS) main.cpp

dialog.o: dialog.cpp archSpiral.h
	$(CC) $(CFLAGS) dialog.cpp

help.o: help.cpp archSpiral.h
	$(CC) $(CFLAGS) help.cpp

clean:
	rm -f *.o exe