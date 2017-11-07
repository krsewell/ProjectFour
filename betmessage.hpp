#ifndef BETMESSAGE_H_INCL_GUARD
#define BETMESSAGE_H_INCL_GUARD

#include <iostream>


#endif


class BetMessage {
private:
  int m_gamblerId;
  int m_betType;
  int m_betValue;
  int m_betWager;
  bool m_good = true;

  void setGamblerId(int);
  void setBetType(int);
  void setBetValue(int);
  void setBetWager(int);
  ~BetMessage();

public:
  BetMessage(int,int,int,int);
  enum Type {Single,Color,Modulo,Group,Half,Column};
  enum TypeValue {Red,Black,Even,Odd,Lower,Middle,Upper,First,Second,Third};

  int getID();
  int getType();
  int getValue();
  int getWager();

};