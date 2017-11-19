/*
 *   kjs170430_Project4/globalTools.hpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 4
 */

#ifndef GLOBALTOOLS_H_INCL_GUARD
#define GLOBALTOOLS_H_INCL_GUARD

#include <string>

inline bool checkIsDigit(std::string str) {
  bool isDigitFlag = true;
  for (char c : str)
  {   //check for a digit that can be converted
    if (!isdigit(c)) { isDigitFlag = false; }
  }
  return isDigitFlag;
}

#endif