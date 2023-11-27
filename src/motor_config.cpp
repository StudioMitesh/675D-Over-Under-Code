#include "main.h"

using namespace pros;

Controller master (E_CONTROLLER_MASTER);

Imu imu(2);

Motor leftFront(20, E_MOTOR_GEARSET_06, true);
Motor leftMid(9, E_MOTOR_GEARSET_06, true);
Motor leftBack(10, E_MOTOR_GEARSET_06, true);

Motor rightFront(4, E_MOTOR_GEARSET_06, false);
Motor rightMid(5, E_MOTOR_GEARSET_06, false);
Motor rightBack(11, E_MOTOR_GEARSET_06, false);

Motor_Group leftMotors({leftFront, leftMid, leftBack});
Motor_Group rightMotors({rightFront, rightMid, rightBack});

Motor intake(1, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
Motor cata(3, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);

//pros::ADIDigitalOut moveintake('B');
ADIDigitalOut wings('A');
ADIDigitalOut elev('B');
//pros::ADIDigitalIn limitSwitch('C');





