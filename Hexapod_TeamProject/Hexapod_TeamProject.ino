/*
 * Hexapod_TeamProject.ino
 *
 * Created: 4/22/2018 9:01:43 PM
 * Author: Tomislav Romic
 */ 
#include "RobotControl.h"
RobotControl myRobot;
void setup(){
	Serial.begin(9600);
	//myRobot.myMovementController.moveAllLegsToHomePosWithLiftingLegs();
}

void loop(){
		myRobot.test_checkMegaState();
}