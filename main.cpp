/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Tue Mar 16 2021                                           */
/*    Description:  Arm Manual Movement                                       */
/*                                                                            */
/*    This example will continuously display the current                      */
/*    position of the arm on the V5 Brain's screen and allow you              */
/*    to manually move the arm around                                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/


// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// RoboticArm1          RoboticArm    1, 2, 3, 4, 1, 2, 3, 4
// EStop                bumper        E              
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"


using namespace vex;


// function to run when the emergency stop button is pressed
void onEStopPressed() {
 RoboticArm1.emergencyStop();
}


int main() {
 // Initializing Robot Configuration. DO NOT REMOVE!
 vexcodeInit();


   // register emergency stop event handler
 EStop.pressed(onEStopPressed);


 // short wait to make sure the emergency stop event is fully registered
 wait(15, msec);


 double x;
 double y;
 double z;




 RoboticArm1.setMasteringValues(1946, 2002, 1997, 445);
 RoboticArm1.setToolTipOffset(0.0, 0.0, 0.0);
 RoboticArm1.setLinearMoveSpeed(10);
 //(5.5,-4,3.594)
 //V
 x = RoboticArm1.getAxisPosition(xaxis);
 y = RoboticArm1.getAxisPosition(yaxis);
 z = RoboticArm1.getAxisPosition(zaxis);
 Brain.Screen.print(x);
 Brain.Screen.print(y);
 Brain.Screen.print(z);
 RoboticArm1.setRelativePosition(x, y, z);
 RoboticArm1.moveToPositionLinear(4,-5.06,3);
 wait(3,sec);
 RoboticArm1.moveToPositionLinear(6.5,-4,3);
 wait(1,sec);
 RoboticArm1.moveToPositionJoint(4,-5.06,3);
 wait(1,sec);
 RoboticArm1.enableManualMovement();


 // display the position on the screen constantly
 Brain.Screen.setFont(mono60);
  while (true) {
   Brain.Screen.clearScreen();


   // Display the X position on row 1
   Brain.Screen.setCursor(1, 1);
   Brain.Screen.print("Arm X: %0.3f", RoboticArm1.getAxisPosition(xaxis));


   // Display the Y position on row 2
   Brain.Screen.newLine();
   Brain.Screen.print("Arm Y: %0.3f", RoboticArm1.getAxisPosition(yaxis));


   // Display the Z position on row 3
   Brain.Screen.newLine();
   Brain.Screen.print("Arm Z: %0.3f", RoboticArm1.getAxisPosition(zaxis));


   wait(0.2, seconds);
 }
}
