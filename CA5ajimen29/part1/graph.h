#include "city.cpp"
#include <list>
#include <string>
#include <map>

using namespace std;

class AdjList{

	public:

	AdjList(int V);

	void addEdge(string vertex, string destination);
	void BFS(string vertex, string destination);
	void populateList();


	vector<City*> cityList;
	vector<City*> *adjList;
	vector<string> itinerary;
	int numLists;
};
