#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void disp() {
    // loop forever
    while (true) {
       	lemlib::Pose pose = chassis.getPose(); // get the current position of the robot
        pros::lcd::print(3, "x: %f", pose.x); // print the x position
        pros::lcd::print(4, "y: %f", pose.y); // print the y position
        pros::lcd::print(5, "heading: %f", pose.theta); // print the heading
        pros::delay(10);
		/*
		master.clear();
		master.print(0, 0, "RAmp %.2lf", kickerRight.get_current_draw());
		master.print(0, 8, "Rtor %.2lf", kickerRight.get_torque());
		master.print(1, 0, "LAmp %.2lf", kickerLeft.get_current_draw());
		master.print(1, 8, "Ltor %.2lf", kickerLeft.get_torque());
		*/
	master.print(0, 0, "good luck");
	
    }
}
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	
	
	leftFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	leftMid.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	leftBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	rightFront.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	rightMid.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	rightBack.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	pros::lcd::initialize();
	pros::lcd::set_text(1, "675D on top :)");
	

	reset_drive_sensors();
	
	chassis.calibrate();
	chassis.setPose({0,0,0});

	pros::Task displayTask(disp);
	
	
	
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	//offensive autons
	offensive_six();
	//new_offensive();

	//defensive autons
	//simple_d_awp();
	//defensive_elim();

	//skills auton
	//skills_auton();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

	master.clear();
	reset_drive_sensors();
	
	pros::Task driveTask(arcade_flipped);
	//pros::Task cataTask(monitorButtonAndFire);
	while(true) {
		intaker();
		updateCatapult();
		move_wings();
		move_elevation();
	}
		//Task cataTask(catapult);
	
}
