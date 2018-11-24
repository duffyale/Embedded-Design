#Button Makefile 

main: main.o WiimoteBtns.o 
	g++ main.o WiimoteBtns.o -o main

main.o: main.cpp WiimoteBtns.h
	g++ -g -Wall -c main.cpp

WiimoteBtns.o: WiimoteBtns.cpp WiimoteBtns.h
	g++ -g -Wall -c WiimoteBtns.cpp

clean: 
	rm main.o WiimoteBtns.o main
