#include <iostream>
#include <stdlib.h>
#include <string>
#include "VoterDB.h"
#include <sstream>
#include <iomanip>
#include <fstream>


using namespace std;

int main(int argc, char* argv[]){

	cout<<fixed;
	cout<<setprecision(2);

	int myint;
	
	if(argc==2){
		stringstream convert(argv[1]);
		convert >> myint;
		VoterDB *voterDataBase = new VoterDB(myint);

		voterDataBase->firstLevel();
	}else if(argc==3){
		stringstream convert(argv[1]);
		convert >> myint;
		VoterDB *voterDataBase = new VoterDB(myint);

		voterDataBase->load(argv[2]);
		
		voterDataBase->firstLevel();
	}
}
