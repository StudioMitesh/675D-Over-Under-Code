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
    // while (R1) catapult runs
    while (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            cata.move_velocity(spinVoltage);
    }

    // if not, then catapult does not
    cata.move_velocity(0);
}

void move_wings() {
        // if (X) then wings out
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
                wings.set_value(true); // wings value true means wings are expanded
        } 

        // if (B) then wings in
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
                wings.set_value(false); // wings value false means wings are retracted
        } 
}

void move_elevation() {
    // if (RIGHT ARROW) then elevation out
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        elev.set_value(true);
    }

    // if (DOWN ARROW) then elevation in
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
        elev.set_value(false);
    }
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
