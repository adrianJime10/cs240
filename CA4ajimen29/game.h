#include "player.h"
#include <fstream>
//#include "llc.cpp"
using namespace std;

class Game{
public:
  Game();
  Game(Player& play1, Player& play2);

  void resetHands();
  void shuffleDeck();
  void dealCards();
  void battle(ofstream& outputfile, int& wars, int& battles);
  void war(ofstream& outputfile, int& wars);
  Player play(ofstream& outputfile);

  ofstream outputfile;
  Player p1;
  Player p2;
  LLC<PlayingCard> *pile;
private:

};
