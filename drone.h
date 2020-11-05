#ifndef DRONE_H
#define DRONE_H

#include <bits/stdc++.h>
#include "./linker.h"

#define FILE_OUT "altitude.out"
#define SIM_TIME 10000// in U_SEC
#define PRINT_INTERVAl 10000

#define TARGET 1000
#define AIR_DENSITY 1.2754 // kg/m^3
#define DRONE_MASS 0.4 // kg
#define DRONE_TOP_AREA 0.018125 // m^2
#define DRONE_DRAG_COEFF 0.88 // approximate: a combination between the drag coefficient of a sqare and a 45 degree rotated square

#define IDEAL 0.15 // dictates the response of the mottors to the command
#define GROUND_LEVEL 0
#define INITIAL_ALTITUDE GROUND_LEVEL
#define INITIAL_ERROR (GROUND_LEVEL - TARGET) // the initial error from the target altitude
#define INITIAL_COMMAND 0
#define INITIAL_SPEED 0

#define TIME_STAMP_US 100 // bigger makes the drone calculate its next position slower
#define FROM_US_TO_S(x) (x / 1000000.0)

#define MAX_COMMAND 2000
#define MIN_COMMAND 0

#define FROM_COMMAND_TO_FORCE 0.02 
// For a maximum comand of 2000, we have the maximum up speed of 40m/s from
// whitch we subtract 10m/s
// #define MAX_SPEED_UP 30
#define GRAVITY -10
// #define MAX_SPEED (MAX_SPEED_UP - MAX_SPEED_DOWN)

void start_drone(const long duration);
double set_accel(int &past_command, int command, double speed);

void border_command(int &command);

#endif // DRONE_H