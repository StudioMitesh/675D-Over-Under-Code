#include "main.h"

void pidlattune(){
    chassis.moveTo(0, 10, 0);
}

void pidangtune(){
    chassis.turnTo(30, 0, 0);
}


/*
void testPath(){
    //chassis.setPose(-14.447676046176046, -13.61615512265512, 0);
    
    chassis.setPose(-11.329472582972583, -36.06722005772006, 0);
    chassis.follow("path4.txt", 5000, 15);
}
*/


void offensive_middle() {
  chassis.setPose(0,0,0);
  //Drop off match load in the middle
  chassis.moveTo(0, -47.5, 1000);
  //Turn to triball on the pipe
  //chassis.turnTo(25, -35, 1000);
  //Move to the pipe triball
  chassis.moveTo(25, -40, 1000);
  //Intake the pipe triball
  pros::delay(120);
  intake.move_relative(1080,600);
  //Turn and drive away from the pipe
  chassis.moveTo(0, -50, 1000);
  //Turn toward goal
  chassis.turnTo(-10, -50, 1000);
  //Outtake the triball
  intake.move_velocity(-600);
  pros::delay(350);
  intake.move_velocity(0);
  //Push them into the goal
  chassis.moveTo(-15, -50, 1000);
  /*
  //Intake the pipe triball
  chassis.set_drive_pid(60, DRIVE_SPEED);
  chassis.wait_drive();
  pros::delay(120);
  intake.move_relative(1080, 600); //intake
  chassis.set_turn_pid(240, TURN_SPEED);
  chassis.wait_drive();
  pros::delay(200);
  intake.move_velocity(-600);
  pros::delay(350);
  intake.move_velocity(0); //outtake
  pros::delay(50);
  chassis.set_turn_pid(70, TURN_SPEED);
  chassis.wait_drive();
  wings.set_value(true);
  chassis.set_drive_pid(-75, DRIVE_SPEED_FASTEST);
  chassis.wait_drive();
  */
}

void matchOffense(){
    chassis.setPose(50, -55, 0);
}