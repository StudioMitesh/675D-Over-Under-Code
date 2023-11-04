#include "main.h"
#include <random>

/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////

const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int DRIVE_SPEED_FASTER = 120;
const int DRIVE_SPEED_FASTEST = 127;
const int TURN_SPEED = 90;
const int TURN_SPEED_FASTER = 105;
const int TURN_SPEED_FASTEST = 127;
const int SWING_SPEED = 90;
const int spinVoltage = 7500;


///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.



void default_constants()
{
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults()
{
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition()
{
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

// far side comp auton offensive
void far_side_comp_auton()
{
  // Extend intake down
  // moveintake.set_value(true);
  // Intake green triball under bar
  chassis.set_drive_pid(-10, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(35, DRIVE_SPEED);
  chassis.wait_drive();
  intake.move_relative(720, 600);
  // Move forward toward match load zone, pushing red triball along w it
  chassis.set_drive_pid(-180, DRIVE_SPEED * 0.75, true, true);
  chassis.wait_drive();
  // Swing and extend wings
  wings.set_value(true);
  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();
  // Go forward against the match load bar
  chassis.set_drive_pid(-20, DRIVE_SPEED);
  chassis.wait_drive();
  // Turn into the goal
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();
  // Go forward and push the two into the goal
  chassis.set_drive_pid(-60, DRIVE_SPEED + 10);
  chassis.wait_drive();
  pros::delay(250);
  // Go backwards out
  chassis.set_drive_pid(40, DRIVE_SPEED);
  chassis.wait_drive();
  wings.set_value(false);
  // Turn full 180
  chassis.set_turn_pid(100, TURN_SPEED * 0.75);
  chassis.wait_drive();
  pros::delay(150);
  // Go forward into the goal and outtake the triball from intake
  intake.move_velocity(-600);
  pros::delay(200);
  intake.move_velocity(0);
  chassis.set_drive_pid(40, DRIVE_SPEED);
  chassis.wait_drive();
  // Back up after dropping it
  chassis.set_drive_pid(-40, DRIVE_SPEED);
  chassis.wait_drive();
  // Turn to middle
  chassis.set_turn_pid(60, TURN_SPEED);
  chassis.wait_drive();
  // Drive toward middle
  chassis.set_drive_pid(95, DRIVE_SPEED);
  chassis.wait_drive();
  // Turn to triball
  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
  // Move to triball on the pipe
  chassis.set_drive_pid(50, DRIVE_SPEED);
  chassis.wait_drive();
  // Intake the triball on the pipe
  intake.move_velocity(600);
  pros::delay(300);
  intake.move_velocity(0);
  // Back up off pipe
  chassis.set_drive_pid(-20, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.wait_drive();
  chassis.set_drive_pid(-25, DRIVE_SPEED);

  // chassis.set_turn_pid(160, TURN_SPEED*0.75);
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
  // Turn toward goal
  chassis.set_turn_pid(160, TURN_SPEED * 0.75);
  chassis.wait_drive();
  // Outtake and push toward goal and in
  chassis.set_drive_pid(-80, DRIVE_SPEED);
  chassis.wait_drive();
  intake.move_velocity(-600);
  pros::delay(500);
  intake.move_velocity(0);

  /*
  // Krish auton
  // Push the triball forward towards the goal and expand wings to get the one triball out of the corner
  chassis.set_drive_pid(20, DRIVE_SPEED*1.5); // Forward 20 inches
  chassis.wait_drive();
  wings.set_value(true); // Expand the wings
  chassis.set_drive_pid(5, DRIVE_SPEED); // Drive forward 5 inches and hopefully triball will come out of the corner
  wings.set_value(false); // Retract the wings
  chassis.set_drive_pid(25, DRIVE_SPEED); // Drive forward 25 inches

  // Back out a little bit and then go back forward to ram the triball into the net goal
  chassis.set_drive_pid(-15, DRIVE_SPEED*1.5);
  chassis.wait_drive();
  chassis.set_drive_pid(15, DRIVE_SPEED);

  // Return to the location that it was before
  chassis.set_drive_pid(-50, DRIVE_SPEED);

  // At this point, hopefully the bot returns to where it started before the auton period. Once its back to where it started, it will go to the first triball located in the center of the field.
  // Turn 60 degrees
  chassis.set_turn_pid(60, TURN_SPEED);
  chassis.wait_drive();

  // Go forward 50 inches
  chassis.set_drive_pid(50, DRIVE_SPEED);
  chassis.wait_drive();

  // Start intaking the triball
  intake.move_velocity(400); // Intake the triball
  pros::delay(500); // Delay for half a second
  intake.move_velocity(0); // Stop intake motor

  // Turn the robot to face towards the net goals
  chassis.set_turn_pid(260, DRIVE_SPEED);
  pros::delay(250);
  chassis.set_drive_pid(50, DRIVE_SPEED*1.15);

  // Outake the triball
  intake.move_velocity(-400);

  // Back robot up so that it can then be used to ram the triball into the goal
  chassis.set_drive_pid(-20, DRIVE_SPEED*1.5);
  chassis.set_dribe_pid(20, DRIVE_SPEED);

  // Now back out so that we can go for another triball
  chassis.set_drive_pid(-30, DRIVE_SPEED*2);
  chassis.wait_drive();
  
  // Turn -80 degrees to face the middle of the feild
  chassis.set_turn_pid(-80, DRIVE_SPEED);
  chassis.wait_drive();

  // Drive forward and intake the triball
  chassis.set_drive_pid(25, DRIVE_SPEED*1.5);
  chassis.wait_drive();

  //Intake the triball
  intake.move_velocity(600);
  pros::delay(150);
  intake.move_velocity(0);

  // Turn 180 degrees
  chassis.set_turn_pid(180, DRIVE_SPEED*1.5);
  
  // Drive forward 20 inches @times 1.75 speed
  chassis.set_drive_pid(20, DRIVE_SPEED*1.75);
  // Drive forward 10 inches normal drive_speed
  chassis.set_drive_pid(10, DRIVE_SPEED);

  // Outake triball
  intake.move_velocity(-600, DRIVE_SPEED);

  // Back up and then go forward again (ram triball in)
  chassis.set_drive_pid(-15, DRIVE_SPEED*1.5);
  chassis.set_drive_pid(15, DRIVE_SPEED;

  
  Drive bot to the bar
  

  chassis.set_drive_pid(-30, DRIVE_SPEED*1.5);
  chassis.set_turn_pid(80, DRIVE_SPEED*1.5);

  chassis.set_drive_pid(25, DRIVE_SPEED);
  slap. // do the fxcking thing with caputal. idk how to do dis shit cause Joseph changed it all
  */







}

// far side auton win point combo auton
void far_side_awp()
{
  // Extend intake down
  //moveintake.set_value(true);
  // Intake green triball under bar
  // chassis.set_drive_pid(-10, DRIVE_SPEED);
  // chassis.wait_drive();
  intake.move_relative(720, 600);
  // Move forward toward match load zone, pushing red triball along w it
  chassis.set_drive_pid(70, DRIVE_SPEED);
  chassis.wait_drive();
  // Swing and extend wings
  wings.set_value(true);
  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();
  // Go forward against the match load bar
  chassis.set_drive_pid(20, DRIVE_SPEED);
  chassis.wait_drive();
  // Turn into the goal
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();
  // Go forward and push the two into the goal
  chassis.set_drive_pid(40, DRIVE_SPEED + 10);
  chassis.wait_drive();
  pros::delay(250);
  // Go backwards out
  chassis.set_drive_pid(-40, DRIVE_SPEED);
  chassis.wait_drive();
  // Turn full 180
  chassis.set_turn_pid(100, TURN_SPEED * 0.75);
  chassis.wait_drive();
  pros::delay(150);
  // Go forward into the goal and outtake the triball from intake
  intake.move_velocity(-600);
  pros::delay(200);
  intake.move_velocity(0);
  chassis.set_drive_pid(-40, DRIVE_SPEED);
  chassis.wait_drive();
  // Back up after dropping it
  chassis.set_drive_pid(40, DRIVE_SPEED);
  chassis.wait_drive();
  // Retract wings
  wings.set_value(false);
  // Turn to bar
  chassis.set_turn_pid(-10, TURN_SPEED);
  chassis.wait_drive();
  // Drive toward bar
  chassis.set_drive_pid(-95, DRIVE_SPEED);
  chassis.wait_drive();
  // Raise intake
  //moveintake.set_value(false);
  // Touch elevation bar slightly
  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-15, DRIVE_SPEED * 0.5);
  chassis.wait_drive();
}

// near side auton
void near_side()
{
  // Extend intake down
  //moveintake.set_value(true);
  //
}

void farsideish()
{
  // Push straight into the close goal (match load tribals)
  chassis.set_drive_pid(-90, 127, true, true);
  chassis.wait_drive();
  chassis.set_drive_pid(20, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-40, 127);
  chassis.wait_drive();
  // Move backward out
  chassis.set_drive_pid(45, DRIVE_SPEED);
  chassis.wait_drive();
  // Turn to elev bar and go to it
  chassis.set_turn_pid(-120 + 210, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(95, DRIVE_SPEED * 0.8, true, true);
  chassis.wait_drive();
  chassis.set_drive_pid(25, DRIVE_SPEED * 0.75);
  chassis.wait_drive();
  pros::delay(500);
  // Intake the one on the bar
  intake.move_relative(1080, 600);
  pros::delay(500);
  // Turn around
  chassis.set_turn_pid(-135, TURN_SPEED * 0.75);
  chassis.wait_drive();
  pros::delay(150);
  // Outtake slightly
  intake.move_velocity(-600);
  pros::delay(300);
  intake.move_velocity(0);
  // Push into the goal
  chassis.set_drive_pid(110, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-20, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(40, 127);
  chassis.wait_drive();
  // Back up to elevation bar
  chassis.set_drive_pid(-120, DRIVE_SPEED);
  chassis.wait_drive();
  // Turn toward bar
  chassis.set_turn_pid(160, TURN_SPEED);
  chassis.wait_drive();
  // Extend wings
  wings.set_value(true);
  // Back up into bar
  chassis.set_drive_pid(-50, DRIVE_SPEED);
  chassis.wait_drive();
}

void far_side_bar() {
  //Push straight into the close goal (match load tribals)
  chassis.set_drive_pid(-90, 127, true, true);
  chassis.wait_drive();
  chassis.set_drive_pid(20, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-40,127);
  chassis.wait_drive();
  //Move backward out
  chassis.set_drive_pid(85, DRIVE_SPEED);
  chassis.wait_drive();
  //Turn to elev bar and go to it
  /*
  chassis.set_turn_pid(-120+180, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(100, DRIVE_SPEED*0.8, true, true);
  chassis.wait_drive();
  chassis.set_turn_pid(75, TURN_SPEED*0.25);
  chassis.wait_drive();
  chassis.set_drive_pid(5, DRIVE_SPEED*0.5);
  chassis.wait_drive();
  */
}


/* krishsBasicAuton()
 * Should get three triballs into the goals: match load, the one near elevation bar, and one in the center of the field (+1 point)
 * Uses the wings to get the triball out of the corner (+1 point)
 * Goes to the elevation bar and touches it (+1 point)
 * We're going to need to change/test all of the values because they are very rough approximations and guesses...
 */
void krishsBasicAuton() {
  /* Goal: Push match load triball into the net goal.
   * 1. Drive forward 90 inches, while pushing the matchload triball along with it.
   * 2. Back up 20 inches. Then, go forward 20 inches. The point of this is to back up and go forward again, ensuring that the triball truly has been pushed into the net goal.
   */
  chassis.set_drive_pid(90, DRIVE_SPEED, true, true); // Drive forward 90 inches
  chassis.wait_drive();
  chassis.set_drive_pid(-20, DRIVE_SPEED_FASTEST, true, true); // Drive backward 20 inches
  chassis.wait_drive();
  chassis.set_drive_pid(20, DRIVE_SPEED_FASTER, true, true); // Drive forward 20 inches
  chassis.wait_drive();

  /* Goal: Get the triball out of the corner using the wings
   * 1. Drive backwards 20 inches.
   * 2. Turn 180 degrees, to essentially be parallel with the corner of the field.
   * 3. Expand wings.
   * 4. Drive forward 10 inches. Hopefully by now the triball has been knocked out of the corner zone.
   * 5. Retract wings. 
   */
  chassis.set_drive_pid(-20, DRIVE_SPEED_FASTEST, true, true);
  chassis.wait_drive();
  chassis.set_turn_pid(180, TURN_SPEED_FASTER);
  chassis.wait_drive();
  wings.set_value(true);
  //pros::delay(250);
  chassis.set_drive_pid(10, DRIVE_SPEED, true, true);
  wings.set_value(false);
  //pros::delay(250);

  /* Goal: Touch the elevation bar.
   * 1. Turn 30 degrees, to be perpendicular to the elevation bar.
   * 2. Drive forward 15 inches.
   * 3. Raise catapult.
   * 4. Drive forward 5 inches.
   */
  chassis.set_turn_pid(30, DRIVE_SPEED_FASTER);
  chassis.wait_drive();
  chassis.set_drive_pid(15, DRIVE_SPEED_FASTEST, true, true);
  chassis.wait_drive();
  //slap.move_voltage(7500); // I honestly have no fxcking clue if this is how the slap part works because after Joseph changed this part, I lowkey kinda got lost.
  //pros::delay(250);
  chassis.set_drive_pid(5, DRIVE_SPEED, true, true);
}

void offensive_middle() {
  //Drop off match load in the middle
  chassis.set_drive_pid(-118, DRIVE_SPEED, true);
  chassis.wait_drive();
  //Turn to triball on the pipe
  chassis.set_turn_pid(80, TURN_SPEED);
  chassis.wait_drive();
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
  
}



void defensive_alli_bar() {
  //Push alliance tri ball in
  chassis.set_drive_pid(-85, DRIVE_SPEED*0.8, true);
  chassis.wait_drive();
  //Steal triball out of defensive goal
  chassis.set_turn_pid(25, TURN_SPEED);
  chassis.wait_drive();
  //drive to go to steal zone
  chassis.set_drive_pid(60, DRIVE_SPEED*0.8);
  chassis.wait_drive();
  //extend wings out
  wings.set_value(true);
  //turn to pull it out
  chassis.set_turn_pid(-10, TURN_SPEED);
  chassis.wait_drive();
  //swing to steal the triball
  chassis.set_swing_pid(RIGHT_SWING, -50, SWING_SPEED);
  chassis.wait_drive();
  //steal the triball
  //chassis.set_drive_pid(45, DRIVE_SPEED*0.8);
  //chassis.wait_drive();
  //turn upfield to bar
  chassis.set_turn_pid(-65, TURN_SPEED);
  chassis.wait_drive();
  //bring wings back in
  wings.set_value(false);
  //go toward bar
  chassis.set_drive_pid(70, DRIVE_SPEED*0.8);
  chassis.wait_drive();
  //turn n touch the bar
  chassis.set_turn_pid(-80, TURN_SPEED);
  chassis.wait_drive();
  //at this point we are facing close
  chassis.set_drive_pid(30, DRIVE_SPEED);
  chassis.wait_drive();
  //outtake
  intake.move_velocity(-600);
  pros::delay(400);
  intake.move_velocity(0);
  //actually turn n touch the bar
  chassis.set_turn_pid(-115, TURN_SPEED);
  chassis.wait_drive();
}


void krishsOptimizedTriballAuton() {
  /* Goal: Knock triball outta corner
   * 1. Drive forward 5 inches.
   * 2. Expand Wings.
   * 3. Drive forward 5 inches.
   * 4. Retract wings.
   */
  chassis.set_drive_pid(-5, DRIVE_SPEED_FASTER, true);
  chassis.wait_drive();
  wings.set_value(true);
  //pros::delay(50);
  chassis.set_drive_pid(-45, DRIVE_SPEED_FASTER, true);
  chassis.wait_drive();
  //wings.set_value(true);
  //pros::delay(50);
  /* Goal: Push matchload and corner triball into goal
   * 1. Turn 60 degrees.
   * 2. Drive forward 10 inches.
   */
  chassis.set_turn_pid(-40, TURN_SPEED_FASTEST);
  chassis.wait_drive();
  chassis.set_drive_pid(-75, DRIVE_SPEED_FASTEST);
  chassis.wait_drive();
  wings.set_value(false);

  /* Goal: Back up
   * 1. Drive backwards 8 inches.
   * 2. Turn 60 degrees.
   */
  chassis.set_drive_pid(35, TURN_SPEED_FASTEST);
  chassis.wait_drive();
  chassis.set_turn_pid(135, TURN_SPEED_FASTEST);

  /* Goal: Drive towards center of the field and get the triball
   * 1. Drive 25 inches forward.
   * 2. Start intake.
   * 3. Turn 180 degrees so that the intake is facing towards the goal.
   
  chassis.set_drive_pid(-25, DRIVE_SPEED_FASTEST);
  intake.move_velocity(spinVoltage);
  pros::delay(250);
  chassis.set_turn_pid(180, TURN_SPEED);
  
   Goal: Drive forward a little bit then outake near the goal.
   * 1. Drive 10 inches forward.
   * 2. Start outake.
   * 3. Turn 180 degrees so that the bot is facing towards the center of the field
   

  chassis.set_drive_pid(-10, DRIVE_SPEED_FASTEST);
  chassis.wait_drive();
  intake.move_velocity(-1*spinVoltage);
  pros::delay(250);
  intake.move_velocity(0);
  chassis.set_turn_pid(180, TURN_SPEED_FASTEST);
  chassis.wait_drive();

  
   Goal: Drive to the absolute center of the field and get the triball
   * 1. Drive 10 inches forward.
   * 2. Start outake.
   * 3. Expand wings and knock all 3 into goal
   
  
  chassis.set_drive_pid(10, DRIVE_SPEED);
  chassis.wait_drive();
  intake.move_velocity(-1*spinVoltage);
  pros::delay(250);
  intake.move_velocity(0);
  wings.set_value(true);
  chassis.set_drive_pid(25, DRIVE_SPEED);
  */
  
  // then we needa go forward and outake
  // then, we're goin back and getting center middle triball
  // turning around
  // expaning wings
  // and pushing all three triballs in
  // we should have 5 triballs into the goal at the end

  /*
  // Comment the rest of this code.
  chassis.set_turn_pid(20, TURN_SPEED_FASTEST);
  chassis.wait_drive();
  wings.set_value(true);
  chassis.set_drive_pid(-7, DRIVE_SPEED_FASTEST, true);
  wings.set_value(false);
  chassis.set_drive_pid(5, DRIVE_SPEED_FASTEST, true);
  chassis.set_turn_pid(135, TURN_SPEED_FASTEST);
  chassis.wait_drive();
  chassis.set_drive_pid(-7, DRIVE_SPEED_FASTEST, true);
  intake.move_velocity(400);
  chassis.wait_drive();
  chassis.set_turn_pid(180, TURN_SPEED_FASTEST);
  chassis.wait_drive();
  chassis.set_drive_pid(-7, DRIVE_SPEED_FASTEST, true);
  intake.move_velocity(-400);
  chassis.set_turn_pid(90, TURN_SPEED_FASTEST);
  chassis.wait_drive();
  chassis.set_drive_pid(-3, DRIVE_SPEED_FASTEST, true);
  chassis.wait_drive();
  chassis.set_turn_pid(90, TURN_SPEED_FASTEST);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, DRIVE_SPEED_FASTEST, true);
  intake.move_velocity(400);
  chassis.set_drive_pid(-1, DRIVE_SPEED_FASTEST, true);
  chassis.wait_drive();
  intake.move_velocity(0);
  chassis.set_turn_pid(180, TURN_SPEED_FASTEST);
  wings.set_value(true);
  chassis.set_drive_pid(-10, DRIVE_SPEED_FASTEST, true);
  chassis.wait_drive();
  chassis.set_turn_pid(-110, TURN_SPEED_FASTEST);
  chassis.set_drive_pid(-4, DRIVE_SPEED_FASTEST, true);
  chassis.wait_drive();
  chassis.set_turn_pid(70, TURN_SPEED_FASTEST);
  chassis.set_drive_pid(-4, DRIVE_SPEED_FASTEST, true);
  slap.move_voltage(7500);




  

  // Below is the old auton code... i realized all we gotta do is j get match load triball, triball outta corner, and touch elevation bar
  // Move backwards and intake first triball near the elevation ball
  chassis.set_drive_pid(-7, DRIVE_SPEED*1.5);
  chassis.wait_drive();
  intake.move_velocity(600);
  chassis.wait_drive();
  chassis.set_drive_pid(-3, DRIVE_SPEED);
  pros::delay(250);
  intake.move_velocity(0);

  // Return to starting position
  chassis.set_drive_pid(10, DRIVE_SPEED*2);

  // Move forward, expand wings to knock triball out from the corner, retract wings, and continue moving forward
  chassis.set_drive_pid(15, DRIVE_SPEED*1.5);
  wings.set_value(true);
  chassis.set_drive_pid(5, DRIVE_SPEED);
  wings.set_value(false);
  chassis.set_drive_pid(20, DRIVE_SPEED);
  chassis.wait_drive();

  // Back out and go back forward to ram triball into net goal 
  chassis.set_drive_pid(-7, DRIVE_SPEED*1.5);
  chassis.wait_drive();
  chassis.set_drive_pid(7, DRIVE_SPEED*1.5);

  // Rotate robot 180 degrees so that the intake is facing the net goal and we can put the triball that we first intaked into the goal
  chassis.set_drive_pid(-5, DRIVE_SPEED*1.5);
  chassis.wait_drive();
  chassis.set_turn_pid(180, TURN_SPEED*1.5);
  chassis.wait_drive();
  chassis.set_drive_pid(4, DRIVE_SPEED);
  intake.move_velocity(-500);
  pros::delay(250);
  intake.move_velocity(0);
  chassis.set_drive_pid(2, DRIVE_SPEED);
  chassis.wait_drive();
  // Back robot out and then go back forward to ram triball into goal
  chassis.set_drive_pid(-7, DRIVE_SPEED*1.5);
  chassis.wait_drive();
  chassis.set_drive_pid(7, DRIVE_SPEED);
  chassis.wait_drive();

  // Turn towards center of the field
  chassis.set_turn_pid(0, TURN_SPEED*1.25);
  chassis.wait_drive();

  // Drive towards center of field, intake triball, rotate robot 180 degrees, drive towards net goal, and outake
  chassis.set_drive_pid(15, DRIVE_SPEED*1.5);
  chassis.wait_drive();
  intake.move_velocity(600);
  pros::delay(250);
  intake.move_velocity(0);
  chassis.set_turn_pid(180, TURN_SPEED*1.5);
  chassis.set_drive_pid(15, DRIVE_SPEED);
  intake.move_velocity(-600);
  pros::delay(250);
  intake.move_velocity(0);
  chassis.set_drive_pid(-7, DRIVE_SPEED*1.5);
  chassis.wait_drive();
  chassis.set_drive_pid(7, DRIVE_SPEED);
  chassis.wait_drive();

  // Return to the starting position and then drive backwards to the elevation bar to touch it
  chassis.set_turn_pid(90, TURN_SPEED*1.5);
  chassis.wait_drive();
  chassis.set_drive_pid(25, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(-90, TURN_SPEED*1.5);
  chassis.wait_drive();
  chassis.set_drive_pid(-8, DRIVE_SPEED);
  chassis.wait_drive();
  // Raise catapult so that it touches elevation bars
  slap.move_voltage(7500); // I honestly have no fxcking clue if this is how the slap part works because after Joseph changed this part, I lowkey kinda got lost.



  */
}

void near_side_tri()
{
  // Drop one into the goal
  chassis.set_drive_pid(90, 127, true, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-20, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(40, 127);
  chassis.wait_drive();
  // Positioning for start
  chassis.set_drive_pid(-30, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(120, TURN_SPEED);
}

void near_side_bar()
{
  chassis.set_drive_pid(90, 127, true, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-20, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(40, 127);
  chassis.wait_drive();
  // Move backward out
  chassis.set_drive_pid(-85, DRIVE_SPEED);
  chassis.wait_drive();
  // Turn to elev bar and go to it
  chassis.set_turn_pid(-120 + 180, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-100, DRIVE_SPEED * 0.8, true, true);
  chassis.wait_drive();
  chassis.set_turn_pid(75, TURN_SPEED * 0.25);
  chassis.wait_drive();
  chassis.set_drive_pid(-5, DRIVE_SPEED * 0.5);
  chassis.wait_drive();
}

// skills auton: spam tribals
void skills_auton()
{
  // Push straight into the close goal (1 tribal)
  //wings.set_value(true);
  chassis.set_drive_pid(-90, 127, true, true);
  chassis.wait_drive();
  //wings.set_value(false);
  chassis.set_drive_pid(20, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(-40, 127);
  chassis.wait_drive();
  //moveintake.set_value(true);
  // Move backward out
  chassis.set_drive_pid(60, DRIVE_SPEED);
  chassis.wait_drive();
  // Turn to goal
  chassis.set_turn_pid(115, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(35, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(112.5, TURN_SPEED);
  chassis.wait_drive();
  // Spam
  slap.move_voltage(8000);
  pros::delay(37000);
  slap.move_voltage(0);
  // Turn to go under bar
  chassis.set_turn_pid(150, TURN_SPEED);
  chassis.wait_drive();
  // Go under neath the bar
  chassis.set_drive_pid(-150, DRIVE_SPEED, true, true);
  chassis.wait_drive();
  /// the one where it goes to the side
  // Open wings and swing to push
  wings.set_value(true);
  chassis.set_drive_pid(-30, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(120, TURN_SPEED);
  chassis.wait_drive();
  // RAM into goal
  chassis.set_drive_pid(-60, 127, true, true);
  chassis.wait_drive();
  chassis.set_drive_pid(40, 127, true, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-60, 127, true, true);
  chassis.wait_drive();
  chassis.set_drive_pid(40, 127, true, true);
  chassis.wait_drive();
  // Turn back to go to bar for elev
  wings.set_value(false);
  chassis.set_drive_pid(50, DRIVE_SPEED);
  chassis.wait_drive();
  chassis.set_turn_pid(120, TURN_SPEED);
  chassis.wait_drive();
  // Hang time for bar
  chassis.set_drive_pid(140, 120, true, true);
  chassis.wait_drive();
  chassis.set_drive_pid(20, 127);
  chassis.wait_drive();
  /*
  /// the one where it goes to the middle
  //Turn away from the thing
  chassis.set_turn_pid(-20, TURN_SPEED);
  chassis.wait_drive();
  //Drive toward the tribals
  chassis.set_drive_pid(-100, DRIVE_SPEED, true, true);
  chassis.wait_drive();
  //Turn toward goal
  chassis.set_turn_pid(150, TURN_SPEED);
  chassis.wait_drive();
  //RAM into
  wings.set_value(true);
  chassis.set_drive_pid(-60, 127, true, true);
  chassis.wait_drive();
  chassis.set_drive_pid(40, 127, true, true);
  chassis.wait_drive();
  chassis.set_drive_pid(-60, 127, true, true);
  chassis.wait_drive();
  chassis.set_drive_pid(40, 127, true, true);
  chassis.wait_drive();
  //Go to bar for elev
  chassis.set_turn_pid(180, TURN_SPEED);
  chassis.wait_drive();
  chassis.set_drive_pid(32, DRIVE_SPEED);
  chassis.wait_drive();
  */
}

///
// Drive Example
///
void drive_example()
{
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
void turn_example()
{
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
void drive_and_turn()
{
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
void wait_until_change_speed()
{
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
void swing_example()
{
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
void combining_movements()
{
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
void tug(int attempts)
{
  for (int i = 0; i < attempts - 1; i++)
  {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered)
    {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else
    {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees.
// If interfered, robot will drive forward and then attempt to drive backwards.
void interfered_example()
{
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  if (chassis.interfered)
  {
    tug(3);
    return;
  }

  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
}

// . . .
// Make your own autonomous functions here!
// . . .