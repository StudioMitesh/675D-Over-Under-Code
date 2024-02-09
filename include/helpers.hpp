#include "api.h"
#include "drive.hpp"
#include "lemlib.hpp"
#include "motor_config.hpp"

void intakes();
void outtake();
void startouttake();
void stopouttake();
void autowings(bool set);
void leftwings(bool set);
void rightwings(bool set);
void bothfrontwings(bool set);
void backwings(bool set);
void releaseIntake();
void autoCata(double spinny, double t);
void hangtime();