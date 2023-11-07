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
    20,
    30,
    1,
    100,
    3,
    500,
    5
};

ChassisController_t angularController{
    10,
    40,
    1,
    100,
    3,
    500,
    50
};

Chassis chassis(drivetrain, lateralController, angularController, sensors);