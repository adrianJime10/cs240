#include <list>
#include <string>
#include "graph.cpp"
#include "time.h"
#include <iostream>
#include <fstream>


//TODO: PARSE A FILE AND SPLIT EACH LINE INTO 5 ELEMENTS (BY WHITE SPACE!)

using namespace std;

int main(int argc, char* argv[]){

	int flag;
	vector<City*> listOfCities;
	vector<City*> validCities;
	string departCity;
	string arrivCity;
	string depTime;
	string arrTime;
	string cost;
	ifstream myfile;
	myfile.open(argv[1]);

	while(myfile >> departCity >> arrivCity >> depTime >> arrTime >> cost){
		City* newCity = new City(departCity);
		listOfCities.push_back(newCity);
	}
	myfile.close();

	for(int i=0;i<listOfCities.size();i++){
		flag=0;
		if(validCities.size()==0){
			validCities.push_back(listOfCities[i]);
		}
		for (int j=0;j<validCities.size();j++){
			if(listOfCities[i]->city==validCities[j]->city){
				flag=1;
			}
		}
		if(flag==0){
			validCities.push_back(listOfCities[i]);
		}
	}

	AdjList *cities = new AdjList(validCities.size());
	
	for(int k=0;k<validCities.size();k++){
		cities->cityList.push_back(validCities[k]);
	}

	cities->populateList();

	myfile.open(argv[1]);


	while(myfile >> departCity >> arrivCity >> depTime >> arrTime >> cost){
		int depHour = (int(depTime[0]))*10+(int(depTime[1]));
		int depMin = (int(depTime[3]))*10+(int(depTime[4]));
		int arrHour = (int(arrTime[0]))*10+(int(arrTime[1]));
		int arrMin = (int(arrTime[3]))*10+(int(arrTime[4]));
		Time objDepTime(depHour, depMin, depTime[5]);
		Time objArrivTime(arrHour, arrMin, arrTime[5]);
		cities->addEdge(departCity,arrivCity,objDepTime,objArrivTime);
	}


	myfile.close();

	string dCity;
	string aCity;
	string dTime;
	string aTime;

	cout << "\nPlease specify a departure city: ";
	cin >> dCity;
	cout << "\nPlease specify an arrival city: ";
	cin >> aCity;
	cout << "\nPlease specify a departure time for the outbound trip (in the form of hh:mmam or hh:mmpm: ";
	cin >> dTime;
	cout << "\nPlease specify a departure time for the inbound trip (in the form of hh:mmam or hh:mmpm: ";
	cin >> aTime;

	int dh=dTime[0];
	int dr=dTime[1];
	int db=dTime[3];
	int dv=dTime[4];

	int dHour = (dh)*10+(dr);
	int dMin = (db)*10+(dv);

	int ah=aTime[0];
	int ar=aTime[1];
	int ab=aTime[3];
	int av=aTime[4];

	int aHour = (ah)*10+(ar);
	int aMin = (ab)*10+(av);

	

	Time objDTime(dHour, dMin, dTime[5]);
	Time objATime(aHour, aMin, aTime[5]);

	cout << "\n--------------------Outbound--------------------------\n";
	cities->BFS(dCity,aCity,objDTime);
	cout << "\n---------------------Inbound--------------------------\n";
	cities->BFS(aCity,dCity,objATime);
}
