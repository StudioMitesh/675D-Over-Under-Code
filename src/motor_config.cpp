#include "main.h"

pros::Motor intake(10, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
pros::Motor cata(1, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);

pros::ADIDigitalOut moveintake('A');