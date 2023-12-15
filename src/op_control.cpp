#include "main.h"

/*
CONTROLLER OVERVIEW::
Drive type: tank
L1: Outtake
L2: Intake
R1: Slapper
R2: 

X: 
A: 
B: Elevation piston down/out
Y: Elevation piston up/in

Up: 
Right: Wings in/out macro
Down: Wings in/out macro
Left: Intake 1.5 times faster ?
*/


bool wingspos = false; //false is in, true is out
bool isMoving = true;
bool kickerToggle = true;
const double targetAngle = 19870;
const double targAngle2 = 22525;
const int spinVoltage = 10000;
bool shouldLoad = true;
bool movement = false;


void intaker() {
    //outtake
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        intake.move_velocity(-400);
    }
    //ramp up intake speed
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        intake.move_velocity(600);
    }
    //intake
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        intake.move_velocity(400);
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
    
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            if (!movement) {
                cata.move_voltage(spinVoltage);
            }
            else if (movement) {
                cata.move_voltage(0);
            }
            movement = !movement;
    }
    
    // put cata all the way down so we can intake into it
    /* if (allthewaydown) {
        if(kickerRotation.get_angle() < targetAngle && kickerRotation.get_angle() > targetAngle-5) {
            cata.move_voltage(0);
            pros::lcd::print(3, "Kicker Angle: %f", kickerRotation.get_angle());
            pros::lcd::print(0, "Stopped loading"); // Debugging
        }    
        else {
            cata.move_voltage(spinVoltage);
            pros::lcd::print(0, "Loading..."); // Debugging
        }
    }
    // haflway point down the cata, stops intaking and holds position
    else {
        if(kickerRotation.get_angle() < targAngle2 && kickerRotation.get_angle() > targAngle2-5) {
            cata.move_voltage(0);
            pros::lcd::print(3, "Kicker Angle: %f", kickerRotation.get_angle());
            pros::lcd::print(0, "Stopped loading"); // Debugging
        }    
        else {
            cata.move_voltage(spinVoltage);
            pros::lcd::print(0, "Loading..."); // Debugging
            
        }
    }

    
    if (allthewaydown) {
        if(kickerRotation.get_angle() > targetAngle || kickerRotation.get_angle() < targetAngle-15) {
            cata.move_voltage(spinVoltage);
            pros::lcd::print(0, "Loading..."); // Debugging
        }    
        else {
            cata.move_voltage(0);
            pros::lcd::print(3, "Kicker Angle: %f", kickerRotation.get_angle());
            pros::lcd::print(0, "Stopped loading"); // Debugging
        }
    }
    // haflway point down the cata, stops intaking and holds position
    else {
        if(kickerRotation.get_angle() > targAngle2 || kickerRotation.get_angle() < targAngle2-15) {
            cata.move_voltage(spinVoltage);
            pros::lcd::print(0, "Loading..."); // Debugging
        }    
        else {
            cata.move_voltage(0);
            pros::lcd::print(3, "Kicker Angle: %f", kickerRotation.get_angle());
            pros::lcd::print(0, "Stopped loading"); // Debugging
        }
    }
    */
   /*
    if (allthewaydown) {
        if(kickerRotation.get_angle() > targetAngle) {
            cata.move_voltage(spinVoltage);
            pros::lcd::print(0, "Loading..."); // Debugging
        }    
        else {
            cata.move_voltage(0);
            pros::lcd::print(3, "Kicker Angle: %f", kickerRotation.get_angle());
            pros::lcd::print(0, "Stopped loading"); // Debugging
        }
    }
    // haflway point down the cata, stops intaking and holds position
    else {
        if(kickerRotation.get_angle() > targAngle2) {
            cata.move_voltage(spinVoltage);
            pros::lcd::print(0, "Loading..."); // Debugging
        }    
        else {
            cata.move_voltage(0);
            pros::lcd::print(3, "Kicker Angle: %f", kickerRotation.get_angle());
            pros::lcd::print(0, "Stopped loading"); // Debugging
        }
    }   
    */

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

void move_wings() {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        wings.set_value(!wingspos);
        wingspos = !wingspos;
        pros::delay(300);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
        wings.set_value(!wingspos);
        wingspos = !wingspos;
        pros::delay(300);
    }
}

void move_elevation() {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
        elev.set_value(true);
    }

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        elev.set_value(false);
    }
}

