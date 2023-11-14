#include "main.h"

bool wingspos = false; //false is in, true is out
bool isMoving = true;
bool kickerToggle = true;
const double targetAngle = 19870;
const double targAngle2 = 22525;
const int spinVoltage = 10000;
bool shouldLoad = true;
bool allthewaydown = true;


void intaker() {
    // if (L1) then intake
    if (master.get_digital(E_CONTROLLER_DIGITAL_L2)) {
        intake.move_velocity(400);
    }
    
    // if (L1) then outtake
    else if (master.get_digital(E_CONTROLLER_DIGITAL_L1)) {
        intake.move_velocity(-400);
    }

    // else then do not run intake motor
    else {
        intake.move_velocity(0);
    }
}

void catapult() {
    while (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            cata.move_velocity(spinVoltage);
    }
    cata.move_velocity(0);
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
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        allthewaydown = true;
        cata.move_velocity(600);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        allthewaydown = false;
        cata.move_velocity(600);
    }
}

void move_wings() {
        //wings false state is in, true state is out
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
            //if false, set true and move wings out
                wings.set_value(true);
                wingspos = true;
            //if true, set false and move wings back in

        } 
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
            //if false, set true and move wings out
                wings.set_value(false);
                wingspos = false;
            //if true, set false and move wings back in

        } 
}

void move_elevation() {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        elev.set_value(true);
    }

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
        elev.set_value(false);
    }
}


