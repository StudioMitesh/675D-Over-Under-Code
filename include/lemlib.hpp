#pragma once

#include "api.h"
#include "lemlib\api.hpp"

using namespace lemlib;


extern Drivetrain_t drivetrain;
extern OdomSensors_t sensors;
extern ChassisController_t lateralController;
extern ChassisController_t angularController;
extern lemlib::Chassis chassis;