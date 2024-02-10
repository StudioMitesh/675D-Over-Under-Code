#include "main.h"

/*
CONTROLLER OVERVIEW::
Drive type: arcade
L1: Outtake
L2: Intake
R1: Left wings
R2: Right wings

X: 
A: 
B: Catapult to pos
Y: Back wings

Up: 
Right: Slapper
Down: Outtake full speed
Left: 
*/

bool elevpos = true;
bool backpos = false; //false is in, true is out
bool leftpos = false;
bool rightpos = false;
bool isMoving = true;
bool kickerToggle = true;
const double targetAngle = 19870;
const double targAngle2 = 22525;
const int spinVoltage = 12000;
bool shouldLoad = true;
bool movement = false;


void intaker() {
    //outtake
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        intake.move_velocity(600);
    }
    //ramp up outtake speed
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        intake.move_velocity(300);
    }
    //intake
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        intake.move_velocity(-300);
    }
    else {
        intake.move_velocity(0);
    }
}

/*
void catawow() {
        if (limitSwitch.get_value() == true) {
            if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
                cata.move_relative(55, 600);
            }
            else {
                cata.move_velocity(0);
            }
        }
        else {
            cata.move_velocity(50);
        }


        pros::delay(20); 
}
*/


void updateCatapult() {
    while (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            if (!movement) {
                cata.move_voltage(spinVoltage);
            }
            else if (movement) {
                cata.move_voltage(0);
            }
            movement = !movement;
            pros::delay(200);
    }
}

void setPosition() {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        cata.move_absolute(180, 300);
    }
}


void fireAndReload() {
    while(true) {

        // Spin the catapult for the defined duration to fire
        cata.move_relative(80, 600);
        pros::lcd::print(1, "Firing!"); // Debugging

        pros::delay(300);

        // Reset the rotation sensor for consistency
        kickerRotation.reset();

        // Signal to start loading again

        return;
    }
}

void monitorButtonAndFire() {
    while(true) {
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            movement = true;
            cata.move_velocity(600);
        }
        else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            movement = false;
            cata.move_velocity(600);
        }
    }
}

/*
void move_the_intake() {

        //pulls the intake back, false is in
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
            moveintake.set_value(false);
        } 
        //pushes the intake forward, true is out
        else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
            moveintake.set_value(true);
        }
}
*/

void move_front_wings() {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        leftwing.set_value(!leftpos);
        rightwing.set_value(!rightpos);
        leftpos = !leftpos;
        rightpos = !rightpos;
        pros::delay(300);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        leftwing.set_value(!leftpos);
        leftpos = !leftpos;
        pros::delay(300);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        rightwing.set_value(!rightpos);
        rightpos = !rightpos;
        pros::delay(300);
    }
}

void move_back_wings() {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
        bwings.set_value(!backpos);
        backpos = !backpos;
        pros::delay(300);
    }
}

void move_elevation() {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
        elev.set_value(!elevpos);
        elevpos = !elevpos;
        pros::delay(350);
    }
}

