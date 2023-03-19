#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
servo BillGate = servo(Brain.ThreeWirePort.A);
motor OnlyMotor = motor(PORT9, ratio18_1, true);

optical AllSeeing = optical(PORT21);
servo FloodGate = servo(Brain.ThreeWirePort.B);
limit LimitSwitch = limit(Brain.ThreeWirePort.C);
#pragma endregion VEXcode Generated Robot Configuration

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Authors:       {Chris Morales, Vicken Semerdjian}                       */
/*    Created:      {March 2023}                                              */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

 void EyeBall(){ //sets light on the sensor to on and sets the power to 50%
   AllSeeing.setLight(ledState::on);
   AllSeeing.setLightPower(50,percent);
 }
int SortState = 0;
 void SortingStuff(){

    if (LimitSwitch.pressing()) {         //Metal Ball, if the ball is metal, it depresses the limit switch.
      BillGate.setPosition(-48,degrees); //opens the gate
     FloodGate.setPosition(10,degrees); //changes the sorting rail to the metal ball position
       SortState=1;
     wait(1,seconds);
  }
  
   else if((AllSeeing.hue()>41)&&(AllSeeing.hue()<58)){ //white ball (44), if the ball is white, it is between 41 and 58
     Brain.Screen.print(AllSeeing.hue()); //prints the hue to the screen
     BillGate.setPosition(-50,degrees); //opens the gate
   SortState=1;
     FloodGate.setPosition(50,degrees); //changes the sorting rail to the white ball position
   }
    else if((AllSeeing.hue()>28)&&(AllSeeing.hue()<40)){ //wood ball(32)
      Brain.Screen.print(AllSeeing.hue()); //prints the hue to the screen
     BillGate.setPosition(-50,degrees); //opens the gate
       SortState=1;
      FloodGate.setPosition(19,degrees); //changes the sorting rail to the wood ball position
   }
 }
   






 


     
int main() {
BillGate.setPosition(50,degrees); //sets the gate to closed
 OnlyMotor.setVelocity(1,percent); //sets the motor to 1% power
    OnlyMotor.spin(reverse); //makes the motor constantly spin at a low speed to only allow one ball through at once.
  while(1==1){
    EyeBall(); //turns on the sensor and light
      while(SortState==0){ //while the ball is not sorted
      SortingStuff(); //keeps checking to see if any of the sort conditions are met
     }
     SortState=0; //resets the sort state so that it can sort again
    wait(.5,seconds); //waits so the ball has time to be sorted so the sensor doesn't get confused or skip
    Brain.Screen.clearLine(1); //clears the screen so the hue doesn't get printed over and over
    BillGate.setPosition(50,degrees); //closes the gate
  }
}




