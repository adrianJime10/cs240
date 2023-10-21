#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
//#include "llc.h"
//#include "node.h"
//#include "player.h"
//#include "game.h"
#include "tournament.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){


	//enum Suit {D=1, C=2, H=3, S=4};
	//cout << "hi";
	ifstream inputfile;
	ofstream outputfile;
	outputfile.open("WarOutput.txt");
	if(!outputfile){
		cerr << "cant open output file" << endl;
	}
	inputfile.open(argv[1]);
	//cout <<"hi there";
	tournament t1(inputfile);
	if(t1.powerTwo(t1.players.size())){
		t1.playTourny(outputfile);
	}else{
		cout << "\n" << "Nice try, but that amount of players isn't a power of two!" << endl;
	}
	//cout << t1.players.size();
	outputfile.close();
	inputfile.close();

	/*//PlayingCard h(13,PlayingCard::S);
	PlayingCard f(13,PlayingCard::S);
	Player p1("p1");
	Player p2("p2");
	Game g1(p1,p2);

	g1.shuffleDeck();
	g1.dealCards();
	cout << *g1.p1.hand << '\n' << *g1.p2.hand;
	cout << '\n' << *g1.pile;
  //g1.battle();
	//g1.battle();
	//g1.war();
	g1.play();
	cout << *g1.p1.hand;
	//g1.war();
	//g1.war();
  //g1.war();
	//g1.war();
	//g1.war();
	//g1.war();
	//g1.war();
	//g1.war();
	//g1.war();
	//g1.war();
	cout << '\n' << *g1.pile;
	//g1.war();
	//g1.war();
	//g1.war();
	//g1.battle();
	//g1.battle();
	//g1.battle();*/

	/*LLC<int> *test = new LLC<int>;
	test->insert(1);
	test->insert(2);
	test->insert(3);
	test->insert(4);
	//test->remove("hey");
	//test->remove("sup");
	//test->remove("hi");
	//test->remove("oh");
	test->remove(test->tail());
	test->remove(test->tail());
	test->remove(test->tail());
	cout << test->tail();
	cout << *test;*/

	/*cout << g1.pile << '\n';
	//PlayingCard TailHere = g1.pile.tail();
	g1.p1.hand.insert(g1.pile.tail());
	cout << g1.p1.hand << '\n';
	//cout << TailHere;
	g1.pile.remove(g1.pile.tail());
	cout << g1.pile;*/

	//g1.shuffleDeck();
	//cout << g1.pile;
	//p1.hand->insert(f);
	//cout << *p1.hand;
	//cout << PlayingCard(10,PlayingCard::C);
	//p1.hand->insert(f);
	//cout << h;

	/*cout << h.suit << "\n\n";
	if(h==f) {cout << "\nyes\n";}
	else {cout <<"\nno\n";}
	==WORKS!!!!*/

	/*if(h>f) {cout << "\nyes\n";}
	else {cout <<"\nno\n";}
	>WORKS!!!!!*/

	/*if(h<f) {cout << "\nyes\n";}
	else {cout <<"\nno\n";}
	<WORKS!!!!!*/



	/*string mode = "";
	string insertion;
	LLC <int>*list = new LLC<int>();
	list->insert(1);
	cout << *list;
	LLC <string>*list3 = new LLC<string>();
	LLC <string>*list4 = new LLC<string>();

	list3->insert("hi");
	list3->insert("hey");
	list3->insert("hi");
	list3->insert("ohsup");
	list3->insert("sup");
	list3->insert("hi");
	list3->insert("sup");

	list->insert("hi1");
	list->insert("hey1");
	cout << *list << " Insert working\n";

	list4->insert("hi4");
	list4->insert("hey4");

	LLC <string>list2(*list);
	delete list;
	cout << list2 << " Copy constructor working\n";

	/*cout << list2.contains("hi1") << "\n";
	cout << list2.contains("hia") << " Contains working\n";

	list2.head(1);
	cout << "\n";
	list2.head(3);
	cout << " Head working\n";

	cout << list2.tail();
	cout << " Tail working\n";

	list2+=1;
	cout << list2 << " += working\n";


	cout << *list3 << "\n";
	list2.join(*list3);
	cout << list2 << "\n";
	cout << " Join working\n";

	//list3->remove("hi");
	//cout << *list3;

	list3->shuffle();
	cout << *list3 << "\n";

	LLC <string>*list5 = new LLC<string>();
	*list5 = (*list3)+(*list4);
	cout << *list5;

	delete list5;
	delete list3;
	delete list4;

	/*while(mode!="quit"){
		cout << "Hey! Choose from 'Insert' 'Display' 'OverloadA' 'Copy' 'Length'(so far)";
		cin >> mode;
		if(mode == "Insert"){
			cout << "What would you like to insert?";
			cin >> insertion;
			list->insert(insertion);
		}else if(mode == "Display"){
			cout << "Displaying....\n";
			cout << *list;
			cout << "\n";
		}else if(mode == "OverloadA"){
			LLC *newList = new LLC();
			*newList = *list;
			cout << *newList;
		}else if(mode == "Copy"){
			LLC newerList(*list);
			cout << newerList;
		}else if(mode =="Length"){
			cout << list->len() << "\n";
		}else if(mode =="Destruct"){
			delete list;
			cout << *list;
		}
	}*/
}
