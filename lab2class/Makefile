CC=g++ -std=c++20
CFLAGS=-c -Wall
LDFLAGS=

libarchspiral.a: dialog.o help.o
	ar cr libarchspiral.a dialog.o help.o archSpiral.h

dialog.o: dialog.cpp archSpiral.h
	$(CC) $(CFLAGS) dialog.cpp

help.o: help.cpp archSpiral.h
	$(CC) $(CFLAGS) help.cpp

clean:
	rm -f *.o *.a exe