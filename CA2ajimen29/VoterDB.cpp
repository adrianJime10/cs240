#include <string>
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include "VoterDB.h"
#include <typeinfo>
#include <iomanip>
#include <fstream>
#include <ostream>

using namespace std;

VoterDB::VoterDB(int maxVoters){
	max=maxVoters;
	voters = new Voter[max];
}

VoterDB::~VoterDB(){
	delete voters;
}

void VoterDB::firstLevel(){
	string Mode;
	do{
		cout << "\nEnter a command.\nChoose from [\"Login\" \"New\" \"Report\" \"Save\" \"Load\" \"Quit\"]\n: ";

		cin >> Mode;

		if(Mode=="New"){
			newInfo();
		}else if(Mode=="Report"){
			reportInfo();
		}else if(Mode=="Login"){
			login();
		}else if(Mode=="Save"){
			saveInfo();
		}else if(Mode=="Load"){
			loadInfo();
		}else if(Mode!="Quit"){
			cout << "Command not recognized. Please try again.\n";
		}
	}while(Mode!="Quit");
}

void VoterDB::newInfo(){
	//cout << "yep: " + voters[0].getUserID();
	int numVoters=0;
	string userID;
	string password;
	string lastName;
	string firstName;
	int age;
	int streetNumber;
	string streetName;
	string town;
	string zipCode;
	for(int i=0;i<max;i++){
		if(voters[i].getUserID()=="[empty]"){
			//cout << i;
			//cout << max;
			//cout << numVoters;		
			break;
		}else{
			//cout << voters[i].getUserID();
			numVoters+=1;
		}
	}
	if(numVoters==max){
		//cout << "\n";
		//cout << typeid(voters[0]).name();
		//cout << "\n";
		//string info = voters[0].getUserID();
		//cout << info;
		//cout << numVoters;
		//cout << max;
		cout <<"Sorry, there are too many voters in this database.";
	}else{
		cout << "Username: ";
		cin >> userID;
		validateUserID(userID);
		int flag;
		do{
			flag = 0;			
			for(int i=0;i<max;i++){
				if(userID==voters[i].getUserID()){
					cout << "Sorry that username is already in use. Please select another: ";
					cin >> userID;
					flag=1;				
				}
			}
		}while(flag==1);
		cout << "Password: ";
		cin >> password;
		validatePassword(password);
		cout << "Last name: ";
		cin >> lastName;
		cout << "First name: ";
		cin >> firstName;
		cout << "Age: ";
		cin >> age;
		while(!cin){
			cin.clear();
			cin.ignore();
			cout << "Age must be a number. \nAge: ";
			cin >> age;
		}
		cout << "House number: ";
		cin >> streetNumber;
		while(!cin){
			cin.clear();
			cin.ignore();
			cout << "Street Number must be a number. \nStreet number: ";
			cin >> streetNumber;
		}
		cout << "Street name: ";
		cin.clear();
		cin.ignore();
		getline(cin,streetName);
		cout << "Town: ";
		cin.clear();
		getline(cin,town);
		cout << "Zip Code: ";
		cin >> zipCode;
		validateZipCode(zipCode);
		int amountDonated = 0;
		Voter *voter = new Voter(lastName, firstName, userID, password, age, streetNumber, streetName, town, zipCode, amountDonated);
		voters[numVoters]=*voter;
		//cout << voter[0].getUserID();
	}
}

void VoterDB::reportInfo(){
	int numVoters = 0;
	float totalDonated = 0;
	for(int i=0;i<max;i++){
		if(voters[i].getUserID()!="[empty]"){
			numVoters+=1;
		}
		totalDonated+=voters[i].getAmountDonated();
	}
	cout<<fixed;
	cout<<setprecision(2);
	cout << "\nAmount of voters: " << numVoters << "\nTotal amount donated: $" << totalDonated << "\n";
}

void VoterDB::validateUserID(string &userID){
	int flag;
	do{
		flag=0;
		if(userID.length()<5 || userID.length()>10){
			flag=1;
		}
		for(int i=0;i<userID.length();i++){
			if(!(isalnum(userID[i]))){
				flag=1;
				//cout << "\n" + userID[i];
			}
		}
		if(flag==1){
			cout << "Username must be atleast 5 characters and at most 10 characters.";
			cout << "Username: ";
			cin >> userID;
		}
	}while(flag==1);
}

void VoterDB::validatePassword(string &password){
	int flag;
	int digit;
	int otherChar;
	do{
		flag=0;
		digit=0;
		otherChar=0;
		if(password.length()<6){
			flag=1;
		}
		for(int i=0;i<password.length();i++){
			if(isdigit(password[i])){
				digit=1;
			}else if(!(isalnum(password[i]))){
				otherChar=1;
			}
		}
		if(flag==1||digit==0||otherChar==0){
			cout << "Password must be atleast 6 characters and contain atleast one digit and one character that is neither a digit nor a letter.";
			cout << "\nPassword: ";
			cin >> password;
		}
	}while(flag==1 || digit == 0 || otherChar == 0);
}

