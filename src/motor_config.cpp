#include "main.h"

pros::Motor intake(1, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor cata(3, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);

//pros::ADIDigitalOut moveintake('B');
pros::ADIDigitalOut wings('A');
pros::ADIDigitalOut elev('B');
//pros::ADIDigitalIn limitSwitch('C');

pros::Rotation kickerRotation(1);




