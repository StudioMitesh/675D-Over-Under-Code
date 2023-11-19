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
    chassis.moveTo(0, -47.5, 1000, 100);
    releaseIntake();
    //Turn to triball on the pipe
    //chassis.turnTo(25, -35, 1000);
    //Move to the pipe triball
    chassis.moveTo(25, -40, 1000, 125);
    //Intake the pipe triball
    pros::delay(120);
    intakes();
    //Turn and drive away from the pipe
    chassis.moveTo(0, -50, 1000, 115);
    //Turn toward goal
    chassis.turnTo(-20, -60, 1000);
    //Reset positioning pose
    chassis.setPose(0,0,0);
    //Outtake the triball
    pros::delay(500);
    outtake(350);
    pros::delay(500);
    //Push them into the goal
    chassis.moveTo(-2, 25, 1000, 100);
    pros::delay(250);
    //Turn to other triball
    chassis.turnTo(-8, -8, 1500);
    pros::delay(250);
    //Move to pick up other triball
    chassis.moveTo(-8, -8, 1000, 100);
    //Intake the triball
    pros::delay(250);
    intakes();
    pros::delay(250);
    //Spin back to goal
    chassis.turnTo(-10, 25, 1000);
    pros::delay(250);
    //Outtake the tri
    outtake(300);
    //Push it into the triball
    chassis.moveTo(-10, 25, 1000, 135);
}

void defensive_awp(){
    chassis.setPose(0, 0, 15);
    //Unlock intake
    releaseIntake();
    //Drive to triball in the middle
    chassis.moveTo(30.5, 55, 1500, 155);
    //Pick up middle triball
    intakes();
    //Back up immediately
    chassis.moveTo(10, 30, 1500, 90);
    pros::delay(500);
    //Turn to new position
    //Now back up to position
    chassis.moveTo(-11.5, 17.5, 1500, 100);
    //Swing into the goal
    /*
    chassis.turnTo(-3,18, 1000, 100);
    chassis.moveTo(-3, 18, 1500, 100);
    */
    //Turn for steal
    chassis.turnTo(5, 0, 1500);
    //Reset the pose
    chassis.setPose(0,0,0);
    //Extend wings out
    autowings(true);
    //Move and steal the triball from the goal
    chassis.moveTo(0, 10, 1000, 100);
    //Turn with steal
    chassis.turnTo(-8, 20, 1000);
    //Pull the steal out
    chassis.moveTo(-8, 20, 1000, 100);
    //Bring the wings in
    autowings(false);
    pros::delay(1000);
    //Reset position
    chassis.setPose(0,0,0);
    //Push triballs over the line
    chassis.moveTo(-3, 25.5, 1200, 125);
    //Outtake the triball
    outtake(300);
    //Turn and touch bar
    chassis.turnTo(-7, 35, 1200);
    //Move a lil bit
    chassis.moveTo(-5, 27, 1200, 125);

}


void skills_auton() {
    //Set the pose at the start
    chassis.setPose(0,0,0);
    //Push the triball under the close goal
    chassis.moveTo(15, -20, 1000, 140);
    //Release the intake for the rest of the run
    releaseIntake();
    //Back up off goal
    chassis.moveTo(15, -5, 1000, 100);
    //Turn for the cata motion
    chassis.turnTo(-75, -5, 1000);
    //Back up against the match load zone thingy
    chassis.moveTo(20, -5, 750, 125);
    //Open wings so we touch the match load zone thingy
    autowings(true);
    pros::delay(200);
    //Automatically spin the cata
    autoCata(9500, 40000);
    //Reset the pose for the grand push
    chassis.setPose(0,0,0);
    //Move up a lil bit to prepare for 180
    chassis.moveTo(5, 25, 1000, 125);
    //Retract wings for 180
    autowings(false);
    //Make 180 so wings are ready
    chassis.turnTo(-5, 0, 1000);
    //Move to position to push underneath the hang bar
    chassis.moveTo(15, 40, 1000, 100);
    //Turn for grand push time
    chassis.turnTo(15, 90, 1000);
    //Reset the pose for this part
    chassis.setPose(0,0,0);
    //Push all the tris to other side
    chassis.moveTo(0, -50, 1000, 135);
    //Extend wings now
    autowings(true);
    //Push triballs into the goal at max
    chassis.moveTo(7.5, -60, 1000, 150);
    chassis.moveTo(15, -57.5, 1000, 175);
    //Back out and ram back in again
    chassis.moveTo(-5, -57.5, 1000, 150);
    chassis.moveTo(15, -57.5, 1000, 175);
    //Wings back in
    autowings(false);
    //Move back to a reasonable position to set up for hang
    chassis.moveTo(0, -50, 1000, 140);
    //Reset pose to go for hang
    chassis.setPose(0,0,0);
    //Open the elevation with the piston
    hangtime();
    //Move to elevation bar
    chassis.moveTo(0, 55, 1000, 150);
    pros::delay(500);
}

/*
void skills(){
    
    autoFire();
    pros::delay(40000);
    chassis.setPose(0,0, 0);
    chassis.moveTo(31, -68, 2000, 125);
 
   
    
    chassis.setPose(0, 0, 0);
    chassis.moveTo(-10, -10, 1000, 150);
   
    chassis.moveTo(-20, 10, 1000, 150);
    chassis.setPose(0, 0, 0);
    autoWings(true);
    chassis.moveTo(-10, -10, 1000, 75);
    chassis.moveTo(-10, -15, 1000, 100);
    chassis.setPose(0, 0,0);
    chassis.moveTo(-15, 10, 1000, 100);
    chassis.moveTo(-10,-5, 1000 , 100);
    chassis.setPose(0, 0,0);
    chassis.moveTo(-15, 10, 1000, 100);
    chassis.moveTo(-10,-5, 1000 , 100);
    chassis.setPose(0, 0,0);
    chassis.moveTo(-15, 10, 1000, 100);
    chassis.moveTo(-10,-5, 1000 , 100);
    chassis.setPose(0, 0,0);
    chassis.moveTo(-15, 10, 1000, 100);
    chassis.moveTo(-10,-5, 1000 , 100);
}
*/