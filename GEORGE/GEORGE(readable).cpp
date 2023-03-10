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
motor OnlyMotor = motor(PORT10, ratio18_1, true);

optical AllSeeing = optical(PORT21);
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

 void EyeBall(){
   AllSeeing.setLight(ledState::on);
   AllSeeing.setLightPower(75,percent);
   AllSeeing.hue();
 }
int SortState = 0;
 void SortingStuff(){
   if((AllSeeing.hue()>37)&&(AllSeeing.hue()<42)){        //Metal ball (41)
      Brain.Screen.print(AllSeeing.hue());
     BillGate.setPosition(-50,degrees);
     SortState=1;

   }
   else if((AllSeeing.hue()>42)&&(AllSeeing.hue()<45)){ //white ball (44)
      Brain.Screen.print(AllSeeing.hue());
     BillGate.setPosition(-50,degrees);
     SortState=1;
   }
    else if((AllSeeing.hue()>28)&&(AllSeeing.hue()<34)){ //wood ball(32)
      Brain.Screen.print(AllSeeing.hue());
      
     BillGate.setPosition(-50,degrees);
     SortState=1;
   }

  // else{
   //  SortState=0;
 //  }
 }
 

  void Turnstile(){
    
    OnlyMotor.spinFor(reverse,0.2,turns);

    wait(.5,seconds);
    OnlyMotor.stop();
  }
int main() {
BillGate.setPosition(50,degrees);
  while(1==1){
    EyeBall();
    SortState=0;
    while(SortState==0){
      Brain.Timer.reset();
      while(Brain.Timer.value()<2){ //this incriments the turnstile slowly so it doesnt accept many marbles at once
      SortingStuff(); 
           
      }
      Turnstile();  
        
    }
 
    wait(.5,seconds);
    Brain.Screen.clearLine(1);
    BillGate.setPosition(50,degrees);
}
}




