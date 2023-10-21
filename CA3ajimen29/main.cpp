#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
//#include "llc.h"
#include "llc.cpp"
//#include "node.h"

using namespace std;

int main(int argc, char* argv[]){

	string mode = "";
	string insertion;
	LLC <string>*list = new LLC<string>();
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

	*/list2+=1;
	cout << list2 << " += working\n";


	cout << *list3 << "\n";
	list2.join(*list3);
	cout << list2 << "\n";
	cout << " Join working\n";

	/*list3->remove("hi");
	cout << *list3;*/

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
