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

int menuController();
void mainmenu(int&);
void betmenu(int&);
void playermenu(int&);
void exitcode();

int fetchType();
int fetchTValue();
int fetchWager();

#endif