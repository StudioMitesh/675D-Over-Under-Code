#include "main.h"

void pidlattune(){
    chassis.moveToPoint(0, 10, 0);
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

void valorsCloseShitHeWanted() { // krish started this
    chassis.setPose(0,0,0);
    cata.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    //releaseIntake();
    //pros::delay(200);

    autowings(true);
    pros::delay(200);
    autowings(false);

    chassis.moveToPose(0, 59, 0, 1750);

    pros::delay(750);

    intake.move_velocity(-600);

    pros::delay(750);

    intake.move_velocity(0);

    pros::delay(200);


    chassis.moveToPose(0, 0, 0, 750);
    
    chassis.setPose(0,0,0);

    chassis.moveToPose(0, -59, 0, 2000);

    chassis.turnTo(-90, 0, 1000);

   pros::delay(1000);
    
   chassis.moveToPose(0, -35, 0, 750);
}


void elims_offensive() {
    chassis.setPose(0,0,0);
    cata.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    releaseIntake();
    pros::delay(50);
    rightwings(true);
    pros::delay(200);
    rightwings(false);

    chassis.moveToPoint(0, 71.5, 3000);
    pros::delay(600);
    intakes();
    pros::delay(700);
    bothfrontwings(true);
    chassis.moveToPoint(7, 2, 1000, false);
    bothfrontwings(false);

    chassis.turnTo(17, 21, 1000);
    pros::delay(100);
    outtake();
    pros::delay(250);
    chassis.moveToPoint(-5, 6, 1000);
    chassis.moveToPoint(-42, 27, 2500);
    pros::delay(400);
    intakes();

    chassis.moveToPoint(4, 6, 1000, false);
    backwings(true);
    chassis.moveToPoint(20, 10, 1000, false);
    chassis.moveToPoint(31, 14, 1000, false);
    backwings(false);
    pros::delay(750);

    chassis.setPose(0,0,0);
    chassis.moveToPoint(-3, -25, 1000, false);
    chassis.moveToPoint(0, 18, 1000);
    chassis.turnTo(-3, -27, 500);
    pros::delay(150);
    outtake();
    pros::delay(50);
    chassis.moveToPoint(-5, -25, 1000);
    chassis.moveToPoint(0, 20, 1000, false);
}




void offensive() {
    chassis.setPose(0,0,0);
    cata.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    releaseIntake();
    pros::delay(200);

    intakes();
    pros::delay(150);

    chassis.moveToPoint(0, -40, 750, false, 100);
    chassis.turnTo(-25, 0, 750);
    pros::delay(150);
    backwings(true);
    pros::delay(150);
    chassis.moveToPoint(13, -58, 500, false, 100);
    chassis.turnTo(-13, -62, 750);
    pros::delay(150);
    pros::delay(150);
    chassis.moveToPoint(54, -76, 850, false, 120);
    pros::delay(100);
    backwings(false);
    pros::delay(500);

    chassis.setPose(0,0,0);
    chassis.moveToPoint(4, -13, 1500);
    outtake();
    pros::delay(250);
    chassis.moveToPoint(0, 0, 1500); 
    chassis.moveToPoint(4, 13, 1000);
    chassis.turnTo(28, 9, 1500);
    //chassis.turnTo(27.75, 9, 1500);
    pros::delay(500);

    chassis.setPose(0,0,0);
    chassis.moveToPoint(0, 40,1500);
    chassis.turnTo(25, 22, 1500);
    pros::delay(250);
    outtake();
    chassis.turnTo(-6, 65, 1500);
    pros::delay(250);
    chassis.moveToPoint(-6, 65, 1500);
    intakes();
    chassis.turnTo(25, 22, 1500);
    pros::delay(250);
    outtake();
    pros::delay(200);
    chassis.turnTo(8, 98, 1500);
    pros::delay(300);

    chassis.setPose(0,0,0);
    chassis.moveToPoint(0, 15, 1500);
    intakes();
    chassis.moveToPoint(0, 18, 1500);
    chassis.turnTo(10, 13, 1500);
    pros::delay(500);
    chassis.setPose(0,0,0);
    bothfrontwings(true);
    chassis.moveToPoint(0, 50, 1500);
    outtake();
    chassis.moveToPoint(0, 70, 1500);
    chassis.moveToPoint(0, 50, 1500, false);
}


void defensive_awp() {
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0, -20, 1000, false);
    chassis.moveToPoint(-22, -37, 1000, false);
    releaseIntake();
    pros::delay(150);
    chassis.moveToPoint(-2, 1, 1000);
    backwings(true);
    chassis.turnTo(-10, 10, 1000);
    chassis.moveToPoint(-16, 16.5, 1000);
    backwings(false);
    chassis.moveToPoint(-26.5, 27.5, 1000);
}

