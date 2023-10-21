#include <list>
#include <string>
#include "graph.cpp"
#include <iostream>
#include <fstream>

//TODO: PARSE A FILE AND SPLIT EACH LINE INTO 5 ELEMENTS (BY WHITE SPACE!)

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
		cities->addEdge(departCity,arrivCity);
	}
	myfile.close();

	string dCity;
	string aCity;

	cout << "\nPlease specify a departure city: ";
	cin >> dCity;
	cout << "\nPlease specify an arrival city: ";
	cin >> aCity;

	//Create itinerary
	cout << "\n--------------------Outbound--------------------------\n";
	cout << "\nDeparture city: " << dCity << " //// Arrival city: " << aCity << "\n";
	cities->BFS(dCity,aCity);

	//Create itinerary in reverse direction
	cout << "\n---------------------Inbound--------------------------\n";
	cout << "\nDeparture city: " << aCity << " //// Arrival city: " << dCity << "\n";
	cities->BFS(aCity,dCity);

}
