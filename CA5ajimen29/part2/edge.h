#ifndef EDGE_H
#define EDGE_H
#include "time.h"
#include "city.h"

class Edge{

	public:

	Edge(City* prev, City* next, Time depart, Time arrive);
	Edge();
	
	int timeElapsed;
	City* prevCity;
	City* nextCity;
	Time departureTime;
	Time arrivalTime;
};

#endif /* EDGE_H */