void near_elims(){
    chassis.setPose(0,0,0);
    bothfrontwings(true);
    pros::delay(500);
    bothfrontwings(false);
    chassis.moveToPoint(25, 25, 1000, true);
    backwings(true);
    chassis.turnTo(-25, 25, 1000);
    chassis.moveToPoint(50, 25, 1000, false);
    chassis.moveToPoint(25, 25, 1000, true);
    chassis.moveToPoint(50, 25, 1000, false);
    backwings(false);
    chassis.moveToPoint(25, 25, 1000, true);
    chassis.turnTo(0, 0, 1000);
    chassis.moveToPoint(0, 0, 1000, true);
    chassis.moveToPoint(-25, -25, 1000, false);
}


void simple_d_awp() {

    chassis.setPose(0,0,0);
    chassis.moveToPoint(0, -40, 1000, false, 100);
    pros::delay(500);
    chassis.moveToPoint(0, -10, 1000, true, 100);
    pros::delay(500);
    chassis.moveToPoint(0, -40, 1000, false, 100);
    chassis.moveToPoint(7, -12, 1000, true, 100);
    chassis.turnTo(1, 0, 1000);
    pros::delay(3000);

    backwings(true);
    chassis.moveToPoint(-2, 3, 1000, true, 100);
    pros::delay(500);
    backwings(false);
    chassis.turnTo(-4, 6, 1000);

    chassis.setPose(0,0,0);
    releaseIntake();
    outtake();
    chassis.moveToPoint(0, 50, 1000);
    
    //chassis.moveToPoint(150, 0, 1000, true, 100);
    //pros::delay(500);
    
    //chassis.moveToPoint(0, -37, 1000, 200);
    //chassis.moveToPoint(-2, -25, 1000, 125);
    //pros::delay(500);
    /*chassis.setPose(0,0,0);
    chassis.moveToPoint(8, 18, 1250, 90);
    chassis.turnTo(8.5, 24, 1000, false, 100);
    //chassis.moveToPoint(8, 20, 1000, 100);
    chassis.setPose(0,0,0);
    chassis.turnTo(-2, 5, 1000);
    pros::delay(500);
    autowings(true);
    pros::delay(1250);
    chassis.setPose(0,0,0);
    chassis.moveToPoint(-1, 15, 1000, 100);
    chassis.turnTo(-9, 23, 1000);
    pros::delay(600);
    autowings(false);
    pros::delay(750);
    chassis.setPose(0,0,0);
    chassis.moveToPoint(-2, 25, 1500, 125);
    releaseIntake();
    outtake();
    chassis.moveToPoint(-2.5, 32, 1000, 90);
    outtake();*/
}






