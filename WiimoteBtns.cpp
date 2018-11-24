#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "WiimoteBtns.h"

	WiimoteBtns::WiimoteBtns(){
	fd = open("/dev/input/event2", O_RDONLY);
	if (fd == -1)
	{
  	std::cerr << "Error: Could not open event file - forgot sudo?\n";
  	exit(1);
   	}
	}

	WiimoteBtns::~WiimoteBtns(){
	close(fd);// Close Wiimote event file 
	}
	
	void WiimoteBtns::ButtonEvent(int code, int value){

           // Print them
        std::cout << "Code = " << code << ", value = " << value << '\n';
        }


        void WiimoteBtns::Listen(){
	char buffer[32]; // Read a packet of 32 bytes from Wiimote
	while (true){
	read(fd, buffer, 32);
        // Extract code (byte 10) and value (byte 12) from packet
        WiimoteBtns::code = buffer[10];
        WiimoteBtns::value = buffer[12];
	ButtonEvent(code, value);
	}
	}

	    
