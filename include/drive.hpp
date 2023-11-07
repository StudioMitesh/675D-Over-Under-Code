#pragma once
#include "api.h"

#include <functional>
#include <iostream>
#include <tuple>
#include "pros/motors.h"

void reset_drive_sensors();
int left_sensor();
int right_sensor();
  
double left_curve_function(double x);
double right_curve_function(double x);
void set_tank(int left, int right);
void joy_thresh_opcontrol(int l_stick, int r_stick);

void arcade_flipped();