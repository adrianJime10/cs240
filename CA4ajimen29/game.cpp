#include "game.h"
#include <iostream>
#include <fstream>

Game::Game(Player& play1, Player& play2){
  p1=play1;
  p2=play2;

  pile = new LLC<PlayingCard>;

  pile->insert(PlayingCard(2,PlayingCard::D));
  pile->insert(PlayingCard(2,PlayingCard::C));
  pile->insert(PlayingCard(2,PlayingCard::H));
  pile->insert(PlayingCard(2,PlayingCard::S));

  pile->insert(PlayingCard(3,PlayingCard::D));
  pile->insert(PlayingCard(3,PlayingCard::C));
  pile->insert(PlayingCard(3,PlayingCard::H));
  pile->insert(PlayingCard(3,PlayingCard::S));

  pile->insert(PlayingCard(4,PlayingCard::D));
  pile->insert(PlayingCard(4,PlayingCard::C));
  pile->insert(PlayingCard(4,PlayingCard::H));
  pile->insert(PlayingCard(4,PlayingCard::S));

  pile->insert(PlayingCard(5,PlayingCard::D));
  pile->insert(PlayingCard(5,PlayingCard::C));
  pile->insert(PlayingCard(5,PlayingCard::H));
  pile->insert(PlayingCard(5,PlayingCard::S));

  pile->insert(PlayingCard(6,PlayingCard::D));
  pile->insert(PlayingCard(6,PlayingCard::C));
  pile->insert(PlayingCard(6,PlayingCard::H));
  pile->insert(PlayingCard(6,PlayingCard::S));

  pile->insert(PlayingCard(7,PlayingCard::D));
  pile->insert(PlayingCard(7,PlayingCard::C));
  pile->insert(PlayingCard(7,PlayingCard::H));
  pile->insert(PlayingCard(7,PlayingCard::S));

  pile->insert(PlayingCard(8,PlayingCard::D));
  pile->insert(PlayingCard(8,PlayingCard::C));
  pile->insert(PlayingCard(8,PlayingCard::H));
  pile->insert(PlayingCard(8,PlayingCard::S));

  pile->insert(PlayingCard(9,PlayingCard::D));
  pile->insert(PlayingCard(9,PlayingCard::C));
  pile->insert(PlayingCard(9,PlayingCard::H));
  pile->insert(PlayingCard(9,PlayingCard::S));

  pile->insert(PlayingCard(10,PlayingCard::D));
  pile->insert(PlayingCard(10,PlayingCard::C));
  pile->insert(PlayingCard(10,PlayingCard::H));
  pile->insert(PlayingCard(10,PlayingCard::S));

  pile->insert(PlayingCard(11,PlayingCard::D));
  pile->insert(PlayingCard(11,PlayingCard::C));
  pile->insert(PlayingCard(11,PlayingCard::H));
  pile->insert(PlayingCard(11,PlayingCard::S));

  pile->insert(PlayingCard(12,PlayingCard::D));
  pile->insert(PlayingCard(12,PlayingCard::C));
  pile->insert(PlayingCard(12,PlayingCard::H));
  pile->insert(PlayingCard(12,PlayingCard::S));

  pile->insert(PlayingCard(13,PlayingCard::D));
  pile->insert(PlayingCard(13,PlayingCard::C));
  pile->insert(PlayingCard(13,PlayingCard::H));
  pile->insert(PlayingCard(13,PlayingCard::S));

  pile->insert(PlayingCard(14,PlayingCard::D));
  pile->insert(PlayingCard(14,PlayingCard::C));
  pile->insert(PlayingCard(14,PlayingCard::H));
  pile->insert(PlayingCard(14,PlayingCard::S));
}

void Game::shuffleDeck(){
  pile->shuffle();
}

void Game::dealCards(){
  for(int i=0;i<26;i++){
    p1.hand->insert(pile->tailNode->element);
    pile->remove(pile->tailNode->element);
    //cout << '\n' << *p1.hand;
    p2.hand->insert(pile->tailNode->element);
    pile->remove(pile->tailNode->element);
    //cout << '\n' << *p2.hand;
  }

}

