# Arm program Makefile 

Run: ServoSpeed.o GPIO.o
	g++ ServoSpeed.o GPIO.o -o run	

ServoSpeed.o: ServoSpeed.cpp GPIO.h
	g++ -g -Wall -c ServoSpeed.cpp
	g++ -g -Wall -c GPIO.cpp

GPIO.o: GPIO.cpp GPIO.h
	g++ -g -Wall -c GPIO.cpp

clean:
	rm ServoSpeed.o GPIO.o run
