#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <mutex>
#include <ctime>
#include <thread>
#include "robot-config.h"

using namespace std;

const float fullCircle = 360; 
const float fullRotation = 31.4;

using namespace std;

void newForward(float distance, float time1);
void newArmRotationLogic(float degrees, float timeSeconds);

void forward(double seconds, double meters);
void degrees(double deg, int direction);

void arm(double seconds, double meters);
void arminv(double seconds, double meters);

    
void openClaw();
void closeClaw();

int main(){


}

void degrees(double deg, int direction){

    

    int right;

    int left;

    

    //if direction = 1 it will turn right

    //else it will turn left

    

    if(direction == 1){

        right = 100;

        left = 50;

    }

    if(direction == 0){

        Motor1.setReversed(true);

        Motor2.setReversed(true);

        right = 50;

        left = 100;

    }

    

    Motor1.setVelocity(right,velocityUnits::rpm);

    Motor2.setVelocity(left,velocityUnits::rpm);

   

    //Motor1.setReversed(false);

    

    Motor1.spin(directionType::fwd);

    Motor2.spin(directionType::fwd);

    

    task::sleep((2500/360)*deg);

    

    Motor1.stop();

    Motor2.stop();

    

    

    Motor1.setReversed(false);

    Motor2.setReversed(false);

    

    

}


void forward(double seconds, double meters, bool metersEqualsSpeed =false){

    if(metersEqualsSpeed){

        double RPM = meters / 31.4;

    }
    else
    {
        double RPM = meters/seconds * 6000 / 31.4;
    }    

    Motor1.setVelocity(RPM,velocityUnits::rpm);

    Motor2.setVelocity(RPM,velocityUnits::rpm);

    Motor1.setReversed(true);

    

    Motor1.spin(directionType::fwd);

    Motor2.spin(directionType::fwd);

    

    task::sleep(seconds * 1000);


}


void arm(double seconds, double meters){

    double RPM = meters/seconds * 6000 / 31.4;

    Arm.setVelocity(RPM,velocityUnits::rpm);
    Arm.setReversed(false);
    Arm.spin(directionType::fwd);

    

    task::sleep(seconds * 1000);


   


 }


void arminv(double seconds, double meters){

    

    double RPM = meters/seconds * 6000 / 31.4;

    

    Arm.setVelocity(RPM,velocityUnits::rpm);

   

    Arm.setReversed(true);

    

    Arm.spin(directionType::fwd);

    

    task::sleep(seconds * 1000);


   


 

}





void turnRight(){

    

    Motor1.setVelocity(50,velocityUnits::rpm);

    Motor2.setVelocity(100,velocityUnits::rpm);

   

    Motor1.setReversed(false);

    

    Motor1.spin(directionType::fwd);

    Motor2.spin(directionType::fwd);

     task::sleep(600);

    

    Motor1.stop();

    Motor2.stop();

    

    task::sleep(600);

    

    Motor1.setReversed(false);

    Motor2.setReversed(false);

 

}


void turnLeft(){

    

    Motor1.setVelocity(100,velocityUnits::rpm);

    Motor2.setVelocity(50,velocityUnits::rpm);

    

    Motor1.spin(directionType::fwd);

    Motor2.spin(directionType::fwd);

    

    task::sleep(600);

    

    Motor1.stop();

    Motor2.stop();

    

    Motor1.setReversed(false);

    Motor2.setReversed(false);

 

}


void openClaw(){

    Claw.setVelocity(100,velocityUnits::rpm);

    Claw.setReversed(true);

    Claw.spin(directionType::fwd);

    

    task::sleep(1600);

    

   

 

}


void closeClaw(){

    Claw.setVelocity(100,velocityUnits::rpm);

    Claw.setReversed(false);

    Claw.spin(directionType::fwd);

    

    task::sleep(1600);

    

    Claw.stop();

 

}

void newArmRotationLogic(float degrees, float timeSeconds){

    float rotation = (fullRotation / fullCircle) * degrees;

    cout << "degrees " << degrees << " for " << 1 << " second :: is equal to " << rotation << " rotations";


}

