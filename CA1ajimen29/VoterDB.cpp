#include <string>
#include <iostream>
#include <stdlib.h>
#include <typeinfo>


using namespace std;

void newInfo(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode, float &amountDonated){
	cout << "Username: ";
	cin >> userID;
	cout << "Password: ";
	cin >> password;
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
	cin >> streetName;
	cout << "Town: ";
	cin >> town;
	cout << "Zip Code: ";
	cin >> zipCode;
	while(!cin){
		cin.clear();
		cin.ignore();
		cout << "Zip code must be a number. \nZip code: ";
		cin >> zipCode;
	}
	amountDonated = 0;
	}

void updateInfo(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode, const float &amountDonated){
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
		cout << "House Number must be a number. \nHouse number: ";
		cin >> streetNumber;
	}
	cout << "Street Name: ";
	cin >> streetName;
	cout << "Town: ";
	cin >> town;
	cout << "Zip Code: ";
	cin >> zipCode;
	}
	
void viewInfo(const string &lastName, const string &firstName, const int &age, const int &streetNumber, const string &streetName, const string &town, const string &zipCode, const float &amountDonated){
	cout << "\nDonor Info:\n";
	cout << firstName + " " + lastName + ": age " + to_string(age) + "\n";
	cout << to_string(streetNumber) + " " + streetName + "\n";
	cout << town + " " + zipCode + "\n";
	cout << "Currently Amount Donated: $" + to_string(amountDonated) + "\n";
	}

void donateAmount(float &amountDonated){
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
	cout << "$" + to_string(donation) + " donated.\n";
	}


void reportInfo(const string &lastName, const float &amountDonated){
	cout << "\n" + lastName + ": $" + to_string(amountDonated) + "\n";	
	}

void validateUserID(const string &userID){
	int flag = 0;
	while(strlen(userID)<5 || strlen(userID)>10){
		cout << "Username must be atleast 5 characters and at most 10 characters.";
		cout << "Username: ";
		cin.clear();
		cin.ignore();
		cin >> userID;
	}
	for(int i=0;i<strlen(userID);i++){
		if(!(userID[i].isdigit()) || !(userID[i].isalpha())){
			flag=1;
		}
	}
	if(flag==1){
		cout << "Username must consist of only digits and characters."
		cin.clear();
		cin.ignore();
		cin >> userID;
		validateUserID();
	}
}