// THE ACTUAL SIX TRIBALL AUTON FR
void offensive_six() {
    //set everything up
    chassis.setPose(0,0,0);
    cata.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    releaseIntake();
    pros::delay(500);
    //chassis.moveToPoint(0, 7, 600, 100);
    //intake the tri underneath the thing
    intakes();
    
    //move backward
    chassis.moveToPoint(0, -40, 750, false, 90);

    pros::delay(250);
    
    //turn exactly 45 degrees diagonally
    chassis.turnTo(-30, 0, 750); //-10, 0

    //pros::delay(500);

    //autowings(true);

    chassis.setPose(0,0,0);

    chassis.moveToPoint(0, -35, 750, false, 90);

    //pros::delay(500);

    //autowings(false);

    chassis.setPose(0,0,0);

    chassis.turnTo(-7, 0, 750, true, 100); // false (default), 100 speed (half)

    chassis.setPose(0,0,0);

    chassis.moveToPoint(0, -30, 750, false, 195);

    //pros::delay(200);

    chassis.setPose(0,0,0);

    chassis.moveToPoint(0, 15, 750, true, 100);

    chassis.turnTo(10, 15*3.14, 750, true, 150);

    outtake();

    chassis.setPose(0,0,0);

    chassis.moveToPoint(2, 25, 350, true, 190);
       
    chassis.moveToPoint(0, -15, 500, false, 150);

    chassis.turnTo(-19, 0, 500);

    chassis.setPose(0,0,0);

    // now get ready to go towards mmiddle of field!
    chassis.moveToPoint(7, 70, 1250, true, 150);

    intakes();

    pros::delay(500);

    chassis.setPose(0,0,0);

    chassis.turnTo(15, -10, 650);

    chassis.setPose(0,0,0);
    
    chassis.moveToPoint(1, 75, 750, true, 190);

    chassis.moveToPoint(0, 57.5, 500);

    chassis.turnTo(40, 1, 500);
    
    chassis.moveToPoint(40, 1, 500, true, 190);

    intakes();

    pros::delay(500);
    
    chassis.turnTo(0, 75, 300);

    chassis.moveToPoint(1.5, 90, 500, true, 190);

    /*
    chassis.setPose(0,0,0);
    pros::delay(350);

    chassis.moveToPoint(0, -25, 750, 100);

    chassis.setPose(0,0,0);

    chassis.turnTo(-20, 0, 250);

    chassis.setPose(0,0,0);

    chassis.moveToPoint(0, -25, 250, 190);

    //chassis.setPose();

    
    //open the wings
    //autowings(true);

    
    //back up and grab the match load
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0, -25, 1000, 75);

    // brings wings back
    //autowings(false);

    // turn the bot 180 degrees so that the intake is facing towards the goal
    chassis.turnTo(-15, -35, 300);
    chassis.turnTo(30, -55, 1000);
    chassis.setPose(0, 0, 0);

    //outakes
    outtake();

    // move forward and push into goal
    chassis.moveToPoint(5, 35, 1000, 195);


    //turn to the goal
    chassis.turnTo(30, -60, 1000, true);

    //bring wings back
    autowings(false);
    

    
    // back out and then go back forward to push the triballs in
    chassis.moveToPoint(0, 5, 1000, 100);
    chassis.moveToPoint(0, -8, 1000, 100);

    
    //back out of the goal
    chassis.moveToPoint(0, 25, 1000, 100);
    chassis.turnTo(3, 35, 1000);
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0, -20, 1000, 100);
    //turn to middle ish triball
    chassis.setPose(0,0,0);
    chassis.turnTo(-10, 0, 1000);
    //go to middle bar triball
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0, 75, 1000, 125);
    //intake the triball
    intakes();
    pros::delay(250);
    //turn to goal
    chassis.setPose(0,0,0);
    chassis.turnTo(20, -20, 1000);
    // go to the goal w the tri
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0, 75, 1250, 180);
    //outtake the triball
    outtake();
    chassis.moveToPoint(0, 100, 500, 190);
    //back off the goal
    chassis.moveToPoint(0, 80, 750, 175);
    //turn to last tribal
    chassis.turnTo(27, 0, 750);
    //go to last triball
    chassis.moveToPoint(27, 0, 1000, 160);
    //intake the last triball
    intakes();
    //move back to the mid
    chassis.moveToPoint(0, 70, 1000, 125);
    //turn to the goal
    chassis.turnTo(0, 100, 750);
    //push the last triball in
    outtake();
    chassis.moveToPoint(0, 100, 500, 180);
    //back off
    chassis.moveToPoint(0, 75, 750, 125);
    */


    
}

