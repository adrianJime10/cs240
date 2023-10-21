#include "player.h"

Player::Player(){
  playerName="";
  hand = new LLC<PlayingCard>;
  wins = 0;
}

Player::Player(string name){
  hand = new LLC<PlayingCard>;
  playerName = name;
  wins = 0;
}

void Player::operator=(const Player &p1){
	playerName = p1.playerName;
	hand = p1.hand;
}
