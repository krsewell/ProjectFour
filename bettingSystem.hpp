#ifndef BETTINGSYSTEM_H_INCL_GUARD
#define BETTINGSYSTEM_H_INCL_GUARD

#include <iostream>
#include <string>
#include <locale>
#include "roulette.hpp"
#include "betmessage.hpp"
#include "participant.hpp"

using std::cout;

#endif

class BettingSystem {
private:
  Participant * m_participantRef[10];   //holds a pointer for an array of participants 
  BetMessage & m_betMessageRef;     //holds a pointer for an array of betMessages

  void writeParticipant();
  void writeBank(Participant);
  // established rules for bets <methods>
  // way to implement payouts <private methods>
  
public:
  // way for participants to place bets <methods>
};