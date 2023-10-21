#include <queue>
#include "graph.h"
#include <iostream>

using namespace::std;

AdjList::AdjList(int V){
	adjList = new vector<City*>[V];
	numLists = V;
}

void AdjList::populateList(){
	for(int i=0;i<cityList.size();i++){
		adjList[i].push_back(cityList[i]);
	}
}

void AdjList::addEdge(string vertex, string destination){

	int index;
	int index2;

	for(int i=0; i<numLists;i++){
		if(adjList[i][0]->city == vertex){
			index=i;
			break;
		}
	}

	for(int i=0; i<numLists;i++){
		if(adjList[i][0]->city == destination){
			index2=i;
			break;
		}
	}
	adjList[index].push_back(adjList[index2][0]);
}

void AdjList::BFS(string vertex, string destination){

	City* hopBack;

	for(int j=0; j<numLists;j++){
		adjList[j][0]->color="white";
		adjList[j][0]->distance=numeric_limits<int>::max();
		adjList[j][0]->pred="";
	}

	int index;

	for(int j=0; j<numLists;j++){
		if(adjList[j][0]->city == vertex){
			index=j;
			break;
		}
	}

	if(index>numLists-1 && adjList[index][0]->city!=vertex){
		cout << "No itinerary available";
		return;
	}
	
	queue<City*> que;

	adjList[index][0]->color="gray";
	adjList[index][0]->distance = 0;
	adjList[index][0]->pred = "";
	
	que.push(adjList[index][0]);

	City* u;

	while(!que.empty()){
		u=que.front();
		que.pop();

		if(u->city==destination){
			cout << "\n====Itinerary available from " << vertex << " to " << destination << "====\n";
			hopBack=u;
			break;
		}

		int index3;

		for(int l=0; l<numLists;l++){
			if(adjList[l][0]->city == u->city){
				index3=l;
				break;
			}
		}

		for(int o=0; o<adjList[index3].size();o++){
			if(adjList[index3][o]->color=="white"){
				adjList[index3][o]->color="gray";
				adjList[index3][o]->distance=(u->distance+1);
				adjList[index3][o]->pred=u->city;
				que.push(adjList[index3][o]);
			}
		}
		u->color="black";
	}

	if(hopBack->city!=destination){
		cout << "No itinerary available";
		return;
	}
	itinerary.push_back(hopBack->city);
	while(hopBack->pred!=""){
		itinerary.push_back(hopBack->pred);
		for(int i=0; i<numLists;i++){
			if(adjList[i][0]->city == hopBack->pred){
				hopBack=adjList[i][0];
				break;
			}
		}
	}
	cout <<"\n======  ";
	for(int i=itinerary.size()-1;i>0-1;i--){
		cout << itinerary[i] << "->";
	}
	cout <<"  ======\n\n";

	itinerary.erase(itinerary.begin(),itinerary.end());
}
