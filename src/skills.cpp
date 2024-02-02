#include "main.h"


void new_skills() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(-15, -15, 1000, false, 100);
    pros::delay(500);
    chassis.turnTo(-17, 15, 1000);
    pros::delay(500);
    backwings(true);
    chassis.turnTo(-24, 15, 1000);
    //releaseIntake();
    autoCata(10000, 2000);
    backwings(false);
    chassis.turnTo(0, -10, 1000);
    pros::delay(100);
    chassis.moveToPoint(-40, -20, 1000, false, 100);
    chassis.moveToPoint(-4, 8, 1000, true, 100);
    pros::delay(100);
    chassis.turnTo(-3, 70, 1000);
    chassis.moveToPoint(-6, 70, 1000);
    pros::delay(500);

    chassis.moveToPoint(-5, 100, 1000);
    pros::delay(5000);
    chassis.setPose(0,0,0);
    chassis.turnTo(7, -10, 1000);
    chassis.moveToPoint(-15, 25, 1000, false, 110);
    chassis.moveToPoint(-30, 25, 1000, false, 110);
    chassis.moveToPoint(-15, 25, 1000, true, 110);
    chassis.moveToPoint(-30, 25, 1000, false, 110);
    chassis.moveToPoint(-15, 25, 1000, true, 110);
    chassis.turnTo(-10, 0, 1000);

}


void skills_auton() {
    ///Set the pose at the start
    chassis.setPose(0,0,0);
    //Back up for the launching
    chassis.moveToPoint(-13, -13, 1000, false);
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
    chassis.moveToPoint(-10, -10, 1000, true);
    //Turn to push it into the goal
    chassis.turnTo(10, 1, 1000);
    //Reset pose
    chassis.setPose(0,0,0);
    autowings(true);
    //Back up and push match load in
    chassis.moveToPoint(0, -35, 750, false);
    autowings(false);
    //Move back to og pos
    chassis.moveToPoint(0,0, 1000);
    //Reset the pose for the grand push
    chassis.setPose(0,0,0);
    //Move up a lil bit to prepare for push
    chassis.moveToPoint(-5, 10, 1000, 125);
    //Move to push under the bar
    chassis.turnTo(-18.75, 16.75, 1000);
    //Reset pose to push under the bar
    chassis.setPose(0,0,0);
    //Push under the bar
    chassis.moveToPoint(-4, 120, 1000, 150);
    //Reset pose and turn around the bot
    chassis.setPose(0,0,0);
    chassis.turnTo(3, -10, 1000);
    autowings(true);
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0, -10, 1000, 150);
    chassis.moveToPoint(15, -18, 1000, 160);
    chassis.moveToPoint(40, -30, 1000, 190);
    chassis.turnTo(0, -25, 1000); 
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0, 30, 1000, 150);
    chassis.moveToPoint(0,0, 1000, 190);
    autowings(false);
    //Move to the middle position of the field
    chassis.moveToPoint(0, 20, 1000);
    chassis.turnTo(40, 10, 1000);
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0, 40, 1000);
    chassis.setPose(0,0,0);
    chassis.turnTo(-5, 0, 1000);
    autowings(true);
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0, -45, 1000);
    chassis.moveToPoint(0,0,1000);
    chassis.moveToPoint(0, -50, 1000);
    chassis.moveToPoint(0,0,1000);
    //Turn to middle middle
    chassis.turnTo(10, -5, 1000);
    chassis.moveToPoint(22, -10, 1000);
    chassis.turnTo(30, 0, 1000);
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0, -75, 1000);
    chassis.moveToPoint(-3, 0, 1000);
    chassis.moveToPoint(-3, -75, 1000);
    chassis.moveToPoint(3, -75, 1000);
    chassis.moveToPoint(3, 0, 1000);
    chassis.setPose(0,0,0);
    //Hanngggggg
    chassis.turnTo(-20, 2, 1000);
    hangtime();
    chassis.moveToPoint(-40, 3, 1000);
    /*
    //Turn for grand push time
    chassis.turnTo(-35, -90, 1000);
    //Reset the pose for this part
    chassis.setPose(0,0,0);
    //Push all the tris to other side
    chassis.moveToPoint(0, -50, 1000, 135);
    //Extend wings now
    autowings(true);
    //Push triballs into the goal at max
    chassis.moveToPoint(7.5, -60, 1000, 150);
    chassis.moveToPoint(15, -57.5, 1000, 175);
    //Back out and ram back in again
    chassis.moveToPoint(-5, -57.5, 1000, 150);
    chassis.moveToPoint(15, -57.5, 1000, 175);
    //Wings back in
    autowings(false);
    //Move back to a reasonable position to set up for hang
    chassis.moveToPoint(0, -50, 1000, 140);
    //Reset pose to go for hang
    chassis.setPose(0,0,0);
    //Open the elevation with the piston
    hangtime();
    //Move to elevation bar
    chassis.moveToPoint(0, 55, 1000, 150);
    pros::delay(500);
    */
}
