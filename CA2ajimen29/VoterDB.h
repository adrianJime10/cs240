#include "Voter.h"

class VoterDB{

	public:
	VoterDB(int maxVoters);

	void validateUserID(string &userID);

	void validatePassword(string &password);

	void validateZipCode(string &zipCode);
	
	void firstLevel();

	void newInfo();

	void reportInfo();

	void login();

	void donateAmount(float &amountDonated);

	void saveInfo();

	void loadInfo();

	void load(string fullName);

	~VoterDB();

	private:
	int max;
	Voter *voters;
};
