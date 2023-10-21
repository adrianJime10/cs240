#include <string>
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include "Voter.h"
#include <iomanip>

using namespace std;

Voter::Voter(string lastNam, string firstNam, string userI, string passwor, int ag, int streetNumbe, string streetNam, string tow, string zipCod, float amountDonate){
	lastName=lastNam;
	firstName=firstNam;
	userID=userI;
	password=passwor;
	age=ag;
	streetNumber=streetNumbe;
	streetName=streetNam;
	town=tow;
	zipCode=zipCod;
	amountDonated=amountDonate;
}

Voter::Voter(){
	lastName = "[empty]";
	firstName = "[empty]";
	userID = "[empty]";
	password = "[empty]";
	age = -1;
	streetNumber = 0;
	streetName = "[empty]";
	town = "[empty]";
	zipCode = "-----";
	amountDonated=0;
}

void Voter::secondLevel(){
	string Mode;
	do{
		cout << "\nEnter a command.\nChoose from [\"Update\" \"Passwd\" \"View\" \"Donate\" \"Report\" \"Logout\"]\n: ";

		cin >> Mode;

		if(Mode=="Update"){
			updateInfo();
		}else if(Mode=="Passwd"){
			changePass();
		}else if(Mode=="View"){
			viewInfo();
		}else if(Mode=="Donate"){
			donateAmount();
		}else if(Mode=="Report"){
			reportInfo();
		}else if(Mode!="Logout"){
			cout << "Command not recognized. Please try again.\n";
		}
	}while(Mode!="Logout");
}

void Voter::updateInfo(){

	string i_lastName;
	string i_firstName;
	string i_age;
	string i_streetNumber;
	string i_streetName;
	string i_town;
	string i_zipCode;

	cout << "Current last name is: "+ lastName + "\nLast name: ";
	cin.clear();
	cin.ignore();
	getline(cin, i_lastName);
	cout << "Current first name is: " + firstName + "\nFirst name: ";
	cin.clear();
	getline(cin, i_firstName);
	cout << "Current age is: " + to_string(age) + "\nAge: ";
	cin.clear();
	getline(cin, i_age);
	validateNum(i_age);

	cout << "Current street number is: "+ to_string(streetNumber) +"\nStreet number: ";
	cin.clear();
	getline(cin, i_streetNumber);
	validateNum(i_streetNumber);

	cout << "Current street name is: "+ streetName+ "\nStreet Name: ";
	cin.clear();
	getline(cin, i_streetName);
	cout << "Current town is: "+town+"\nTown: ";
	cin.clear();
	getline(cin, i_town);
	cout << "Current zip code is: "+zipCode+"\nZip Code: ";
	cin.clear();
	getline(cin, i_zipCode);

	if(i_lastName!="") lastName= i_lastName;
	if(i_firstName!="") firstName= i_firstName;
	if(i_age!="") age= stoi(i_age);
	if(i_streetNumber!="") streetNumber= stoi(i_streetNumber);
	if(i_streetName!="") streetName= i_streetName;
	if(i_town!="") town= i_town;
	if(i_zipCode!="") zipCode= i_zipCode;
	}

void Voter::changePass(){
	string i_oldPass;
	string i_newPass;
	string i_newPass1;

	cout << "Please enter your current password: ";
	cin >> i_oldPass;

	if(i_oldPass!=password){
		cout << "Sorry, that password was incorrect.";
	}else{
		cout << "Please enter your new password: ";
		cin >> i_newPass;
		validatePassword(i_newPass);

		cout << "Please re-enter your new password: ";
		cin >> i_newPass1;

		if(i_newPass==i_newPass1){
			password = i_newPass;
			//cout << password;
		}else{
			cout << "Sorry, the two passwords did not match.";
		}
	}
}
	
void Voter::viewInfo(){
	cout << "\nDonor Info:\n";
	cout << firstName + " " + lastName + ": age " + to_string(age) + "\n";
	cout << to_string(streetNumber) + " " + streetName + "\n";
	cout << town + " " + zipCode + "\n";
	cout<<fixed;
	cout<<setprecision(2);
	cout << "Currently Amount Donated: $" << amountDonated << "\n";
	}

void Voter::donateAmount(){
	float donation = 0;
	cout << "\nEnter Amount to Donate: ";
	cin >> donation;
	while(!cin){
		cin.clear();
		cin.ignore();
		cout << "Donation must be a number. \nDonation: ";
		cin >> donation;
	}
	while(donation<0){
		cin.clear();
		cin.ignore();
		cout << "Donation must be positive. \nDonation: ";
		cin >> donation;
	}
	if((amountDonated+donation)>2700){
		donation = 2700 - amountDonated;
		amountDonated=2700;
		cout << "Total amount donated cannot grow beyond $2,700.";
	}else{
		amountDonated +=donation;
	}
	cout<<fixed;
	cout<<setprecision(2);	
	cout << " $" << donation << " donated.\n";
}


void Voter::reportInfo(){
	cout<<fixed;
	cout<<setprecision(2);
	cout << "\n" << lastName << " $" << amountDonated << "\n";	
}

void Voter::validatePassword(string &pass){
	int flag;
	int digit;
	int otherChar;
	do{
		flag=0;
		digit=0;
		otherChar=0;
		if(pass.length()<6){
			flag=1;
		}
		for(int i=0;i<pass.length();i++){
			if(isdigit(pass[i])){
				digit=1;
			}else if(!(isalnum(pass[i]))){
				otherChar=1;
			}
		}
		if(flag==1||digit==0||otherChar==0){
			cout << "Password must be atleast 6 characters and contain atleast one digit and one character that is neither a digit nor a letter.";
			cout << "\nPassword: ";
			cin >> pass;
		}
	}while(flag==1 || digit == 0 || otherChar == 0);
}

void Voter::validateNum(string &num){
	int flag;
	do{
		flag=0;
		for(int i=0;i<num.length();i++){
			if(!(isdigit(num[i]))){
				flag=1;
			}
		}
		if(flag==1){
			cout << "Value must be a number.\n : ";
			cin.clear();
			getline(cin,num);
		}
	}while(flag==1);
}

string Voter::getUserID(){
	return userID;
}

string Voter::getPassword(){
	return password;
}

float Voter::getAmountDonated(){
	return amountDonated;
}

string Voter::getLastName(){
	return lastName;
}

string Voter::getFirstName(){
	return firstName;
}

int Voter::getAge(){
	return age;
}

int Voter::getStreetNumber(){
	return streetNumber;
}

string Voter::getStreetName(){
	return streetName;
}

string Voter::getTown(){
	return town;
}

string Voter::getZipcode(){
	return zipCode;
}
