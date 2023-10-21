#include <string>
#include "llc.cpp"
#include "pc.h"

class Player{
public:
  Player();
  Player(string name);

  void operator=(const Player &p1);

  LLC<PlayingCard> *hand;
  string playerName;
  int wins;

private:
};
