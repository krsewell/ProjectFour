#include "bettingSystem.hpp"

BettingSystem::BettingSystem() {
  game = new RouletteWheel(); 
}
BettingSystem::~BettingSystem() {
  delete game;
}

void BettingSystem::getWinners() {
  for (int i = 0; i < 88; i++) {
    BetMessage * msg = *m_betMessageRef[i];
    int type;
    msg.check() ? type = msg->getType() : type = -1;     //if msg is valid get type
    Participant * p = m_participantRef[msg.getID()];

    if (type == BetMessage::Type::Single) {
      if (msg.getValue() == game->getRoll()) {
        p.PayOut(msg.getWager() * 36);
      }
    } else if (type == BetMessage::Type::Color) {
      if (game->isBlack() && msg.getValue() == BetMessage::TypeValue::Black) {
        p.PayOut(msg.getWager() * 2);
      }
      else if (game->isRed() && msg.getValue() == BetMessage::TypeValue::Red) {
        p.PayOut(msg.getWager() * 2);
      }

    } else if (type == BetMessage::Type::Modulo) {
      if (game->isEven() && msg.getValue() == BetMessage::TypeValue::Even) {
        p.PayOut(msg.getWager() * 2);
      }
      else if (game->isOdd() && msg.getValue() == BetMessage::TypeValue::Odd) {
        p.PayOut(msg.getWager() * 2);
      }
    } else if (type == BetMessage::Type::Group) {
      if (msg.getValue() == BetMessage::TypeValue::Lower && game->getRoll() < 13 && game->getRoll() != 0) {
        p.PayOut(msg.getWager() * 3);
      }
      else if (msg.getValue() == BetMessage::TypeValue::Upper && game->getRoll() > 24) {
        p.PayOut(msg.getWager() * 3);
      }
      else if (msg.getValue() == BetMessage::TypeValue::Middle && game->getRoll() > 12 && game->getRoll() < 25) {
        p.PayOut(msg.getWager() * 3);
      }
    } else if (type == BetMessage::Type::Half) {
      if (msg.getValue == BetMessage::TypeValue::Lower && game->getRoll() < 19 && game->getRoll() != 0) {
        p.PayOut(msg.getWager() * 2);
      }
      else if (msg.getValue == BetMessage::TypeValue::Upper && game->getRoll() > 18) {
        p.PayOut(msg.getWager() * 2);
      }
    } else if (type == BetMessage::Type::Column) {
      if (game->getRoll() != 0) {
        if (msg.getValue == BetMessage::TypeValue::Third && game->getRoll() % 3 == 0) {
          p.PayOut(msg.getWager() * 3);
        }
        else if (msg.getValue == BetMessage::TypeValue::Second && game->getRoll() % 3 == 2) {
          p.PayOut(msg.getWager() * 3);
        }
        else if (msg.getValue == BetMessage::TypeValue::First && game->getRoll() % 3 == 1) {
          p.PayOut(msg.getWager() * 3);
        }
      }
    }
  }
  sendBetMessage();
}

string BettingSystem::getParticipantName(int id) {
  string name;
  name = m_participantRef[id].getName();
  if (name.empty()) {name = "NONE";}
  return name;
}

void BettingSystem::sendBetMessage(int id ,int ty ,int tyv, int wg) {
  static int counter = 0;
  m_betMessageRef[counter] = BetMessage(id,ty,tyv,wg);
  if (m_betMessageRef[counter].check()) {counter++;}
  else {m_betMessageRef[counter].~BetMessage();}
}

void BettingSystem::sendBetMessage(){
  static int counter = 0;
  counter = 0;
  delete [] m_betMessageRef;    //delete and recreate
  m_betMessageRef = new BetMessage[88];
}

void joinGame(Participant * p) {
  for (Participant s : m_participantRef) {
    
  }
}

void leaveGame(Participant * p) {

}



