#include "bettingSystem.hpp"

void BettingSystem::writeParticipant() 
{
  static int recursivecount;  //zero by default
  string strin;

  cout << "Please enter the number of Players [1-10]\n";
  std::cin >> strin;

  if (checkIsDigit(strin)) 
  {   //convert to int if it is just a digit
    int players = stoi(strin);
    for (int i =0; i < players; i++) 
    { //make a participant profile for each player.
      (m_participantRef[i]) = new Participant();
    }
  }  
  else 
  {   //otherwise try again up to 3 times
    recursivecount++;
    if (recursivecount > 3) {exit(0);}
    BettingSystem::writeParticipant();
  }
}

void BettingSystem::writeBank(Participant p) 
{
  string strin;
  std::cout << "For Player: " << p.m_gamblerId 
            << " enter a starting balance.\n";
  std::cin >> strin;

  if (checkIsDigit(strin)) 
  {
    p. = stoi(strin);
    if (p.m_bank < 0 || p.m_bank > 10001)
    {


    }
  }
}

bool checkIsDigit(string str) 
{
  bool isDigitFlag = true;
  for (char c : str)
  {   //check for a digit that can be converted
    if (!isdigit(c)) { isDigitFlag = false; }
  }
  return isDigitFlag;
}