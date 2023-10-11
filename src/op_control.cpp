#include "main.h"



void intaker() {
    //intake
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        intake.move_velocity(215);
    }
    //ramp up intake speed
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
        intake.move_velocity(400);
    }
    //outtake
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        intake.move_velocity(-215);
    }
    else {
        intake.move_velocity(0);
    }
}

void catawow() {
    //cata fire
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        cata.move_velocity(100);
    }
    //intake outtaking cata position
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        cata.move_relative(50, 100);
    }
    else {
        cata.move_velocity(0);
    }
}


void move_the_intake() {
    while (true) {
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
            moveintake.set_value(false);
        } 
        else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
            moveintake.set_value(true);
        }
    }
}

void move_wings() {
    while (true) {
        if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
            moveintake.set_value(false);
        } 
        else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
            moveintake.set_value(true);
        }
    }
}




void op_control() {
    intaker();
    catawow();
    move_the_intake();
}