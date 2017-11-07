/*
 *   kjs170430_Project4/roulette.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 * 
 *   Course:  CE1337  Section:  501   Project: 4
 */
#include "roulette.hpp"

const int RouletteWheel::red[18] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
const int RouletteWheel::black[18] = {2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};

RouletteWheel::RouletteWheel() {
  m_isBlack = false;
  m_isRed = false;
  m_isEven = false;
  m_isOdd = false;
}

RouletteWheel::~RouletteWheel() {}


void RouletteWheel::roll() { 
  srand(time(0));
  RouletteWheel::m_roll = rand() % 37;
  //now set booleons for states
  m_isEven = RouletteWheel::getEven();
  m_isOdd = RouletteWheel::getOdd();
  m_isRed = RouletteWheel::getRed();
  m_isBlack = RouletteWheel::getBlack();
}

bool RouletteWheel::getEven() {
  if (m_roll == 0) {return false;}
  bool value = (m_roll % 2 == 0);
  return value;
}
bool RouletteWheel::getOdd() {
  bool value = (m_roll % 2 == 1);
  return value;
}
bool RouletteWheel::getRed() {
  bool value = jumpSearch(m_roll,red);
  return value;
}
bool RouletteWheel::getBlack() {
  bool value = jumpSearch(m_roll,black);
  return value;
}

bool RouletteWheel::jumpSearch(const int value, const int* arrayPtr) {
  for (int i = 0, j = 0; i < 21; i +=4) {
    if (i > 17) {i = 17;}   //max value of array
    while (*(arrayPtr + i) >= value) {
      if (*(arrayPtr + i) == value) {
        return true;
      } else if (i < 0 || j > 4) {
        return false;
      } else {
        i--;
        j++;
      }
    }
  }
  return false;   // Should never reach here.
}


bool RouletteWheel::isEven() const {
  return m_isEven;
}
bool RouletteWheel::isOdd() const {
  return m_isOdd;
}
bool RouletteWheel::isRed() const {
  return m_isRed;
}
bool RouletteWheel::isBlack() const {
  return m_isBlack;
}
int RouletteWheel::getRoll() const {
  return m_roll;
}