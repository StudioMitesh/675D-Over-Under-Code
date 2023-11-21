#include "main.h"

bool wingspos = false; //false is in, true is out
bool isMoving = true;
bool kickerToggle = true;
const double targetAngle = 19870;
const double targAngle2 = 22525;
const int spinVoltage = 9500;
bool shouldLoad = true;
bool allthewaydown = true;


void intaker() {
    //outtake
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        intake.move_velocity(-400);
    }
    //ramp up intake speed
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        intake.move_velocity(400);
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
    
    while (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            cata.move_velocity(spinVoltage);
            allthewaydown = !allthewaydown;
    }
    cata.move_velocity(0);
    allthewaydown = !allthewaydown;
    
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
            allthewaydown = true;
            cata.move_velocity(600);
        }
        else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            allthewaydown = false;
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
        //wings false state is in, true state is out
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
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
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
        elev.set_value(true);
    }

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
        elev.set_value(false);
    }
}

