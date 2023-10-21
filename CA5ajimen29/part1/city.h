#include <string>
#include <vector>
#include <limits>

using namespace std;

class City{
	
	public:
	
	City();
	City(string daCity);
	void operator=(City const &obj);

	string city;
	string color;
	string pred;
	int distance;
};
