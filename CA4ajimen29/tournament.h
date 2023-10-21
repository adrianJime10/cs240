#include <vector>
//#include "player.h"
#include <fstream>
#include "game.h"
#include <iostream>

using namespace std;

 class tournament{
 public:
   tournament(ifstream& inputfile);

   Player playTourny(ofstream& outputfile);
   Player match(ofstream& outputfile, Player& p1, Player& p2);
   bool powerTwo(int n);

   vector<Player> players;
 private:

 };
