CC=g++ -std=c++14
CFLAGS=-c -Wall
LDFLAGS=

all: exe

exe: main.o dialog.o help.o class.o
	$(CC) main.o dialog.o help.o class.o -o exe

main.o: main.cpp archSpiral.h
	$(CC) $(CFLAGS) main.cpp

dialog.o: dialog.cpp archSpiral.h
	$(CC) $(CFLAGS) dialog.cpp

help.o: help.cpp archSpiral.h
	$(CC) $(CFLAGS) help.cpp

class.o: class.cpp archSpiral.h
	$(CC) $(CFLAGS) class.cpp

clean:
	rm -f *.o exe