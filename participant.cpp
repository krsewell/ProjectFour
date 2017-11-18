#include "participant.hpp"


Participant::Participant(BettingSystem * bs) {
  m_CurrentBetTable = bs;
  setName();

}

Participant::Participant(BettingSystem * bs, string name) {
  m_CurrentBetTable = bs;
  setName(name);
}


void Participant::initBank() {
  string strin;
  std::cout << "For Player: " << this->getName() 
            << " enter a starting balance up to $10,000.\n";
  std::cin >> strin;

  if (checkIsDigit(strin)) {      //is it safe to convert into a digit.
    int testVal = atoi(strin.c_str());
    if (testVal > 0 && testVal < 10001) {
      this->m_bank = testVal;
    } else {
      std::cout << "That amount is not valid.";
      Participant::initBank();    //try again.
    }
  }
}

void Participant::PayOut(int diff) {
  m_gain += diff;
  m_bank += diff;
}


void Participant::setName(string name) {
  m_name = name;
}

void Participant::setName() {
  string name;
  std::cout << "Please enter your name.\n";
  std::getline(std::cin,name);
  m_name = name;
}

string Participant::getName() const {
  return m_name;
}


int Participant::getBank() const {
  return m_bank;
}

int Participant::getGain() const {
  return m_gain;
}
