#include "vex.h"



vex::brain Brain;

vex::motor LeftMotor2 = vex::motor( vex::PORT2 , true);
vex::motor RightMotor = vex::motor( vex::PORT1 );
vex::motor LeftMotor = vex::motor( vex::PORT10, true );
vex::motor RightMotor2 = vex::motor( vex::PORT9);

vex::motor BallShooter = vex::motor(vex::PORT16);
vex::motor BallShooterAngle = vex::motor(vex::PORT17);

vex::motor Arm = vex::motor(vex::PORT8);
vex::motor ClawRotate = vex::motor(vex::PORT3);

  vex::controller Controller1 = vex::controller();

  vex::gyro Gyroscope = vex::gyro(Brain.ThreeWirePort.C);
  vex::sonar UltraSonic = vex::sonar(Brain.ThreeWirePort.A);



  

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

  void turn(double degrees, double RPM, double fixer, bool left = false){

    if(left){
      LeftMotor.setReversed(true);
      LeftMotor2.setReversed(true);

    }
    else{
      RightMotor.setReversed(true);
      RightMotor2.setReversed(true);    
    }
      
    LeftMotor.setVelocity(0, vex::velocityUnits::rpm );
    RightMotor.setVelocity(RPM, vex::velocityUnits::rpm );
    RightMotor2.setVelocity(RPM, vex::velocityUnits::rpm );
    LeftMotor2.setVelocity(0, vex::velocityUnits::rpm );

    LeftMotor.spin( vex::directionType::rev );
    RightMotor.spin( vex::directionType::fwd );
    LeftMotor2.spin( vex::directionType::rev );
    RightMotor2.spin( vex::directionType::fwd );   



    vex::task::sleep(((7.407407407407407 * degrees) * 2)* degrees / fixer);



  }

 

  void ballShoot(double angle, double seconds){

    double RotationAmount = angle / 360;

    double minutes = seconds / 60;

    double RPM = RotationAmount / (minutes*2);

    BallShooterAngle.setVelocity(RPM, vex::velocityUnits::rpm );
    BallShooterAngle.spin(vex::directionType::fwd);

    vex::task::sleep(seconds * 1000);

    BallShooter.setVelocity(1000, vex::velocityUnits::rpm );  
    BallShooter.spin(vex::directionType::fwd);
    

    vex::task::sleep(1000);

    BallShooter.stop();
    BallShooterAngle.stop();

  }
  void claw(double degree, double seconds){

    double RotationAmount = degree / 360;

    double minutes = seconds / 60;

    double RPM = RotationAmount / (minutes * 2);

    ClawRotate.setVelocity(RPM, vex::velocityUnits::rpm );
    ClawRotate.spin(vex::directionType::fwd);

    vex::task::sleep(seconds * 1000);


  }
  void ArmMove(double angle, double seconds){

    double RotationAmount = angle * 0.08722222222222222222222222222222;

    double minutes = seconds / 60;

    double RPM = RotationAmount / minutes / minutes;

    Arm.setVelocity(RPM, vex::velocityUnits::rpm );
    Arm.spin(vex::directionType::fwd);

    vex::task::sleep(seconds * 1000);


  }




int main() {
  LeftMotor.setReversed(false);
  LeftMotor2.setReversed(false);
  RightMotor.setReversed(true);
  RightMotor2.setReversed(true);
  
  forward(1, .3048 * 2);

  LeftMotor.setReversed(false);
  LeftMotor2.setReversed(false);
  RightMotor.setReversed(true);
  RightMotor2.setReversed(true);
  
  turn(90, 100, 90, true);

  LeftMotor.setReversed(false);
  LeftMotor2.setReversed(false);
  RightMotor.setReversed(true);
  RightMotor2.setReversed(true);
  forward(2.34, 10000);

  

  LeftMotor.stop();
  RightMotor.stop();
  LeftMotor2.stop();
  RightMotor2.stop(); 

}
