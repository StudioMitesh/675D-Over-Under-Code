#include "main.h"

using namespace lemlib;

Drivetrain_t drivetrain{
    &leftMotors,
    &rightMotors,
    10.2,
    2.75,
    480
};

OdomSensors_t sensors{
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &imu
};

ChassisController_t lateralController{
    11,
    30,
    1,
    100,
    3,
    500,
    20
};

ChassisController_t angularController{
    6,
    37,
    1,
    100,
    3,
    500,
    20
};

Chassis chassis(drivetrain, lateralController, angularController, sensors);