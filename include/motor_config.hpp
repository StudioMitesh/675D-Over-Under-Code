#include "api.h"
#include "pros/adi.hpp"
#include "pros/motors.h"

extern pros::Controller master;
extern pros::Imu imu;

extern pros::Motor leftFront;
extern pros::Motor leftMid;
extern pros::Motor leftBack;

extern pros::Motor rightFront;
extern pros::Motor rightMid;
extern pros::Motor rightBack;

extern pros::Motor_Group leftMotors;
extern pros::Motor_Group rightMotors;

extern pros::Motor intake;
extern pros::Motor cata;

extern pros::ADIDigitalOut moveintake;
extern pros::ADIDigitalOut bwings;
extern pros::ADIDigitalOut fwings;
extern pros::ADIDigitalOut elev;

extern pros::ADIDigitalIn limitSwitch;

extern pros::Rotation kickerRotation;