void Game::battle(ofstream& outputfile, int& wars, int& battles){
  //ofstream outputfile;
  //outputfile.open("WarOutput.txt");
  if(p1.hand->len()==0){
      cout << "\n" << p1.playerName << " LOST";
      outputfile << "\n" << p1.playerName << " LOST";
      //outputfile.close();
      return;
  }
  if(p2.hand->len()==0){
      cout << "\n" << p2.playerName << " LOST";
      outputfile << "\n" << p2.playerName <<" LOST";
      return;
  }
  
  if((p1.hand->headNode->element)>(p2.hand->headNode->element)){

    PlayingCard WinningCard = p1.hand->headNode->element;
    pile->insert(p1.hand->headNode->element);
    p1.hand->remove(p1.hand->headNode->element);

    PlayingCard LosingCard = p2.hand->headNode->element;
    pile->insert(p2.hand->headNode->element);
    p2.hand->remove(p2.hand->headNode->element);

    p1.hand->insert(pile->headNode->element);
    pile->remove(pile->headNode->element);
    p1.hand->insert(pile->headNode->element);
    pile->remove(pile->headNode->element);
    cout << "\nBattle " << battles << ": " << p1.playerName << " (" << WinningCard << ") defeated " << p2.playerName << " (" << LosingCard <<"): " << p1.playerName << " " << p1.hand->len() << ", " << p2.playerName << " " << p2.hand->len() << "\n";
    outputfile << "\nBattle " << battles << ": " << p1.playerName << " (" << WinningCard << ") defeated " << p2.playerName << " (" << LosingCard <<"): " << p1.playerName << " " << p1.hand->len() << ", " << p2.playerName << " " << p2.hand->len() << "\n";
    if(p2.hand->len()==0){
      cout << "\n" << p2.playerName << " LOST";
      outputfile << "\n" << p2.playerName <<" LOST";
      return;
    }

  }else if((p1.hand->headNode->element)<(p2.hand->headNode->element)){

    PlayingCard LosingCard = p1.hand->headNode->element;
    pile->insert(p1.hand->headNode->element);
    p1.hand->remove(p1.hand->headNode->element);

    PlayingCard WinningCard = p2.hand->headNode->element;
    pile->insert(p2.hand->headNode->element);
    p2.hand->remove(p2.hand->headNode->element);

    p2.hand->insert(pile->headNode->element);
    pile->remove(pile->headNode->element);
    p2.hand->insert(pile->headNode->element);
    pile->remove(pile->headNode->element);
    cout << "\nBattle "<< battles << ": " << p2.playerName << " (" << WinningCard << ") defeated " << p1.playerName << " (" << LosingCard <<"): " << p1.playerName << " " << p1.hand->len() << "," << p2.playerName << " " << p2.hand->len() << "\n";
    outputfile << "\nBattle " << battles << ": " << p2.playerName << " (" << WinningCard << ") defeated " << p1.playerName << " (" << LosingCard <<"): " << p1.playerName << " " << p1.hand->len() << "," << p2.playerName << " " << p2.hand->len() << "\n";

    if(p1.hand->len()==0){
      cout << "\n" << p1.playerName << " LOST";
      outputfile << "\n" << p1.playerName << " LOST";
      //outputfile.close();
      return;
    }

  }else if((p1.hand->headNode->element.value)==(p2.hand->headNode->element.value)){
    cout << "warring";
    cout << '\n' << *p1.hand << '\n' << *p2.hand;
    //outputfile.close();
    cout << "\nBattle " << battles << ": " << p1.playerName << " (" << p1.hand->headNode->element << ") tied " << p2.playerName << " (" << p2.hand->headNode->element <<")";
    outputfile << "\nBattle " << battles << ": " << p1.playerName << " (" << p1.hand->headNode->element << ") tied " << p2.playerName << " (" << p2.hand->headNode->element <<")";
    war(outputfile, wars);
  }else if(p1.hand->len()==0){
    p2.wins++;
    cout << "\n" << p2.playerName << " (" << p2.wins << ") DEFEATED " << p1.playerName << " in " << battles << " Battles and " << wars << " Wars";
    outputfile << "\n" << p2.playerName << " (" << p2.wins << ") DEFEATED " << p1.playerName << " in " << battles << " Battles and " << wars << " Wars";
  }else if(p2.hand->len()==0){
    p1.wins++;
    cout << "\n" << p1.playerName << " (" << p1.wins << ") DEFEATED " << p2.playerName << " in " << battles << " Battles and " << wars << " Wars";
    outputfile << "\n" << p1.playerName << " (" << p1.wins << ") DEFEATED " << p2.playerName << " in " << battles << " Battles and " << wars << " Wars";
  }
  //outputfile.close();
}

