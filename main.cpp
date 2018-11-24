#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "WiimoteBtns.h"

using namespace std;

int main()
{
	WiimoteBtns x = WiimoteBtns();
	x.Listen();
//	x.ButtonEvent();
	x.~WiimoteBtns();
        
    	return 0;
}                      
