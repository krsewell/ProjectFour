#ifndef MENU_H_INCL_GUARD
#define MENU_H_INCL_GUARD

#include <iostream>
#include <iomanip>
#include "bettingSystem.hpp"
#include "roulette.hpp"
#include "globalTools.hpp"

using std::setw;

void mainmenu(Participant&,BettingSystem&);
void betmenu(Participant&);
void playermenu();
void exitcode();

void fetchType(int&,int&);
void fetchWager(int&,Participant&);

void printStats(Participant&);
int get0thru36();

#endif