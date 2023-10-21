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

void AdjList::addEdge(string vertex,string destination,Time depart,Time arrive){

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

	adjList[index].push_back(adjList[index2][0]);//CONNECTS TWO NODES
	adjList[index][0]->edges.push_back(new Edge(adjList[index][0],adjList[index2][0],depart,arrive));//ADDS EDGE TO VECTOR IN CITY BASED ON DESTINATION CITY, ARRIVAL CITY, DEPARTURE TIME, ARRIVAL TIME!!!

}

/*void AdjList::BFS(string vertex, string destination){

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

	if(index==numLists && adjList[index][0]->city!=vertex){
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
			cout << "\n====Flight available from " << vertex << " to " << destination << "====\n";
			hopBack=u;
			cout << "\n====" << hopBack->pred;
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
	itinerary.push_back(hopBack->city);
	while(hopBack->pred!=""){
		itinerary.push_back(hopBack->pred);
		for(int i=0; i<numLists;i++){
			if(adjList[i][0]->city == hopBack->pred){//DEREFERENCE MAYBE
				hopBack=adjList[i][0];
				break;
			}
		}
	}
	cout <<"\n======  ";
	for(int i=itinerary.size()-1;i>0-1;i--){
		cout << itinerary[i] << "->";
	}
	cout <<"  ======";
}*/

/*void AdjList::dijkstra(string vertex, string destination, Time depart){
	City* u;
	Edge e;

	int index;
	int index2;

	for(int i=0; i<numLists;i++){
		if(adjList[i][0]->city == vertex){//DEREFERENCE MAYBE
			index=i;
			break;
		}
	}

	for(int i=0; i<numLists;i++){
		if(adjList[i][0]->city == destination){//DEREFERENCE MAYBE
			index2=i;
			break;
		}
	}

	vector<City*> que;
	vector<City*> earliestTime;

	//for(int i=0;i<numLists;i++){
	e=adjList[index][0]->edges[0];
	for(int j=0;j<adjList[index][0]->edges.size();j++){
		if(depart.compareTimes(e.departureTime)){//??????
			if(adjList[index][0]->edges[j].departureTime<e.departureTime){
				e=adjList[index][0]->edges[j];
			}
		}
		else if(!depart.compareTimes(e.departureTime)){
			if(j+1<adjList[index][0]->edges.size()){
				e=adjList[index][0]->edges[j+1];
			}
			else{
				cout << "No itinerary possible. Sorry!";
			}
		}
	}

	que.push(e);

	string destCity="";
	while(destCity!=destination){
		for(int i=0;i<
		que.pop();
		
	}
}*/

void AdjList::BFS(string vertex, string destination, Time depart){

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

	if(index==numLists && adjList[index][0]->city!=vertex){
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
	itinerary.push_back(hopBack->city);

	while(hopBack->pred!=""){
		itinerary.push_back(hopBack->pred);
		for(int i=0; i<numLists;i++){
			if(adjList[i][0]->city == hopBack->pred){//DEREFERENCE MAYBE
				hopBack=adjList[i][0];
				break;
			}
		}
	}

	vector<Edge> earliestTime;
	string cityToCheck;
	Edge* e;
	int indexFound;

	for(int k=itinerary.size()-1;k>0-1;k--){
		//FINDS FIRST CITY NODE
		cityToCheck = itinerary[k];
		for(int o=0;o<numLists;o++){
			if(adjList[o][0]->city==cityToCheck){
				indexFound=o;
				break;
			}
		}
		//SETS edge to first edge in vector, then proceeds to check for earliest edge!	
		e= adjList[indexFound][0]->edges[0];

		for(int j=0;j<adjList[indexFound][0]->edges.size();j++){
			//Check if edge's departure time is indeed after specified one
			if(depart.compareTimes(e->departureTime)){
				//Check if there is an edge earlier than the current one that satisfies 					requirements
				if(adjList[indexFound][0]->edges[j]->departureTime.compareTimes(e->departureTime) && depart.compareTimes(adjList[indexFound][0]->edges[j]->departureTime)){
					e=adjList[indexFound][0]->edges[j];
				}
			}
			else if(!depart.compareTimes(e->departureTime)){
				//Current edge's departure time is not after specified departure time, 					try next one!
				if(j+1<adjList[indexFound][0]->edges.size()){
					e=adjList[indexFound][0]->edges[j+1];
				}
				//No possible edge found within vector!
				else{
					cout << "No itinerary possible. Sorry!";
					return;
				}
			}
		}

		//Pushes edge into vector of earliest edges
		earliestTime.push_back(*e);

		//SETS NEW DEPARTURE TIME TO PREVIOUS FLIGHT'S ARRIVAL TIME
		depart = e->arrivalTime;
	}


	cout <<"\n======  ";
	for(int i=itinerary.size()-1;i>0-1;i--){
		cout << itinerary[i] << earliestTime[i].departureTime.hr << ":" << earliestTime[i].departureTime.min << earliestTime[i].departureTime.aftermorn << " " << earliestTime[i].arrivalTime.hr << ":" << earliestTime[i].arrivalTime.hr << earliestTime[i].arrivalTime.aftermorn << " " << "->";
	}
	cout <<"  ======\n\n";
	itinerary.erase(itinerary.begin(),itinerary.end());
}
