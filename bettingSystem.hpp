/*
 *   kjs170430_Project4/bettingSystem.hpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 4
 */

#ifndef BETTINGSYSTEM_H_INCL_GUARD
#define BETTINGSYSTEM_H_INCL_GUARD

#include "roulette.hpp"
#include "betmessage.hpp"
#include "participant.hpp"
#include "globalTools.hpp"
#include <iostream>
#include <string>
#include <locale>
#include <cstdlib>

using std::string;

class Participant;

class BettingSystem {
private:
  std::vector<Participant*> m_player;   //holds a vector of participants
  RouletteWheel * game;

public:
  BettingSystem();
  ~BettingSystem();

  void joinGame(Participant&);
  void leaveGame(Participant&);
  void getWinners();
  string getParticipantName(Participant&);
};

#endif