// 2-3 or WHATEVER TRIBALL AUTON THAT WORKS I THINK
void new_offensive() {
    chassis.setPose(0,0,0);
    releaseIntake();
    pros::delay(500);
    intakes();
    chassis.moveToPoint(0, 50, 1250, 135);
    chassis.setPose(0,0,0);
    chassis.turnTo(15, 8, 1000);
    outtake(); 
    chassis.setPose(0,0,0);
    chassis.turnTo(0, -15, 1000);
    pros::delay(500);
    chassis.setPose(0,0,0);
    chassis.moveToPoint(19, 29, 1000, 100);
    intakes();
    pros::delay(250);
    chassis.turnTo(17,35,1000);
    //pros::delay(750);
    //chassis.setPose(0,0,0);
    //chassis.turnTo(-5, -15, 1000);
    pros::delay(250);
    autowings(true);
    chassis.setPose(0,0,0);
    chassis.moveToPoint(-2, -40, 1000, 150);
    chassis.moveToPoint(-2, -25, 1000, 125);
    autowings(false);
    chassis.turnTo(-2, -40, 1000);
    outtake();
    chassis.moveToPoint(-2, -40, 1000, 150);
    chassis.moveToPoint(-2, -25, 1000);
    chassis.turnTo(-15, 0, 1000);
    chassis.moveToPoint(-15, 0, 1000, 140);
    intakes();
    chassis.moveToPoint(-2.5, -10, 1000, 120);
    chassis.turnTo(-2.5, -40, 1000);
    outtake();
    chassis.moveToPoint(-2.5, -40, 1000, 150);
    chassis.moveToPoint(-2.5, -30, 1000);

}

void offensive_middle() {
    chassis.setPose(0,0,0);
    //Drop off match load in the middle
    chassis.moveToPoint(0, -47.5, 1500, 70);
    releaseIntake();
    //Turn to triball on the pipe
    //chassis.turnTo(25, -35, 1000);
    //Move to the pipe triball
    chassis.moveToPoint(25, -35, 1250, 95);
    //Intake the pipe triball
    pros::delay(120);
    intakes();
    //Turn and drive away from the pipe
    chassis.moveToPoint(0, -50, 1000, 120);
    //Reset pose
    chassis.setPose(0,0,0);
    pros::delay(250);
    //Turn toward goal
    chassis.turnTo(-20, -65, 1200, false, 80);
    //Reset positioning pose
    chassis.setPose(0,0,0);
    //Outtake the triball
    pros::delay(500);
    outtake();
    pros::delay(500);
    //Push them into the goal
    chassis.moveToPoint(-3, 25, 1000, 120);
    pros::delay(250);
    //Back up slightly
    chassis.moveToPoint(-3, 15, 750);
    //Turn to other triball
    chassis.turnTo(-4, -7, 1500);
    pros::delay(250);
    //Move to pick up other triball
    chassis.moveToPoint(-4, -7, 1000, 120);
    //Intake the triball
    pros::delay(250);
    intakes();
    pros::delay(250);
    //Spin back to goal
    chassis.turnTo(-4, 25, 1000);
    pros::delay(250);
    //Move slightly to goal
    chassis.moveToPoint(-3.5, 5, 1000, 140);
    //Outtake the tri
    outtake();
    //Push it into the triball
    chassis.moveToPoint(-4, 25, 1000, 150);
}



