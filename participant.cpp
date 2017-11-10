#include "participant.hpp"


Participant::Participant() {
  setGamblerId();
}

Participant::Participant(string name) {
  setGamblerId();
  setName(name);
}


int Participant::getBank() const {
  return m_bank;
}
int Participant::getGain() const {
  return m_gain;
}
string Participant::getName() const {
  return m_name;
}
int Participant::getID() const {
  return m_gamblerId;
}

void Participant::PayOut(int diff) {
  m_gain += diff;
  m_bank += diff;
}
void Participant::setBank(int diff) {
  if (diff > 0 && diff < 10001)
    m_bank += diff;
} 
void Participant::setGamblerId() {
  participantCount++;
  m_gamblerId = participantCount;
}
void Participant::setName(string name) {
  m_name = name;
}