void Game::war(ofstream& outputfile, int& wars){
  //ofstream outputfile;
  //outputfile.open("WarOutput.txt");
  wars++;
  if((p1.hand->len()==1) && (p2.hand->len()==1)){
      cout << "Yea, player1 just wins lol";
      //outputfile << "Yea, player1 just wins lol";
      return;
  }
  //cout << "Player 1: ------ " << *p1.hand << "\n";
  if(p1.hand->len()>4){
    for(int i=0;i<4;i++){
      pile->insert(p1.hand->headNode->element);
      p1.hand->remove(p1.hand->headNode->element);
    }
  }else{
    for(int i=0;i<p1.hand->len()-1;i++){//WHY IS 2 WORKING AND ONE ISNT
      pile->insert(p1.hand->headNode->element);
      p1.hand->remove(p1.hand->headNode->element);
    }
  }
  //cout << "Player2: =====" << *p2.hand << "\n";
  if(p2.hand->len()>4){
     for(int i=0;i<4;i++){
      pile->insert(p2.hand->headNode->element);
      p2.hand->remove(p2.hand->headNode->element);
    }
  }else{
    for(int i=0;i<p2.hand->len()-1;i++){//WHY IS 2 WORKING AND ONE ISNT
      //cout << "i: " << i << "p"
      pile->insert(p2.hand->headNode->element);
      p2.hand->remove(p2.hand->headNode->element);
    }

  }if((p1.hand->headNode->element)>(p2.hand->headNode->element)){

    PlayingCard WinningCard = p1.hand->headNode->element;
    pile->insert(p1.hand->headNode->element);
    p1.hand->remove(p1.hand->headNode->element);

    PlayingCard LosingCard = p2.hand->headNode->element;
    pile->insert(p2.hand->headNode->element);
    p2.hand->remove(p2.hand->headNode->element);

    while(!(pile->len()==0)){
      p1.hand->insert(pile->headNode->element);
      pile->remove(pile->headNode->element);
    }
    cout << "\n" << "War " << wars << ": " << p1.playerName << " (" << WinningCard << ") defeated " << p2.playerName << " (" << LosingCard <<"): " << p1.playerName <<" " << p1.hand->len() << ", " << p2.playerName << " " << p2.hand->len() << "\n";
    outputfile << "\n" << "War " << wars << ": " << p1.playerName << " (" << WinningCard << ") defeated " << p2.playerName << " (" << LosingCard <<"): " << p1.playerName <<" " << p1.hand->len() << ", " << p2.playerName << " " << p2.hand->len() << "\n";

    if(p2.hand->len()==0){
      p1.wins++;
      cout << p1.playerName << " (" << p1.wins << ") DEFEATED " << p2.playerName;
      outputfile << p1.playerName << " (" << p1.wins << ") DEFEATED " << p2.playerName;
      return;
    }
    return;

  }else if((p1.hand->headNode->element)<(p2.hand->headNode->element)){

    PlayingCard LosingCard = p1.hand->headNode->element;
    pile->insert(p1.hand->headNode->element);
    p1.hand->remove(p1.hand->headNode->element);

    PlayingCard WinningCard = p2.hand->headNode->element;
    pile->insert(p2.hand->headNode->element);
    p2.hand->remove(p2.hand->headNode->element);

    while(!(pile->len()==0)){
      p2.hand->insert(pile->headNode->element);
      pile->remove(pile->headNode->element);
    }
    cout << "\n" << "War " << wars << ": " << p2.playerName << " (" << WinningCard << ") defeated " << p1.playerName << " (" << LosingCard <<"): " << p1.playerName << " " << p1.hand->len() << "," << p2.playerName << " " << p2.hand->len() << "\n";
    outputfile << "\n" << "War " << wars << ": " << p2.playerName << " (" << WinningCard << ") defeated " << p1.playerName << " (" << LosingCard <<"): " << p1.playerName << " " << p1.hand->len() << "," << p2.playerName << " " << p2.hand->len() << "\n";

    if(p1.hand->len()==0){
      p2.wins++;
      cout << p2.playerName << " (" << p2.wins << ") DEFEATED " << p1.playerName;
      outputfile << p2.playerName << " (" << p2.wins << ") DEFEATED " << p1.playerName;
      return;
    }
    return;

  }else{
    cout << "\n" << "War " << wars << ": " << p1.playerName << " (" << p1.hand->headNode->element << ") tied " << p2.playerName << " (" << p2.hand->headNode->element << ")";
    outputfile << "\n" << "War " << wars << ": " << p1.playerName << " (" << p1.hand->headNode->element << ") tied " << p2.playerName << " (" << p2.hand->headNode->element << "): "<< p1.playerName << " " << p1.hand->len() << ", " << p2.playerName << ": " << p2.hand->len();

    if(p1.hand->len()==0){
      p2.wins++;
      cout << p2.playerName << " (" << p2.wins << ") DEFEATED " << p1.playerName;
      outputfile << p2.playerName << " (" << p2.wins << ") DEFEATED " << p1.playerName;
      return;
    }else if(p2.hand->len()==0){
      p1.wins++;
      cout << p2.playerName << " (" << p2.wins << ") DEFEATED " << p1.playerName;
      outputfile << p2.playerName << " (" << p2.wins << ") DEFEATED " << p1.playerName;
      return;
    }
    cout << " " << p1.playerName <<": " << p1.hand->len() << ", " << p2.playerName <<": " << p2.hand->len();
    //outputfile.close();
    war(outputfile, wars);

  }
}

