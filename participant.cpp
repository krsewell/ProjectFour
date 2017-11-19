#include "participant.hpp"


Participant::Participant() {
  m_spinGain = 0;
  setName();

}

Participant::Participant(BettingSystem * bs, string name) {
  m_CurrentBetTable = bs;
  setName(name);
}

Participant::~Participant() {
  delBetArray();
}


void Participant::initBank() {
  string strin;
  std::cout << "For Player: " << getName() 
            << " enter a starting balance up to $10,000.\n";
  std::cin >> strin;

  if (checkIsDigit(strin)) {      //is it safe to convert into a digit.
    int testVal = atoi(strin.c_str());
    if (testVal > 0 && testVal < 10001) {
      m_bank = testVal;
    } else {
      std::cout << "That amount is not valid.";
      Participant::initBank();    //try again.
    }
  }
}

void Participant::PayOut(int diff) {
  m_spinGain += diff;
  m_totalGain += diff;
  m_bank += diff;
}

void Participant::resetSpin() {
  m_spinGain = 0;
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

void Participant::setBetArray() {
  SIZE = getBetNum();
  m_bets = new BetMessage*[SIZE];
  for (int k = 0; k < SIZE; k++) {
    m_bets[k] = new BetMessage();
  }
}

void Participant::delBetArray() {
  for (int i = 0; i < SIZE && m_bets != nullptr; i++) {
    delete m_bets[i];
  }
  delete [] m_bets;
  m_bets = nullptr;
}

string Participant::getName() const {
  return m_name;
}

int Participant::getBetNum() {
  string temp;
  std::cout << "How many bets would you like to make?\nYou may make up to 8 bets:  ";
  std::cin >> temp;
  std::cout << std::endl;

  if (checkIsDigit(temp)) {
    int rtn = atoi(temp.c_str());
    if (rtn < 9 && rtn > 0) {
      return rtn;
    } 
  }
    
  getBetNum();
  return 0;     //should never run.
}

int Participant::getBank() const {
  return m_bank;
}

int Participant::getTotalGain() const {
  return m_totalGain;
}

int Participant::getSpinGain() const {
  return m_spinGain;
}

int Participant::getSIZE() const {
  return SIZE;
}

BetMessage* Participant::getBet(int index) {
  if (m_bets == nullptr) {return nullptr;}
  return m_bets[index];
}