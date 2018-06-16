/* 
* Leg.h
*
* Created: 22.04.2018 21:07:09
* Author: Tomislav Romic
*/


#ifndef __LEG_H__
#define __LEG_H__

#include "Servo.h"
#include "AX12A.h"

/*Default values. Can be set later. Are evaluated for Botolomäus*/
#define def_homePositionBodyServo 150
#define def_homePositionMiddleServo 84.8
#define def_homePositionLowerServo 53.6
#define def_speed 150

#define positionKnown 1
#define positionUnknown 2


/*   

Rough structure of the hexapod to understand the naming of the three servos on one leg. 

         (LeftLeg)                      <Hexapod>                        (RightLeg)	

							/////######################\\\\\		
	   _____________	 BodyServo				     BodyServo          _____________
	   LowerLegServo	  /////#########################\\\\\		    LowerLegServo
	 /////      \\\\\    /////							 \\\\\		  /////      \\\\\
	/////		 \\\\\  /////							  \\\\\		 /////		  \\\\\
   /////		MiddleLegServo		     				MiddleLegServo		       \\\\\
____\/______________________________________Ground___________________________________\/______
															 
*/

class Leg
{
//variables
public:
	AX12A* m_pConnectedBus;

	Servo m_bodyServo;
	Servo m_middleServo;
	Servo m_lowerServo;

//functions
public:
	Leg(AX12A& m_pConnectedBus, unsigned char ID_bodyServo, unsigned char ID_middleLegServo, unsigned char ID_lowerLegServo);
	unsigned char move2HomePosition();
	unsigned char moveBodyServoToHomePos();
	unsigned char liftLeg();
	unsigned char lowerLeg();
	
	unsigned char moveLegToKnownPosition(float angleBody, float angleMiddle, float angleLower);
	unsigned char registerDesiredPositionAndSpeed(float angleBody, float angleMiddle, float angleLower, float speed);
	unsigned char registerDesiredPosition(float angleBody, float angleMiddle, float angleLower);
	unsigned char moveLegToRegisteredPosition();
	unsigned char setBodyServoAngle(float angle);
	unsigned char setMiddleServoAngle(float angle);
	unsigned char setLowerServoAngle(float angle);
	unsigned char setMaxAngles(float maxAngleBody,float maxAngleMiddle,float maxAngleLower);
	unsigned char setMinAngles(float minAngleBody,float minAngleMiddle,float minAngleLower);
	
	float getCurrentAngles(float& bodyAngle, float& middleAngle, float& lowerAngle);
	bool getMovingStatus();

	~Leg();
private:
	unsigned char setpkX(float val);
	unsigned char setpkY(float val);
	unsigned char setpkZ(float val);

	unsigned char getpkX(float val);
	unsigned char getpkY(float val);
	unsigned char getpkZ(float val);
	


}; //Leg

#endif //__LEG_H__
