#ifndef BETTINGSYSTEM_H_INCL_GUARD
#define BETTINGSYSTEM_H_INCL_GUARD

#include <iostream>
#include <string>
#include <locale>
#include <cstdlib>
#include "roulette.hpp"
#include "betmessage.hpp"
#include "participant.hpp"
#include "globalTools.hpp"

#endif

class BettingSystem {
private:
  std::vector<Participant*> m_player;   //holds a vector of participants
  RouletteWheel * game;
  
public:
  BettingSystem();
  ~BettingSystem();

  void joinGame(Participant*);
  void leaveGame(Participant*);
  void getWinners();
  string getParticipantName(Participant*);
};