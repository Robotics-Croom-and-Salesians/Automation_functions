#include "vex.h"

using namespace vex;

vex::brain Brain;

vex::motor LeftMotor = vex::motor( vex::PORT1 );
vex::motor LeftMotor2 = vex::motor( vex::PORT2 );
vex::motor RightMotor = vex::motor( vex::PORT10, true );
vex::motor RightMotor2 = vex::motor( vex::PORT9, true );

vex::motor BallShooter = vex::motor(vex::PORT16);
vex::motor BallShooterAngle = vex::motor(vex::PORT17);

vex::motor Arm = vex::motor(vex::PORT8);
vex::motor ClawRotate = vex::motor(vex::PORT3);

vex::controller Controller1 = vex::controller();
vex::gyro Gyroscope = vex::gyro(Brain.ThreeWirePort.C);

void forward(double seconds, double meters);
void gyroTurning(double);

void ballShoot(double angle, double seconds);
void claw(double degree, double seconds);
void ArmMove(double angle, double seconds);

int main() {

  forward(5, 1);

}

void forward(double seconds, double meters){

    double RPM = meters/seconds * 6000 / 31.4;

    Brain.Screen.print(RPM);
    
    LeftMotor.setVelocity(RPM, vex::velocityUnits::rpm );
    RightMotor.setVelocity(RPM, vex::velocityUnits::rpm );
    RightMotor2.setVelocity(RPM, vex::velocityUnits::rpm );
    LeftMotor2.setVelocity(RPM, vex::velocityUnits::rpm );

    
    LeftMotor.spin( vex::directionType::fwd );
    RightMotor.spin( vex::directionType::fwd );
    LeftMotor2.spin( vex::directionType::fwd );
    RightMotor2.spin( vex::directionType::fwd );    

    vex::task::sleep(seconds * 1000);
    

    LeftMotor.stop();
    RightMotor.stop();

    LeftMotor2.stop();
    RightMotor2.stop();    

}

void gyroTurning(double degrees){

  Gyroscope.startCalibration();

  LeftMotor.setVelocity(100, vex::velocityUnits::rpm );
  RightMotor.setVelocity(100, vex::velocityUnits::rpm );
  RightMotor2.setVelocity(100, vex::velocityUnits::rpm );
  LeftMotor2.setVelocity(100, vex::velocityUnits::rpm );

  while(Gyroscope.value(vex::rotationUnits::deg) < 90){
    
    LeftMotor.spin( vex::directionType::rev );
    RightMotor.spin( vex::directionType::fwd );
    LeftMotor2.spin( vex::directionType::rev );
    RightMotor2.spin( vex::directionType::fwd );   


  }

}

void ballShoot(double angle, double seconds){

  double RotationAmount = angle * 0.002777777777777;

  double minutes = seconds / 60;

  double RPM = RotationAmount / minutes;

  BallShooterAngle.setVelocity(RPM, vex::velocityUnits::rpm );
  BallShooterAngle.spin(vex::directionType::fwd);

  vex::task::sleep(seconds * 1000);

  BallShooter.setVelocity(1000, vex::velocityUnits::rpm );  
  BallShooter.spin(vex::directionType::fwd);
  

  vex::task::sleep(1000);

}
void claw(double degree, double seconds){

  double RotationAmount = degree * 0.002777777777777;

  double minutes = seconds / 60;

  double RPM = RotationAmount / minutes;

  ClawRotate.setVelocity(RPM, vex::velocityUnits::rpm );
  ClawRotate.spin(vex::directionType::fwd);

  vex::task::sleep(seconds * 1000);


}
void ArmMove(double angle, double seconds){

  double RotationAmount = angle * 0.002777777777777;

  double minutes = seconds / 60;

  double RPM = RotationAmount / minutes;

  Arm.setVelocity(RPM, vex::velocityUnits::rpm );
  Arm.spin(vex::directionType::fwd);

  vex::task::sleep(seconds * 1000);


}
