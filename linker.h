#ifndef LINKER_H
#define LINKER_H

#include <bits/stdc++.h>
#include "./drone.h"



class Linker {
  static Linker *instance;
  Linker() {}; // no object instance can be created

 public:
  std::mutex command_mutex;
  std::mutex error_mutex;
  int command;
  double error;

  static Linker* get_instance();

  static void give_command(int command);
  static int get_command();
  
  static void give_error(double error);
  static double get_error();
};

#endif // LINKER_H