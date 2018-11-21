#include "GPIO.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

const string names[] = {"Base","Bicep","Elbow","Wrist","Gripper"};
const int servos[] = {13,10,11,12,0};

//calculate duty cycle
int degreeToDelay(int deg){
	int cycle = (deg+60)*10;
	return cycle;
}

//main function inlcuding user interface
int main()
{
	int servo, start, end, speed;
    //ask user for servo number
	cout << "Enter Servo number: ";
	cin >> servo;
    //ask user for start angle of the arm
	cout << "Enter Start Angle: ";
	cin >> start;
    //ask user for end angle of the arm
	cout << "Enter End Angle: ";
	cin >> end;
    //ask the user for the desire speed
	cout << "Enter Speed: ";
	cin >> speed;
    //make suer servo input is within the valid value
	if(servo > 5 || servo < 0){
		 return 1;
	}
	int begin =	degreeToDelay(start);
	int finish = degreeToDelay(end);

	GPIO gpio(servos[servo]);
	gpio.GeneratePWM(20000, begin, 100);

	int speed2 = ((abs(end-start)/speed) * 100)/20;
	gpio.GenerateVariablePWM(20000, begin, finish, speed2);
	gpio.GeneratePWM(20000, finish, 100);

	return 0;
}
