#include "./pid.h"

// point plotter with the boundries already set
// just paste the content of altitude.out in the text box and the points will be plotted
// http://fooplot.com#W3sidHlwZSI6MywiZXEiOltdLCJjb2xvciI6IiMwMDAwMDAifSx7InR5cGUiOjEwMDAsIndpbmRvdyI6WyItMTkuOTA5MDY5ODk2NDQ5NTEiLCIxMDYyLjM4NTEwMDc3NjYyNzMiLCItMTg1Ni4xMzY3Nzk3ODUxNTQ0IiwiMTc5Ni44MTczMjE3NzczNDU2Il19XQ--

// mentions, you can only use the following functions
// to get the error from the target altitude
// double read_error(void)
// to give commands to the mottors
// valid input: 0 - 4000
// void set_motor_command(int command)


void loop() {
  // TO_DO
  // a PID controller
  set_motor_command(5000);
}

void set_motor_command(int command) {
  Linker::get_instance()->give_command(command);
}

double read_error() {
  return Linker::get_instance()->get_error();
}