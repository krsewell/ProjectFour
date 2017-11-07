#include "betmessage.hpp"

BetMessage::BetMessage(int gamblerId, int betType, int betValue, int betWager) {
  setGamblerId(gamblerId);
  setBetType(betType);
  setBetValue(betValue);
  setBetWager(betWager);
}

BetMessage::~BetMessage() {}

void BetMessage::setGamblerId(int gamblerId) {
  if (gamblerId != 0) {
    m_gamblerId = gamblerId;
  }
}
void BetMessage::setBetType(int betType) {
  if (betType >= 0 && betType < 5) {
    m_betType = betType;
  } else {
    std::cout << "Improper Betting Type\n";
    m_good = false;
  }
}
void BetMessage::setBetValue(int betValue) {
  switch (m_betType) {
    case Single:
      if (betValue >= 0 && betValue < 37) {
        m_betValue = betValue;
      } else {m_good = false;}
      break;
    case Color:
      if (betValue == Red || betValue == Black) {
        m_betValue = betValue;
      } else {m_good = false;}
      break;
    case Modulo:
      if (betValue == Even || betValue == Odd) {
        m_betValue = betValue;
      } else {m_good = false;}
      break; 
    case Group: 
      if (betValue == Lower || betValue == Middle || betValue == Upper) {
        m_betValue = betValue;
      } else {m_good = false;}
      break;
    case Half: 
      if (betValue == Lower || betValue == Upper) {
        m_betValue = betValue;
      } else {m_good = false;}
      break;
    case Column:
      if (betValue == First || betValue == Second || betValue == Third) {
        m_betValue = betValue;
      } else {m_good = false;}
      break;

    default:
      m_good = false;
  }
}
void BetMessage::setBetWager(int betWager) {
  if (betWager > 0 && betWager < 10000) {
    m_betWager = betWager;
  } else {
    std::cout << "Improper Bet Wager\n";
    m_good = false;
  }
}

int BetMessage::getID() {
  return m_gamblerId;
}
int BetMessage::getType() {
  return m_betType;
}
int BetMessage::getValue() {
  return m_betValue;
}
int BetMessage::getWager() {
  return m_betWager;
}
