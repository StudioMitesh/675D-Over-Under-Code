#include "main.h"

pros::Motor intake(15, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor cata(21, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);

pros::ADIDigitalOut moveintake('A');
pros::ADIDigitalOut wings('B');