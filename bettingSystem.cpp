#include "bettingSystem.hpp"

BettingSystem::BettingSystem() {
  game = new RouletteWheel(); 
}
BettingSystem::~BettingSystem() {
  delete game;
}

void BettingSystem::getWinners() {
  for (auto p : m_player) {
    for (int i = 0; i < p->getSIZE(); i++) {
      BetMessage* msg = p->getBet(i);
      int type;
      msg->good() ? type = msg->getType() : type = -1;     //if msg is valid get type

      if (type == BetMessage::Type::Single) {
        if (msg->getValue() == game->getRoll()) {
          p->PayOut(msg->getWager() * 36);
        }
      } else if (type == BetMessage::Type::Color) {
        if (game->isBlack() && msg->getValue() == BetMessage::TypeValue::Black) {
          p->PayOut(msg->getWager() * 2);
        }
        else if (game->isRed() && msg->getValue() == BetMessage::TypeValue::Red) {
          p->PayOut(msg->getWager() * 2);
        }

      } else if (type == BetMessage::Type::Modulo) {
        if (game->isEven() && msg->getValue() == BetMessage::TypeValue::Even) {
          p->PayOut(msg->getWager() * 2);
        }
        else if (game->isOdd() && msg->getValue() == BetMessage::TypeValue::Odd) {
          p->PayOut(msg->getWager() * 2);
        }
      } else if (type == BetMessage::Type::Group) {
        if (msg->getValue() == BetMessage::TypeValue::Lower && game->getRoll() < 13 && game->getRoll() != 0) {
          p->PayOut(msg->getWager() * 3);
        }
        else if (msg->getValue() == BetMessage::TypeValue::Upper && game->getRoll() > 24) {
          p->PayOut(msg->getWager() * 3);
        }
        else if (msg->getValue() == BetMessage::TypeValue::Middle && game->getRoll() > 12 && game->getRoll() < 25) {
          p->PayOut(msg->getWager() * 3);
        }
      } else if (type == BetMessage::Type::Half) {
        if (msg->getValue == BetMessage::TypeValue::Lower && game->getRoll() < 19 && game->getRoll() != 0) {
          p->PayOut(msg->getWager() * 2);
        }
        else if (msg->getValue == BetMessage::TypeValue::Upper && game->getRoll() > 18) {
          p->PayOut(msg->getWager() * 2);
        }
      } else if (type == BetMessage::Type::Column) {
        if (game->getRoll() != 0) {
          if (msg->getValue == BetMessage::TypeValue::Third && game->getRoll() % 3 == 0) {
            p->PayOut(msg->getWager() * 3);
          }
          else if (msg->getValue == BetMessage::TypeValue::Second && game->getRoll() % 3 == 2) {
            p->PayOut(msg->getWager() * 3);
          }
          else if (msg->getValue == BetMessage::TypeValue::First && game->getRoll() % 3 == 1) {
            p->PayOut(msg->getWager() * 3);
          }
        }
      }
    }
    p->delBetArray();
    p->setBetArray();
  }
}

string BettingSystem::getParticipantName(Participant* p) {
  bool done = false;
  unsigned i = 0;
  string name = "NONE";

  while (!done && i < m_player.size()) {
    if (m_player.at(i) == p) {
      name = m_player.at(i)->getName();
      done = true;
    }
    i++;
  }
  return name;
}

void BettingSystem::joinGame(Participant * p) {
  m_player.push_back(p);
  p->initBank();
}

void BettingSystem::leaveGame(Participant * p) {
  bool done = false;
  unsigned i = 0;

  while (!done && i < m_player.size()) {
    if (m_player.at(i) == p) {
      m_player.at(i) = nullptr;
      done = true;
    }
    i++;
  }
}



