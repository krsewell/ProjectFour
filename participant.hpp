#ifndef PARTICIPANT_H_INCL_GUARD
#define PARTICIPANT_H_INCL_GUARD

#include <iostream>
#include <string>

using std::string;

#endif

class Participant {
private:
  static unsigned int participantCount;
  int m_gamblerId;
  string m_name;
  int m_bank;
  int m_gain;
  
  friend class BettingSystem;
  void setBank(int);      //declared private for use by betting system
  void PayOut(int);
  void setGamblerId();

public:
  Participant();
  Participant(string);
  void setName(string);
  int getBank() const;
  int getGain() const;

  string getName() const;
  int getID() const;
};