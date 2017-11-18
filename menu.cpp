#include "menu.hpp"

/*    Control Varible Key   xxxz
*         xxx - denotes menu command
*         z - denotes current player active 
*       control % 10 gives player number
*       subtract player number and divide by 10 to give menu code
*
*/

BettingSystem house;
RouletteWheel game;


int menuController() {
  int c;

  while (c !=1990) {
    if (c == 1030) {
      game.roll();
      house.getWinners();
      c = 0;
    }
    else if (c == )
    else if (c == 0) {
      mainmenu(c);
    }


  }
  return 0;
}

void mainmenu(int& control) {
  int playerID = (control % 10) + 1;
  std::cout << "## MAIN MENU. ##\n" << house.getParticipantName(playerID) << ", ";
  std::cout << "Please enter your selection. \n"
            << std::setw(5) << "  1.)" << " Place Bet.\n"
            << std::setw(5) << "  2.)" << " Change Player.\n"
            << std::setw(5) << "  3.)" << " Spin the Wheel.\n"
            << std::setw(5) << "  4.)" << " Exit Game.\n";
  int temp;
  std::cin >> temp;

  switch (temp) {
    case 1:
      control %= 10;
      control += 1010;
      betmenu(control);
      break;
    case 2:
      control %= 10;
      control += 1020;
      playermenu(control);
      break;
    case 3:
      control = 1030;
      break;
    case 4:
      control = 1990;
      break;

    default:
      control = -1;
      mainmenu(control);
  }
}

void betmenu(int& control) {
  int Type = -1, TypeValue, Wager = -1;
  int playerID = (control % 10) + 1;
  
  std::cout << "## BET MENU. ##\n" << house.getParticipantName(playerID) << ", ";
  std::cout << "Please enter your selection. \n"
            << std::setw(5) << "  1.)" << " Enter Bet Type.\n"
            << std::setw(5) << "  2.)" << " Enter Bet Wager.\n"
            << std::setw(5) << "  3.)" << " Previous Menu.\n";
  int temp;
  std::cin >> temp;

  switch (temp) {
    case 1:
      Type = fetchType();
      TypeValue = Type % 100;
      Type -= TypeValue;
      break;

    case 2:
      Wager = fetchWager();
      break;
    
    case 3:
      control %= 10;
      control += 2030;
      break;

    default:
      control -2;
      betmenu(control);
  }  
}


int fetchType() {
  int ty;
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
  if (checkIsDigit(temp)) {
    ty = atoi(temp.c_str());
    if (ty == 1) {}
    else if (ty == 2 || ty == 3) {}
    else if (ty == 4 || ty == 5) {}
    else if (ty >= 6 && ty <= 8) {}
    else if (ty == 9 || ty == 10) {}
    else if (ty >= 11 && ty <= 13) {}
    else {ty = 0;}
  }
  else {ty = 0;} 
  return ty;
}

int fetchWager() {
  int wg;

  return wg;
}
