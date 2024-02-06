#include "main.h"

using namespace pros;

Controller master (E_CONTROLLER_MASTER);

Imu imu(21);

Motor leftFront(20, E_MOTOR_GEARSET_06, true);
Motor leftMid(19, E_MOTOR_GEARSET_06, true);
Motor leftBack(10, E_MOTOR_GEARSET_06, true);

Motor rightFront(11, E_MOTOR_GEARSET_06, false);
Motor rightMid(13, E_MOTOR_GEARSET_06, false);
Motor rightBack(12, E_MOTOR_GEARSET_06, false);

Motor_Group leftMotors({leftFront, leftMid, leftBack});
Motor_Group rightMotors({rightFront, rightMid, rightBack});

Motor intake(1, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);
Motor cata(9, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);

//pros::ADIDigitalOut moveintake('B');
ADIDigitalOut bwings('A');
ADIDigitalOut elev('B');
ADIDigitalOut fwings('C');
//pros::ADIDigitalIn limitSwitch('C');