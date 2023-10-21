#include "tournament.h"
#include <string>
//#include "game.h"

using namespace std;

tournament::tournament(ifstream& inputfile){
  while(inputfile.good() && !inputfile.eof()){
    if(inputfile.eof()) break;
    string playername;
    inputfile >> playername;
    //getline(inputfile,playername);
    players.push_back(Player(playername));
  }
  players.erase(players.begin()+players.size());
}

Player tournament::playTourny(ofstream& outputfile){
    players.push_back(match(outputfile, players.at(0),players.at(1)));
    players.erase(players.begin());
    players.erase(players.begin());
  
  if(players.size()==1){
    return players.at(0);
  }else{
    return playTourny(outputfile);
  }
}

Player tournament::match(ofstream& outputfile, Player& p1, Player &p2){
  cout << "played 1";
  Game g1(p1,p2);
  Player winner = g1.play(outputfile);
  //cout << *winner.hand;
  return winner;
}

bool tournament::powerTwo(int n){
  if(n==0) return false;
  if((n & (n-1))==0)return true;
  return false;
}
