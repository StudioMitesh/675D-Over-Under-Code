#include "main.h"

void skills_auton() {
    //Set the pose at the start
    chassis.setPose(0,0,0);
    //Back up for the launching
    chassis.moveTo(-13, -13, 1000, 100);
    //Release the intake for the rest of the run
    releaseIntake();
    chassis.turnTo(-16, -1, 1000);
    autowings(true);
    chassis.turnTo(-16, -1, 1000, false, 75);
    pros::delay(100);
    //Automatically spin the cata
    autoCata(9500, 35000);
    autowings(false);
    //Back up off match load zone
    chassis.moveTo(-10, -10, 1000, 100);
    //Turn to push it into the goal
    chassis.turnTo(10, 1, 1000);
    //Reset pose
    chassis.setPose(0,0,0);
    autowings(true);
    //Back up and push match load in
    chassis.moveTo(0, -35, 750, 180);
    autowings(false);
    //Move back to og pos
    chassis.moveTo(0,0, 1000);
    //Reset the pose for the grand push
    chassis.setPose(0,0,0);
    //Move up a lil bit to prepare for push
    chassis.moveTo(-5, 10, 1000, 125);
    //Move to push under the bar
    chassis.turnTo(-18.75, 16.75, 1000);
    //Reset pose to push under the bar
    chassis.setPose(0,0,0);
    //Push under the bar
    chassis.moveTo(-4, 120, 1000, 150);
    //Reset pose and turn around the bot
    chassis.setPose(0,0,0);
    chassis.turnTo(3, -10, 1000);
    autowings(true);
    chassis.setPose(0,0,0);
    chassis.moveTo(0, -10, 1000, 150);
    chassis.moveTo(15, -18, 1000, 160);
    chassis.moveTo(40, -30, 1000, 190);
    chassis.turnTo(0, -25, 1000); 
    chassis.setPose(0,0,0);
    chassis.moveTo(0, 30, 1000, 150);
    chassis.moveTo(0,0, 1000, 190);
    autowings(false);
    //Move to the middle position of the field
    chassis.moveTo(0, 20, 1000);
    chassis.turnTo(40, 10, 1000);
    chassis.setPose(0,0,0);
    chassis.moveTo(0, 40, 1000);
    chassis.setPose(0,0,0);
    chassis.turnTo(-5, 0, 1000);
    autowings(true);
    chassis.setPose(0,0,0);
    chassis.moveTo(0, -45, 1000);
    chassis.moveTo(0,0,1000);
    chassis.moveTo(0, -50, 1000);
    chassis.moveTo(0,0,1000);
    //Turn to middle middle
    chassis.turnTo(10, -5, 1000);
    chassis.moveTo(22, -10, 1000);
    chassis.turnTo(30, 0, 1000);
    chassis.setPose(0,0,0);
    chassis.moveTo(0, -75, 1000);
    chassis.moveTo(-3, 0, 1000);
    chassis.moveTo(-3, -75, 1000);
    chassis.moveTo(3, -75, 1000);
    chassis.moveTo(3, 0, 1000);
    chassis.setPose(0,0,0);
    //Hanngggggg
    chassis.turnTo(-20, 2, 1000);
    hangtime();
    chassis.moveTo(-40, 3, 1000);
    /*
    //Turn for grand push time
    chassis.turnTo(-35, -90, 1000);
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
    */
}
