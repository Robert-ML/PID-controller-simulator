#ifndef PID_H
#define PID_H

#include <bits/stdc++.h>
#include "./linker.h"

void loop();

void set_motor_command(int command);

double read_error();

#endif // PID_H