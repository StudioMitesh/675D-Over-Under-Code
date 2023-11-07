#include "main.h"


//put in opcontrol initialize
void reset_drive_sensors() {
  left_front_motor.tare_position();
  right_front_motor.tare_position();

}

// Left curve function
double left_curve_function(double x) {
    double left_curve_scale = 3;
  if (3 != 0) {
    // if (CURVE_TYPE)
    return (powf(2.718, -(3 / 10)) + powf(2.718, (fabs(x) - 127) / 10) * (1 - powf(2.718, -(3 / 10)))) * x;
    // else
    // return powf(2.718, ((abs(x)-127)*RIGHT_CURVE_SCALE)/100)*x;
  }
  return x;
}

// Right curve fnuction
double right_curve_function(double x) {
    double right_curve_scale = 3;
  if (3 != 0) {
    // if (CURVE_TYPE)
    return (powf(2.718, -(3 / 10)) + powf(2.718, (fabs(x) - 127) / 10) * (1 - powf(2.718, -(3 / 10)))) * x;
    // else
    // return powf(2.718, ((abs(x)-127)*RIGHT_CURVE_SCALE)/100)*x;
  }
  return x;
}
void set_tank(int left, int right) {
  if (pros::millis() < 1500) return;

    leftMotors.move_voltage(left * (12000.0 / 127.0));  // If the motor is in the pto list, don't do anything to the motor.
  
  
    rightMotors.move_voltage(right * (12000.0 / 127.0));  // If the motor is in the pto list, don't do anything to the motor.
  
}
int left_sensor(){
    return left_front_motor.get_position();
}
int right_sensor(){
    return right_front_motor.get_position();
}
void joy_thresh_opcontrol(int l_stick, int r_stick) {
    int JOYSTICK_THRESHOLD = 5;
    double active_brake_kp = .05;
  // Threshold if joysticks don't come back to perfect 0
  if (abs(l_stick) > JOYSTICK_THRESHOLD || abs(r_stick) > JOYSTICK_THRESHOLD) {
    set_tank(l_stick, r_stick);
    if (active_brake_kp != 0) reset_drive_sensors();
  }
  //When joys are released, run active brake (P) on drive
  else {
    set_tank((0 - left_sensor()) * active_brake_kp, (0 - right_sensor()) * active_brake_kp);
  }
}


void arcade_flipped() {

  while(true){

  int turn_stick, fwd_stick;
  
    // Put the joysticks through the curve function
    fwd_stick = right_curve_function(master.get_analog(ANALOG_LEFT_Y));
    turn_stick = left_curve_function(master.get_analog(ANALOG_RIGHT_X));
  

  // Set robot to l_stick and r_stick, check joystick threshold, set active brake
  joy_thresh_opcontrol(fwd_stick + turn_stick, fwd_stick - turn_stick);}
}