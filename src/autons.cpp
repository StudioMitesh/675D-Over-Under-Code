#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}




//far side comp auton offensive
void far_side_comp_auton() {
  //Extend intake down
  moveintake.set_value(true);
  //Intake green triball under bar
  pros::delay(100);
  chassis.set_drive_pid(-10, DRIVE_SPEED);
  chassis.wait_drive();
  intake.move_relative(720, 600);
  //Move forward toward match load zone, pushing red triball along w it
  chassis.set_drive_pid(90, DRIVE_SPEED);
  chassis.wait_drive();
  //Swing and extend wings
  //wings.set_value(true);
  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();
  //Go forward against the match load bar
  chassis.set_drive_pid(20, DRIVE_SPEED);
  chassis.wait_drive();
  //Turn into the goal
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();
  //Go forward and push the two into the goal
  chassis.set_drive_pid(60, DRIVE_SPEED+10);
  chassis.wait_drive();
  pros::delay(250);
  //Go backwards out
  chassis.set_drive_pid(-40, DRIVE_SPEED);
  chassis.wait_drive();
  //Turn full 180
  chassis.set_turn_pid(100, TURN_SPEED*0.75);
  chassis.wait_drive();
  pros::delay(150);
  //Go forward into the goal and outtake the triball from intake
  intake.move_velocity(-600);
  pros::delay(200);
  intake.move_velocity(0);
  chassis.set_drive_pid(-40, DRIVE_SPEED);
  chassis.wait_drive();
  //Back up after dropping it
  chassis.set_drive_pid(40, DRIVE_SPEED);
  chassis.wait_drive();
  //Turn to middle
  chassis.set_turn_pid(60, TURN_SPEED);
  chassis.wait_drive();
  //Drive toward middle
  chassis.set_drive_pid(-95,DRIVE_SPEED);
  chassis.wait_drive();
  //Turn to triball
  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
  //Move to triball on the pipe
  chassis.set_drive_pid(-50, DRIVE_SPEED);
  chassis.wait_drive();
  //Intake the triball on the pipe
  intake.move_velocity(600);
  pros::delay(300);
  intake.move_velocity(0);
  //Back up off pipe
  chassis.set_drive_pid(20, DRIVE_SPEED);
  chassis.wait_drive();
  /*
  //Turn inwards
  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  //Move forward ish
  chassis.set_drive_pid(-25, DRIVE_SPEED);
  chassis.wait_drive();
  //Turn toward goal
  chassis.set_turn_pid(180, TURN_SPEED);
  chassis.wait_drive();
  */
  //Turn toward goal
  chassis.set_turn_pid(160, TURN_SPEED*0.75);
  chassis.wait_drive();
  //Outtake and push toward goal and in
  chassis.set_drive_pid(-80, DRIVE_SPEED);
  chassis.wait_drive();
  intake.move_velocity(-600);
  pros::delay(500);
  intake.move_velocity(0);

}


//far side auton win point combo auton
void far_side_awp() {
  //Extend intake down
  moveintake.set_value(true);
  //Intake green triball under bar
  //chassis.set_drive_pid(-10, DRIVE_SPEED);
  //chassis.wait_drive();
  intake.move_relative(720, 600);
  //Move forward toward match load zone, pushing red triball along w it
  chassis.set_drive_pid(70, DRIVE_SPEED);
  chassis.wait_drive();
  //Swing and extend wings
  wings.set_value(true);
  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();
  //Go forward against the match load bar
  chassis.set_drive_pid(20, DRIVE_SPEED);
  chassis.wait_drive();
  //Turn into the goal
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();
  //Go forward and push the two into the goal
  chassis.set_drive_pid(40, DRIVE_SPEED+10);
  chassis.wait_drive();
  pros::delay(250);
  //Go backwards out
  chassis.set_drive_pid(-40, DRIVE_SPEED);
  chassis.wait_drive();
  //Turn full 180
  chassis.set_turn_pid(100, TURN_SPEED*0.75);
  chassis.wait_drive();
  pros::delay(150);
  //Go forward into the goal and outtake the triball from intake
  intake.move_velocity(-600);
  pros::delay(200);
  intake.move_velocity(0);
  chassis.set_drive_pid(-40, DRIVE_SPEED);
  chassis.wait_drive();
  //Back up after dropping it
  chassis.set_drive_pid(40, DRIVE_SPEED);
  chassis.wait_drive();
  //Retract wings
  wings.set_value(false);
  //Turn to bar
  chassis.set_turn_pid(-10, TURN_SPEED);
  chassis.wait_drive();
  //Drive toward bar
  chassis.set_drive_pid(-95,DRIVE_SPEED);
  chassis.wait_drive();
  //Raise intake
  moveintake.set_value(false);
  //Touch elevation bar slightly
  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-15, DRIVE_SPEED*0.5);
  chassis.wait_drive();
}


// near side auton
void near_side() {
  //Extend intake down
  moveintake.set_value(true);
  //
}


//skills auton: spam tribals
void skills_auton() {
  //Push straight into the close goal (2 tribals)
  chassis.set_drive_pid(90, 127, true, true);
  chassis.wait_drive();
  //Move backward out
  chassis.set_drive_pid(-30, DRIVE_SPEED);
  chassis.wait_drive();
  //Turn to goal
  chassis.set_turn_pid(120, TURN_SPEED);
  chassis.wait_drive();
  //Spam
  cata.move_voltage(10000);
  pros::delay(30000);
  cata.move_voltage(0);
  //Turn to go under bar
  chassis.set_turn_pid(150, TURN_SPEED);
  chassis.wait_drive();
  //Go under neath the bar
  chassis.set_drive_pid(150, DRIVE_SPEED, true, true);
  chassis.wait_drive();
  //Turn away from the thing
  chassis.set_turn_pid(-20, TURN_SPEED);
  chassis.wait_drive();
  //Drive toward the tribals
  chassis.set_drive_pid(100, DRIVE_SPEED, true, true);
  chassis.wait_drive();
  //Turn toward goal
  chassis.set_turn_pid(150, TURN_SPEED);
  chassis.wait_drive();
  //RAM into
  wings.set_value(true);
  chassis.set_drive_pid(60, 127, true, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-40, 127, true, true);
  chassis.wait_drive();
  chassis.set_drive_pid(60, 127, true, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-40, 127, true, true);
  chassis.wait_drive();
}









///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches


  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();
}



///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at


  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}



///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();
}



///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive


  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}



///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Interference example
///
void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees. 
// If interfered, robot will drive forward and then attempt to drive backwards. 
void interfered_example() {
 chassis.set_drive_pid(24, DRIVE_SPEED, true);
 chassis.wait_drive();

 if (chassis.interfered) {
   tug(3);
   return;
 }

 chassis.set_turn_pid(90, TURN_SPEED);
 chassis.wait_drive();
}



// . . .
// Make your own autonomous functions here!
// . . .