void Game::resetHands(){
  while(!(p1.hand->len()==0)){
    p1.hand->remove(p1.hand->headNode->element);
  }
  while(!(p2.hand->len()==0)){
    p2.hand->remove(p2.hand->headNode->element);
  }
}

Player Game::play(ofstream& outputfile){
  //outputfile.open("WarOutput.txt");
  resetHands();
  shuffleDeck();
  dealCards();
  cout << "\n" << "===";
  cout << "\n" << p1.playerName << " VS. " << p2.playerName << "\n";
  outputfile << "\n" << "===";
  outputfile << "\n" << p1.playerName << " VS. " << p2.playerName;
  int wars=0;
  int battles = 0;
  
  while(!(p1.hand->len()==0) && !(p2.hand->len()==0) || !(p1.hand->len()==1) && !(p2.hand->len()==1)){
    battles++;
    battle(outputfile, wars, battles);

    if(p1.hand->len()==0) return p2;
    if(p2.hand->len()==0) return p1;

    if((p1.hand->len()==1) && (p2.hand->len()==1)){
    p1.wins++;
    outputfile << "\n" << p1.playerName << " (" << p1.wins << ") " << " DEFEATED " << p2.playerName << " since they warred with 1 card remaining each in " << battles << " Battles and " << wars << " Wars";
    return p1;
    }
  }
  //outputfile.close();
  //if((p1.hand->len()==1) && (p2.hand->len()==1)) return p1;
  if(p1.hand->len()==0) return p2;
  return p1;
}
//TODO: battle
//TODO: war (what if both players tie on 1 card remaining)
//TODO: play
