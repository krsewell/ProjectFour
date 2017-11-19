#ifndef PARTICIPANT_H_INCL_GUARD
#define PARTICIPANT_H_INCL_GUARD

#include <iostream>
#include <string>
#include "bettingSystem.hpp"
#include "betmessage.hpp"

using std::string;

class BetMessage;
class BettingSystem;

class Participant {
private:
  
  string m_name;
  int m_bank;
  int m_totalGain;
  int m_spinGain;
  BetMessage ** m_bets;
  int SIZE;
  BettingSystem * m_CurrentBetTable;
   
  //declared private for use by betting system

  int getBetNum();
  

public:
  Participant();
  Participant(BettingSystem*, string);
  ~Participant();

  void setName(string);
  void setName();     // When called with no args will prompt for a name before setting m_name

  string getName() const;
  int getBank() const;
  int getTotalGain() const;
  int getSpinGain() const;

  void PayOut(int);
  void setBetArray();
  void delBetArray();
  void initBank();
  void resetSpin();
  int getSIZE() const;
  BetMessage* getBet(int);
  

  
};

#endif