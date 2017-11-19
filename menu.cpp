/*
 *   kjs170430_Project4/menu.cpp
 *   Copyright 2017, Kristopher Sewell, All rights reserved.
 *
 *   Course:  CE1337  Section:  501   Project: 4
 */

#include "menu.hpp"

void mainmenu(Participant& customer ,BettingSystem& table) {
  while(true) {
    std::cout << "## MAIN MENU. ##\n" << customer.getName() << ", ";
    std::cout << "Please enter your selection. \n"
              << std::setw(5) << "  1.)" << " Place Bet.\n"
              << std::setw(5) << "  2.)" << " Change Player.\n"
              << std::setw(5) << "  3.)" << " Spin the Wheel.\n"
              << std::setw(5) << "  4.)" << " Exit Game.\n";
    string temp;
    std::cin >> temp;
    int swvar;
    if (checkIsDigit(temp)) {
      swvar = atoi(temp.c_str());
    }

    switch (swvar) {
      case 1:
        betmenu(customer);
        break;

      case 2:
        playermenu();
        break;

      case 3:
        table.getWinners();
        printStats(customer);
        customer.resetSpin();
        break;

      case 4:
        printStats(customer);
        return;

      default:
        mainmenu(customer,table);
    }
  }
}

void betmenu(Participant& customer) {
  int Type = -1; 
  int TypeValue;
  int Wager = -1;
  
  customer.setBetArray();
  bool isGood = true;
  for (int i = 0; i < customer.getSIZE(); i++) {
    if (isGood) {
      printStats(customer);
      fetchType(Type,TypeValue);
      fetchWager(Wager, customer);
      customer.getBet(i)->setBetType(Type); 
      customer.getBet(i)->setBetValue(TypeValue);
      customer.getBet(i)->setBetWager(Wager);
      customer.getBet(i)->checkMessage(customer);
      if (!customer.getBet(i)->good()) {
        //std::cout << Type << " "<< TypeValue << " " << Wager << std::endl;
        std::cout << customer.getBet(i)->good()<< " " << customer.getBet(i)->getType()<< " " 
                  << customer.getBet(i)->getValue()<< " "<<customer.getBet(i)->getWager()<< std::endl;
        isGood = false;
      }
    }
  }
}


void fetchType(int& ty, int& tyv) {
  std::cout << "Please enter a type.\n" 
            << setw(3) << "1" << ".) Single\t\tPAYOUT 36:1\n"
            << setw(3) << "2" << ".) Red\t\tPAYOUT 2:1\n"
            << setw(3) << "3" << ".) Black\t\tPAYOUT 2:1\n"
            << setw(3) << "4" << ".) Even\t\tPAYOUT 2:1\n"
            << setw(3) << "5" << ".) Odd\t\tPAYOUT 2:1\n"
            << setw(3) << "6" << ".) <1-12>\t\tPAYOUT 3:1\n"
            << setw(3) << "7" << ".) <13-24>\t\tPAYOUT 3:1\n"
            << setw(3) << "8" << ".) <25-36>\t\tPAYOUT 3:1\n"
            << setw(3) << "9" << ".) <1-18>\t\tPAYOUT 2:1\n"
            << setw(3) << "10" << ".) <19-36>\t\tPAYOUT 2:1\n"
            << setw(3) << "11" << ".) First Column\tPAYOUT 3:1\n"
            << setw(3) << "12" << ".) Second Column\tPAYOUT 3:1\n"
            << setw(3) << "13" << ".) Third Column\tPAYOUT 3:1\n";
  string temp;
  std::cin >> temp;
  int var;
  if (checkIsDigit(temp)) {
    var = atoi(temp.c_str());
    if (var == 1) {
      ty = BetMessage::Type::Single;
      tyv = get0thru36();
    }
    else if (var == 2 || var == 3) {
      ty = BetMessage::Type::Color;
      if (var == 2) {tyv = BetMessage::TypeValue::Red;}
      if (var == 3) {tyv = BetMessage::TypeValue::Black;}
    }
    else if (var == 4 || var == 5) {
      ty = BetMessage::Type::Modulo;
      if (var == 4) {tyv = BetMessage::TypeValue::Even;}
      if (var == 5) {tyv = BetMessage::TypeValue::Odd;}
    }
    else if (var >= 6 && var <= 8) {
      ty = BetMessage::Type::Group;
      if (var == 6) {tyv = BetMessage::TypeValue::Lower;}
      if (var == 7) {tyv = BetMessage::TypeValue::Middle;}
      if (var == 8) {tyv = BetMessage::TypeValue::Upper;}
    }
    else if (var == 9 || var == 10) {
      ty = BetMessage::Type::Half;
      if (var == 9) {tyv = BetMessage::TypeValue::Lower;}
      if (var == 10) {tyv = BetMessage::TypeValue::Upper;}
    }
    else if (var >= 11 && var <= 13) {
      ty = BetMessage::Type::Column;
      if (var == 11) {tyv = BetMessage::TypeValue::First;}
      if (var == 12) {tyv = BetMessage::TypeValue::Second;}
      if (var == 13) {tyv = BetMessage::TypeValue::Third;}
    }
    else {ty = 0;}
  }
  else {ty = 0;} 
}

void fetchWager(int& wg, Participant& customer) {
  printStats(customer);
  std::cout << "Please enter a Wager: ";
  string temp;
  std::cin >> temp;
  std::cout << std::endl;
  if (checkIsDigit(temp)) {
    wg = atoi(temp.c_str());
  }
}

void playermenu() {
  std::cout << "\n\nSorry this feature is not yet implemented.\n\n";
}


int get0thru36() {
  string temp;
  while (true) {
    std::cout << "\nPlease enter a number from 0-36: ";
    std::cin >> temp;
    std::cout << std::endl;
    if (checkIsDigit(temp)) {
      int rtn = atoi(temp.c_str());
      if (rtn >= 0 && rtn < 37) {
        return rtn;
      } 
    }
    std::cout << "\nEntry not valid. Please try again.\n";
  }
}

void printStats(Participant& customer) {
  std::cout << "Total Dollar Amount: $" << customer.getBank() << " ";
  std::cout << "Round Gain/Loss: $" << customer.getSpinGain() << " ";
  std::cout << "Total Gain/Loss: $" << customer.getTotalGain() << " ";
  std::cout << std::endl;
}