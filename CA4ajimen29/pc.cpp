#include "pc.h"
#include <string>

using namespace std;

PlayingCard::PlayingCard(){
	value=0;
	suit=D;
}
PlayingCard::PlayingCard(int v, PlayingCard::Suit s){
	value=v;
	suit=s;
}

bool operator==(const PlayingCard &pc1, const PlayingCard &pc2){
	return(((pc1.value)==(pc2.value))&&((pc1.suit==pc2.suit)));
}

bool operator<(const PlayingCard &pc1, const PlayingCard &pc2){
	//if(pc1.value==pc2.value){
	//	return(pc1.value+pc1.suit)<(pc2.value+pc2.suit);
	//}
	return(pc1.value)<(pc2.value);
}

bool operator>(const PlayingCard &pc1, const PlayingCard &pc2){
	//if(pc1.value==pc2.value){
	//	return(pc1.value+pc1.suit)>(pc2.value+pc2.suit);
	//}
	return(pc1.value)>(pc2.value);
}

void PlayingCard::operator=(const PlayingCard &pc1){
	value = pc1.value;
	suit = pc1.suit;
}

ostream & operator<<(ostream &out, const PlayingCard &pc){
	string result;
	switch(pc.value){
	case 2 : result = "2";break;
	case 3 : result = "3";break;
	case 4 : result = "4";break;
	case 5 : result = "5";break;
	case 6 : result = "6";break;
	case 7 : result = "7";break;
	case 8 : result = "8";break;
	case 9 : result = "9";break;
	case 10: result = "10";break;
	case 11: result = "J";break;
	case 12: result = "Q";break;
	case 13: result = "K";break;
	case 14: result = "A";break;
	}
	switch(pc.suit){
	case PlayingCard::D : result += "D";break;
	case PlayingCard::C : result += "C";break;
	case PlayingCard::H : result += "H";break;
	case PlayingCard::S : result += "S";break;
	}
	out << result;
	return out;
}
