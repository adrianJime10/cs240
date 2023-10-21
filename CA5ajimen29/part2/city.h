#ifndef CITY_H
#define CITY_H
#include <string>
#include <vector>
#include <limits>
#include "edge.h"

using namespace std;

class City{
	
	public:
	
	City();
	City(string daCity);
	void operator=(City const &obj);

	string city;
	string color;
	string pred;
	vector<Edge*> edges;
	int distance;
};

#endif /* CITY_H */
