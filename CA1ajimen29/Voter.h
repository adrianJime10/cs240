#ifndef VOTER
#define VOTER

void newInfo(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode, float &amountDonated);

void updateInfo(string &lastName, string &firstName, int &age, int &streetNumber, string &streetName, string &town, string &zipCode, const float &amountDonated);

void viewInfo(const string &lastName, const string &firstName, const int &age, const int &streetNumber, const string &streetName, const string &town, const string &zipCode, const float &amountDonated);

void donateAmount(float &amountDonated);

void reportInfo(const string &lastName, const float &amountDonated);

#endif