void defensive_fakeawp(){
    chassis.setPose(0, 0, 15);
    //Unlock intake
    releaseIntake();
    //Drive to triball in the middle
    chassis.moveToPoint(29, 55, 1500, 155);
    //Pick up middle triball
    intakes();
    //Back up immediately
    chassis.moveToPoint(10, 30, 1500, 90);
    pros::delay(500);
    //Turn to new position
    chassis.turnTo(-11, 17.5, 1500);
    pros::delay(1000);
    //Reset the pose right here
    chassis.setPose(0,0,0);
    //Now back up to position
    chassis.moveToPoint(-3, 21, 1500, 100);
    //Swing into the goal
    /*
    chassis.turnTo(-3,18, 1000, 100);
    chassis.moveToPoint(-3, 18, 1500, 100);
    */
    //Reset positioning again
    chassis.setPose(0,0,0);
    //Turn again for a little bit to set up
    chassis.moveToPoint(-2, 3, 1000, 50);
    //Turn for steal
    chassis.turnTo(-15, 0, 1500);
    pros::delay(500);
    //Reset the pose
    chassis.setPose(0,0,0);
    //Extend wings out
    autowings(true);
    //Move and steal the triball from the goal
    chassis.moveToPoint(0, 10, 1000, 100);
    //Turn with steal
    chassis.turnTo(-8, 20, 1000);
    //Pull the steal out
    chassis.moveToPoint(-8, 20, 1000, 100);
    //Bring the wings in
    autowings(false);
    pros::delay(1000);
    //Reset position
    chassis.setPose(0,0,0);
    //Push triballs over the line
    chassis.moveToPoint(-3, 25.5, 1200, 125);
    //Outtake the triball
    outtake();
    //Turn and touch bar
    chassis.turnTo(-5, 27.5, 1200);
    //Move a lil bit
    chassis.moveToPoint(-5, 27.25, 1200, 125);

}

void single_tri_off() {
    chassis.setPose(0,0,0);
    chassis.moveToPoint(0, -35, 1000);
    chassis.moveToPoint(0, 0, 1000);
}


// DEFENSIVE AUTON FOR ELIMS
void defensive_elim() {
    chassis.setPose(0,0,0);
    //Rush for middle tri
    chassis.moveToPoint(30.5, 55, 1250, 85);
    releaseIntake();
    //Intake that triball
    intakes();
    //Back up a bit
    chassis.moveToPoint(25, 30, 1000, 120);
    //Turn to the right so we can push them over the line
    chassis.turnTo(60, 30, 1000);
    //Go up to the bar
    chassis.moveToPoint(50, 30, 1000, 100);
    //Outtake and push it over the line
    outtake();
    //Push
    chassis.moveToPoint(55, 30, 500, 125);
    //Back up a tad
    chassis.moveToPoint(25, 30, 1000, 120);
    //Turn toward second tri
    chassis.turnTo(50, 55, 1000);
    //Go for the other tri
    chassis.moveToPoint(50, 55, 1000);
    //Intake
    intakes();
    //Back up again
    chassis.moveToPoint(25, 30, 1000, 120);
    //Turn to the right so we can push them over the line part 2
    chassis.turnTo(60, 30, 1000);
    //Go up to the bar part 2
    chassis.moveToPoint(50, 30, 1000, 100);
    //Outtake and push it over the line part 2
    outtake();
    //Push part 2
    chassis.moveToPoint(55, 30, 500, 125);
    //Back up a tad part 2
    chassis.moveToPoint(25, 30, 1000, 120);
    //Turn toward the alliance triball
    chassis.turnTo(-3, 3, 750);
    
    //Reset the pose for simplicity
    chassis.setPose(0,0,0);
    //Go to the alliance triball
    chassis.moveToPoint(-10, 50, 1000, 125);
    //Reset the pose again
    chassis.setPose(0,0,0);
    //Turn away so back faces alli tri
    chassis.turnTo(-40, 0, 1000);
    //Back straight into the thing with wings
    autowings(true);
    chassis.moveToPoint(20, -3, 1000, 150);
    autowings(false);
    //Turn slightly
    chassis.turnTo(25, -10, 750);
    //Back alli tri straight in
    chassis.moveToPoint(35, -15, 1000, 190);
    //Move forward
    chassis.moveToPoint(10, -5, 750);
}