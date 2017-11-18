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
  std::vector<Participant> m_participantRef;   //holds an vector of participants
  BetMessage * m_betMessageRef;
  RouletteWheel * game;
  void writeBank(Participant &);
  
public:
  BettingSystem();
  ~BettingSystem();

  void joinGame(Participant*);
  void leaveGame(Participant*);
  void getWinners();
  string getParticipantName(int);
  void sendBetMessage(int,int,int,int);
  void sendBetMessage();
};