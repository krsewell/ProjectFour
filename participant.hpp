#ifndef PARTICIPANT_H_INCL_GUARD
#define PARTICIPANT_H_INCL_GUARD

#include <iostream>
#include <string>
#include "bettingSystem.hpp"

using std::string;

#endif

class Participant {
private:
  string m_name;
  int m_bank;
  int m_gain;
  BettingSystem * m_CurrentBetTable;
  
  friend class BettingSystem;
  //declared private for use by betting system           
  void PayOut(int);
  void initBank();

public:
  Participant(BettingSystem*);
  Participant(BettingSystem*, string);
  void setName(string);
  void setName();

  string getName() const;
  int getBank() const;
  int getGain() const;

  
};