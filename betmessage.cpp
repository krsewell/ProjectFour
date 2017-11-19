#include "betmessage.hpp"

BetMessage::BetMessage() {
  m_good = false;
  m_betType = 0;
  m_betValue = 0;
  m_betWager = 0;
}

BetMessage::BetMessage(int betType, int betValue, int betWager) {
  m_good = false;
  setBetType(betType);
  setBetValue(betValue);
  setBetWager(betWager);
}

BetMessage::~BetMessage() {
  //std::cout << "B.msg deleting\n";
}


void BetMessage::setBetType(int betType) {
  if (betType >= 0 && betType <= 5) {
    m_betType = betType;
  } else {
    std::cout << "Improper Betting Type\n";
  }
}
void BetMessage::setBetValue(int betValue) {
  switch (m_betType) {
    case Single:
      if (betValue >= 0 && betValue < 37) {
        m_betValue = betValue;
      } 
      break;
    case Color:
      if (betValue == Red || betValue == Black) {
        m_betValue = betValue;
      } 
      break;
    case Modulo:
      if (betValue == Even || betValue == Odd) {
        m_betValue = betValue;
      } 
      break; 
    case Group: 
      if (betValue == Lower || betValue == Middle || betValue == Upper) {
        m_betValue = betValue;
      } 
      break;
    case Half: 
      if (betValue == Lower || betValue == Upper) {
        m_betValue = betValue;
      } 
      break;
    case Column:
      if (betValue == First || betValue == Second || betValue == Third) {
        m_betValue = betValue;
      } 
      break;

    default:
      m_good = false;
      break;
  }
}
void BetMessage::setBetWager(int betWager) {
  if (betWager > 0) {
    m_betWager = betWager;
  } else {
    std::cout << "Improper Bet Wager\n";
  }
}

void BetMessage::checkMessage(Participant& p) {
  /*  
  Check to see if the message has a valid wager and that the message isn't already well formed
  If the message is in good format then check if the player has enough funds to cover the bet.
  */
  if (m_betWager > 0 && !m_good) {
    if (p.getBank() > m_betWager) {
      m_good = true;
      p.PayOut(m_betWager*-1);
    } else {
      //invalidate bet
      m_betWager = 0;
    }
  }
}

int BetMessage::getType() const {
  return m_betType;
}
int BetMessage::getValue() const{
  return m_betValue;
}
int BetMessage::getWager() const {
  return m_betWager;
}

bool BetMessage::good() const{
  return m_good;
}
