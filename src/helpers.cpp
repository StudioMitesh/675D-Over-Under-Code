#include "main.h"

using namespace pros;

int start = 0;

// intaker
void intakes() {
    pros::delay(100);
    intake.move_relative(-1440, 450);
    pros::delay(100);
}

// outaker
void outtake() {
    pros::delay(50);
    intake.move_relative(1440, 600);
    pros::delay(50);
}

//auto wings out
void autowings(bool set) {
    fwings.set_value(set);
}

void backwings(bool set) {
    bwings.set_value(set);
}

//spins the cata to release the intake down
void releaseIntake() {
    cata.move_relative(340, 100);
}

//constant fire the cata for set time at set voltage
void autoCata(double spinny, double t) {
    cata.move_voltage(spinny);
    pros::delay(t);
    cata.move_voltage(0);
}

//open the elevation w the piston
void hangtime() {
    elev.set_value(false);
}

/*
// load the kicker in position to fire
void load()
{
    // set motor speed of the kicker motorgroup using pid with the angle of a rotation sensor
    changeKickerSpeed(kickerRotation.get_angle());
    //kicker.move_voltage(-10000);
}

// auto fire the kicker making it constantly fire
void autoFire()
{
 
    // sets the voltage to -10V to make motor spin back to cycle at high speeds
    kicker.move_voltage(-10000);
}
// stop the kicker motors
void stop()
{
    // sets the kicker motors to 0V so they stop
    //kicker.move_voltage(0);
    kicker.brake();
}

// spin the intake
void intakes()
{
    intake.move_voltage(10000);
}
 
// function to fire whenever the kicker is loaded
void kick()
{
    // checks for when the button is pressed causing the motor to move at 10V for 3 seconds making it fire and load again
    if (master.get_digital(E_CONTROLLER_DIGITAL_R1))
    {   
        raiseIntake.set_value(true);
        delay(150);
        kicker.move_voltage(-10000);
        delay(750);
        loaded = false;
        kickerRotation.reset();
        
    }
    else if(master.get_digital(E_CONTROLLER_DIGITAL_R2)){
        kicker.move_voltage(10000);
        raiseIntake.set_value(false);
    }
    else if(master.get_digital(E_CONTROLLER_DIGITAL_X)){
        raiseIntake.set_value(false);
    }
    // if it is loaded but pressing the button the motors will not move
    //kicker.brake();
    else{
    kicker.move_voltage(0);}
}
// function using pid to set the voltage of the kicker to reach the angle most optimally
void changeKickerSpeed(int currentAngle)
{

    // sets the error to how many more degrees it needs to turn
    int error = targetAngle - currentAngle;

    // calculated by the tuned proportion constant and the error
    int proportional = roKp * error;

    // gets the total sum of the loop
    errorSum += error;
    int integral = roKi * errorSum;

    int derivative = roKd * (error - lastError);

    int motorSpeed = proportional + integral + derivative;

    kicker.move_voltage(-motorSpeed);

    lastError = error;
}


void fire(){
    cataToggle.set_value(false);
    while(kickerRotation.get_angle()<targetAngle){
        kicker.move_voltage(-10000);
    }
    if(kickerRotation.get_angle() > targetAngle){
    kicker.move_voltage(-10000);
    delay(500);
    kicker.move_voltage(0);}
    else{fire();}
   
}
void autoWing(bool setWings){
    wings.set_value(setWings);
}

*/