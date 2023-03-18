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
/*    Author:       {Chris Morales, Vicken Semerdjian}                        */
/*    Created:      {March 2023}                                              */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

 void EyeBall(){
   AllSeeing.setLight(ledState::on);
   AllSeeing.setLightPower(50,percent);
 }
int SortState = 0;
 void SortingStuff(){

    if (LimitSwitch.pressing()) {         //Metal Ball
      BillGate.setPosition(-48,degrees);
     FloodGate.setPosition(10,degrees);
       SortState=1;
     wait(1,seconds);
  }
  
   else if((AllSeeing.hue()>41)&&(AllSeeing.hue()<58)){ //white ball (44)
     Brain.Screen.print(AllSeeing.hue());
     BillGate.setPosition(-50,degrees);
   SortState=1;
     FloodGate.setPosition(50,degrees);
   }
    else if((AllSeeing.hue()>28)&&(AllSeeing.hue()<40)){ //wood ball(32)
      Brain.Screen.print(AllSeeing.hue());
     BillGate.setPosition(-50,degrees);
       SortState=1;
      FloodGate.setPosition(19,degrees);
   }
 }
   






 


     
int main() {
BillGate.setPosition(50,degrees);
 OnlyMotor.setVelocity(1,percent);
    OnlyMotor.spin(reverse);
  while(1==1){
    EyeBall();
      while(SortState==0){
      SortingStuff(); 
     }
     SortState=0;
    wait(.5,seconds);
    Brain.Screen.clearLine(1);
    BillGate.setPosition(50,degrees);
  }
}




