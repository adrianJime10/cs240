#include "edge.h"

Edge::Edge(){
	prevCity = new City();
	nextCity = new City();
	depart = Time(0,0,"a");
	arrive = Time(0,0,"a");
}

Edge::Edge(City* prev, City* next, Time depart, Time arrive){
	prevCity=prev;
	nextCity=next;
	departureTime=depart;
	arrivalTime=arrive;
	timeElapsed=depart.minElapsed(arrive);
}
