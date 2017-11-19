#ifndef MENU_H_INCL_GUARD
#define MENU_H_INCL_GUARD

#include <iostream>
#include <iomanip>
#include "bettingSystem.hpp"
#include "roulette.hpp"
#include "globalTools.hpp"

extern BettingSystem house;
extern RouletteWheel game;

using std::setw;

void menuController();
void mainmenu();
void betmenu();
void playermenu();
void exitcode();

int fetchType();
int fetchTValue();
int fetchWager();

#endif