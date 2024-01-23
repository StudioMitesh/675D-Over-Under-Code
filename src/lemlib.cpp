#include "main.h"

using namespace lemlib;

Drivetrain drivetrain{
    &leftMotors,
    &rightMotors,
    10.2,
    2.75,
    480,
    2
};

OdomSensors sensors{
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &imu
};

ControllerSettings lateralController{
    11,
    0,
    30,
    0,
    1,
    100,
    3,
    500,
    20
};

ControllerSettings angularController{
    6,
    0,
    37,
    0,
    1,
    100,
    3,
    500,
    20
};

Chassis chassis(drivetrain, lateralController, angularController, sensors);