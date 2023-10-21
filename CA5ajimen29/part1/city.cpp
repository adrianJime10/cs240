#include "city.h"

using namespace std;

City::City(){
	city="";
	color="white";
	pred="";
	distance=0;
}

City::City(string daCity){
	city = daCity;
	color = "white";
	pred = "";
	distance = numeric_limits<int>::max();
}

void City::operator=(City const &obj){
	city=obj.city;
	color=obj.color;
	pred=obj.pred;
	distance=obj.distance;
}

