#include "main.h"

bool wingspos = false; //false is in, true is out
bool isMoving = true;
bool kickerToggle = true;
const double targetAngle = 2425;
const int spinVoltage = 11000;
bool shouldLoad = true;


void intaker() {
    //intake
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1) == 1) {
        intake.move_velocity(400);
    }
    //ramp up intake speed
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT) == 1) {
        intake.move_velocity(400);
    }
    //outtake
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1) {
        intake.move_velocity(400);
    }
    else {
        intake.move_velocity(0);
    }
}

/*
void catawow(void* param) {
        if (limitSwitch.get_value() == 1) {
              if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1)
              {
                cata.move_relative(55, 600);
              }
              else
              {
                cata.move_velocity(0);
        }
        else {
            cata.move_velocity(50);
        }


        pros::delay(20); 
}

*/

void updateCatapult() {
    if(kickerRotation.get_angle() > targetAngle) {
        cata.move_voltage(spinVoltage);
        pros::lcd::print(0, "Loading..."); // Debugging
    } else {
        cata.move_voltage(0);
        pros::lcd::print(3, "Kicker Angle: %f", kickerRotation.get_angle());
        pros::lcd::print(0, "Stopped loading"); // Debugging
    }
}

void fireAndReload() {
    // Spin the catapult for the defined duration to fire
    cata.move_relative(80, 600);
    pros::lcd::print(1, "Firing!"); // Debugging

    pros::delay(300);

    // Reset the rotation sensor for consistency
    kickerRotation.reset();

    // Signal to start loading again

    return;
}

void monitorButtonAndFire() {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == 1) {
        cata.move_velocity(600);
        }
}


void move_the_intake() {

        //pulls the intake back, false is in
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X) == 1) {
            moveintake.set_value(false);
        } 
        //pushes the intake forward, true is out
        else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B) == 1) {
            moveintake.set_value(true);
        }
}

void move_wings() {
        //wings false state is in, true state is out
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A) == 1) {
            //if false, set true and move wings out
                wings.set_value(true);
                wingspos = true;
            //if true, set false and move wings back in

        } 
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y) == 1) {
            //if false, set true and move wings out
                wings.set_value(false);
                wingspos = false;
            //if true, set false and move wings back in

        } 
}


