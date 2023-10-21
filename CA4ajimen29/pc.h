#include <string>

using namespace std;

class PlayingCard{
	public:

	enum Suit {D=1, C=2, H=3, S=4};
	friend bool operator>(const PlayingCard &pc1, const PlayingCard &pc2);
	friend bool operator<(const PlayingCard &pc1, const PlayingCard &pc2);
	friend bool operator==(const PlayingCard &pc1, const PlayingCard &pc2);
	void operator=(const PlayingCard &pc1);
	friend ostream & operator<<(ostream &out, const PlayingCard &pc);

	PlayingCard(int v, PlayingCard::Suit s);
	PlayingCard();

	//~PlayingCard();

	int value;
	Suit suit;

	private:

};
