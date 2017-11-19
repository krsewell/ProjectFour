/*
 *   kjs170430_Project4/main.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 4
 */
#ifndef MAIN_H_INCL_GUARD
#define MAIN_H_INCL_GUARD


#include "menu.hpp"
#include "participant.hpp"

#endif


int main() {
  //initialize program start
  BettingSystem table;
  Participant customer;
  table.joinGame(customer);
  // mainmenu(&customer);

  //exit code here.

  return 0;
}
