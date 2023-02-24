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
motor Bottom = motor(PORT20, ratio18_1, false);

motor foreArm = motor(PORT21, ratio18_1, false);

servo Hand = servo(Brain.ThreeWirePort.A);
controller Controller1 = controller(primary);



// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
#pragma endregion VEXcode Generated Robot Configuration

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       {author}                                                  */
/*    Created:      {date}                                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;
void Walter (){
 if(Controller1.ButtonUp.pressing()){
    foreArm.spin(forward);
  }
  else if(Controller1.ButtonDown.pressing()){
    foreArm.spin(reverse);
  }
  else if(!Controller1.ButtonUp.pressing()){
    foreArm.setStopping(hold);
  }
  else{
    foreArm.stop();
  }
}

void Hubert (){
  if (Controller1.ButtonL1.pressing()){
    Bottom.spin(forward);
  }
  if(!Controller1.ButtonL1.pressing()){
    Bottom.setStopping(hold);
  }
  else if(Controller1.ButtonL2.pressing()){
    Bottom.spin(reverse);
  }
  else if(!Controller1.ButtonL2.pressing()){ 
    Bottom.setStopping(hold);
  }

}

void Stuart (){
  if (Controller1.ButtonA.pressing()){
    Hand.setPosition(-25,degrees);
  }
  else if(Controller1.ButtonY.pressing()){
    Hand.setPosition(25,degrees);
  }

}

int main() {
  foreArm.setVelocity(10,percent);
   Bottom.setVelocity(15,percent);
while (1==1){
 Walter();
 Hubert();
 Stuart();
}
}
