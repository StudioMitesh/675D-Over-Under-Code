#include "api.h"
#include "pros/adi.hpp"
#include "pros/motors.h"

extern pros::Motor intake;
extern pros::Motor cata;

extern pros::ADIDigitalOut moveintake;
extern pros::ADIDigitalOut wings;

extern pros::ADIDigitalIn limitSwitch;

extern pros::Rotation kickerRotation;