#include <string>

using namespace std;

class Voter{

	public:
	Voter();
	Voter(string lastNam, string firstNam, string userI, string passwor, int ag, int streetNumbe, string streetNam, string tow, string zipCod, float amountDonate);

	void secondLevel();

	void updateInfo();

	void changePass();

	void viewInfo();

	void donateAmount();

	void reportInfo();

	void validatePassword(string &pass);

	void validateNum(string &num);

	string getLastName();

	string getFirstName();

	int getAge();

	int getStreetNumber();

	string getStreetName();

	string getTown();

	string getZipcode();

	string getUserID();

	string getPassword();

	float getAmountDonated();

	private:
	string lastName;
	string firstName;
	string userID;
	string password;
	int age;
	int streetNumber;
	string streetName;
	string town;
	string zipCode;
	float amountDonated;
};
