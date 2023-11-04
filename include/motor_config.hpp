#include "api.h"
#include "pros/adi.hpp"
#include "pros/motors.h"

extern pros::Motor intake;
extern pros::Motor slap;

extern pros::ADIDigitalOut moveintake;
extern pros::ADIDigitalOut wings;
extern pros::ADIDigitalOut elev;

extern pros::ADIDigitalIn limitSwitch;

extern pros::Rotation kickerRotation;