void VoterDB::validateZipCode(string &zipCode){
	int flag;
	do{
		flag=0;
		if(zipCode.length()!=5){
			flag=1;
		}
		for(int i=0;i<zipCode.length();i++){
			if(!(isdigit(zipCode[i]))){
				flag=1;
			}
		}
		if(flag==1){
			cin.clear();
			cin.ignore();
			cout << "Zip code must be 5 digits.";
			cout << "\nZip Code: ";
			cin >> zipCode;
		}
	}while(flag==1);
}

void VoterDB::login(){

	string userID;
	string password;

	cout << "Enter your username: ";
	cin >> userID;
		
	cout << "Enter your password: ";
	cin >> password;

	for(int i=0;i<max;i++){
		if(voters[i].getUserID()==userID && voters[i].getPassword()==password){
			cout << voters[i].getUserID();
			voters[i].secondLevel();
		}
	}
}

void VoterDB::saveInfo(){
	int numVoters = 0;
	string fileName;
	cout << "Please enter the name of the file to save as: ";
	cin >> fileName;
	string fullName = fileName + ".csv";
	ifstream rfile;	
	ofstream wfile;
	rfile.open(fullName);
	if(!rfile){
		wfile.open(fullName, ios::out);
		for(int i=0;i<max;i++){
			if(voters[i].getUserID()=="[empty]"){		
				break;
			}else{
				wfile << voters[i].getUserID() <<","<<voters[i].getPassword()<<","<<voters[i].getLastName()<<","<<voters[i].getFirstName()<<","<<voters[i].getAge()<<","<<voters[i].getStreetNumber()<<","<<voters[i].getStreetName()<<","<<voters[i].getTown()<<","<<voters[i].getZipcode()<<"\n";
				numVoters+=1;
			}
		}
		wfile.close();
	}else{
		string yesNo;
		cout << "This file already exists. Would you like to overwrite it?\nY or N: ";
		cin >> yesNo;
		if(yesNo=="Y"){
			wfile.open(fullName, ios::out | ios::trunc);
			for(int i=0;i<max;i++){
				if(voters[i].getUserID()=="[empty]"){		
					break;
				}else{
					wfile << voters[i].getUserID() <<","<<voters[i].getPassword()<<","<<voters[i].getLastName()<<","<<voters[i].getFirstName()<<","<<voters[i].getAge()<<","<<voters[i].getStreetNumber()<<","<<voters[i].getStreetName()<<","<<voters[i].getTown()<<","<<voters[i].getZipcode()<<","<<fixed<<setprecision(2)<<voters[i].getAmountDonated()<<"\n";
					numVoters+=1;
				}
			}
			wfile.close();
			rfile.close();
		}else if(yesNo=="N"){
			rfile.close();		
		}
	}
}

void VoterDB::loadInfo(){

	string lastName;
	string firstName;
	string userID;
	string password;
	string age;
	string streetNumber;
	string streetName;
	string town;
	string zipCode;
	string amountDonated;
 
	int i=0;
	ifstream rfile;
	string fileName;
	string temp;
	cout << "Please enter the name of the file you would like to load (without the .csv extension): ";
	cin >> fileName;
	string fullName = fileName + ".csv";
	cout<<fullName;
	rfile.open(fullName, ios::in);
	while(rfile.good()){
		while(getline(rfile,temp)){
			istringstream ss(temp);	
			getline(ss, userID, ',');
			getline(ss, password, ',');
			getline(ss, lastName, ',');
			getline(ss, firstName, ',');
			getline(ss, age, ',');
			getline(ss, streetNumber, ',');
			getline(ss, streetName, ',');
			getline(ss, town, ',');
			getline(ss, zipCode, ',');
			getline(ss, amountDonated, ',');
			cout<<userID<<town;
			voters[i] = Voter(lastName, firstName, userID, password, stoi(age), stoi(streetNumber), streetName, town, zipCode, stof(amountDonated));		
			i+=1;
			if(i==max)break;
		}
		if(i==max)break;
	}
}

void VoterDB::load(string fullName){

	string lastName;
	string firstName;
	string userID;
	string password;
	string age;
	string streetNumber;
	string streetName;
	string town;
	string zipCode;
	string amountDonated;
 
	int i=0;
	ifstream rfile;
	string fileName;
	string temp;
	
	rfile.open(fullName, ios::in);
	while(rfile.good()){
		while(getline(rfile,temp)){
			istringstream ss(temp);	
			getline(ss, userID, ',');
			getline(ss, password, ',');
			getline(ss, lastName, ',');
			getline(ss, firstName, ',');
			getline(ss, age, ',');
			getline(ss, streetNumber, ',');
			getline(ss, streetName, ',');
			getline(ss, town, ',');
			getline(ss, zipCode, ',');
			getline(ss, amountDonated, ',');
			cout<<userID<<town;
			voters[i] = Voter(lastName, firstName, userID, password, stoi(age), stoi(streetNumber), streetName, town, zipCode, stof(amountDonated));		
			i+=1;
			if(i==max)break;
		}
		if(i==max)break;
	}
}
