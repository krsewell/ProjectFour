/*
 *   kjs170430_Project4/roulette.hpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 * 
 *   Course:  CE1337  Section:  501   Project: 4
 */
#ifndef ROULETTEWHEEL_H_INCL_GUARD
#define ROULETTEWHEEL_H_INCL_GUARD

#include <ctime>
#include <random>

using std::time;
using std::rand;
using std::srand;


 class RouletteWheel {
 private:
  static const int red[18];
  static const int black[18];
  int m_roll;
  bool m_isRed;
  bool m_isBlack;
  bool m_isOdd;
  bool m_isEven;
  
  bool getEven();
  bool getOdd();
  bool getRed();
  bool getBlack();

  bool jumpSearch(const int, const int*);


    
 public:
  RouletteWheel();
  ~RouletteWheel();  
  void roll();
  bool isEven() const;
  bool isOdd() const;
  bool isRed() const;
  bool isBlack() const;
  int getRoll() const;


 };

 #endif
