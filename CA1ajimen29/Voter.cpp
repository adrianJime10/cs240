#include <iostream>
#include <stdlib.h>
#include <string>


using namespace std;

void newInfo(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode, float &amountDonated);

void updateInfo(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode, const float &amountDonated);

void viewInfo(const string &lastName, const string &firstName, const int &age, const int &streetNumber, const string &streetName, const string &town, const string &zipCode, const float &amountDonated);

void donateAmount(float &amountDonated);

void reportInfo(const string &lastName, const float &amountDonated);


int main(int argc, char* argv[]){
	
	string Mode;
	string lastName = "[empty]";
	string firstName = "[empty]";
	string userID;
	string password;
	int age = -1;
	int streetNumber = 0;
	string streetName = "[empty]";
	string town = "[empty]";
	string zipCode = "-----";
	float amountDonated=0;

	do{
		cout << "\nEnter a command.\nChoose from [\"New\" \"Update\" \"View\" \"Donate\" \"Report\" \"Quit\"]\n: ";

		cin >> Mode;

		if(Mode=="New"){
			newInfo(lastName, firstName, age, streetNumber, streetName, town, zipCode, amountDonated);
		}else if(Mode=="Update"){
			updateInfo(lastName, firstName, age, streetNumber, streetName, town, zipCode, amountDonated);
		}else if(Mode=="View"){
			viewInfo(lastName, firstName, age, streetNumber, streetName, town, zipCode, amountDonated);
		}else if(Mode=="Donate"){
			donateAmount(amountDonated);
		}else if(Mode=="Report"){
			reportInfo(lastName, amountDonated);
		}else if(Mode!="Quit"){
			cout << "Command not recognized. Please try again.\n";
		}
	}while(Mode!="Quit");
}
