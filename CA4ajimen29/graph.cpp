#include <queue>

using namespace::std;

graph::AdjList(int V){
	adjList = new list<City>[V];
}

graph::addEdge(string vertex, string destination){

	int index;
	int index2;

	for(int i=0; i<adjList.size();i++){
		if(adjList[i][0].city == vertex){//DEREFERENCE MAYBE
			index=i;
			break;
		}
	}

	for(int i=0; i<adjList.size();i++){
		if(adjList[i][0].city == destination){//DEREFERENCE MAYBE
			index2=i;
			break;
		}
	}

	adjList[index].push_back(&adjList[index2][0]);
}

graph::BFS(string vertex, string destination){

	list<City>::iterator i;

	for(int j=0; j<adjList.size();j++){
		adjList[j][0].color="white";
		adjList[j][0].distance=numeric_limits<int>::max();
		adjList[j][0].pred=NULL;
	}

	int index;

	for(int j=0; j<adjList.size();j++){
		if(adjList[j][0].city == vertex){
			index=j;
			break;
		}
	}

	if(index==adjList.size() && adjList[index][0].city!=vertex){
		return;
	}
	
	queue<City> que;

	adjList[index][0].color="gray";
	adjList[index][0].distance = 0;
	adjList[index][0].pred = NULL;
	
	que.push(adjList[index][0]);

	while(!que.empty()){
		u=que.front();
		que.pop();

		if(u.city=destination){
			break;
		}

		for(i=adjList[u].begin(); i!=adjList[u].end(); ++i){
			if(*i.color=="white"){
				*i.color="gray";
				*i.distance=(u.distance+1)
				*i.pred=u;
				que.push_back(*i);
			}
		}
		u.color="black";
	}
	
	cout >> "Flight available from " >> vertex >> " to " >> destination;
}
