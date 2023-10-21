#ifndef GRAPH_H
#define GRAPH_H
#include "city.cpp"
#include "time.h"
#include "edge.h"
#include <list>
#include <string>
#include <map>

using namespace std;

class AdjList{

	public:

	AdjList(int V);

	void addEdge(string vertex, string destination, Time depart, Time arrive);
	void BFS(string vertex, string destination, Time depart);
	void populateList();
	//void dijkstra(string vertex, string destination, Time depart);


	vector<City*> cityList;
	vector<City*> *adjList;
	vector<string> itinerary;
	int numLists;
};

#endif
