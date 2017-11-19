#ifndef BETMESSAGE_H_INCL_GUARD
#define BETMESSAGE_H_INCL_GUARD

#include <iostream>
#include "participant.hpp"

class Participant;

class BetMessage {
private:
  int m_betType;
  int m_betValue;
  int m_betWager;
  bool m_good;

  void setBetType(int);
  void setBetValue(int);
  void setBetWager(int);
  

public:
  BetMessage();
  ~BetMessage();
  BetMessage(int,int,int);
  enum Type {Single,Color,Modulo,Group,Half,Column};
  enum TypeValue {Red,Black,Even,Odd,Lower,Middle,Upper,First,Second,Third};
  
  int getType() const;
  int getValue() const;
  int getWager() const;
  void checkMessage(Participant*);
  bool good() const;

};

#endif