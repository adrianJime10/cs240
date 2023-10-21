#include <string>
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
//#include "llc.h"
#include <cmath>
#include <ctgmath>
#include "node.cpp"

using namespace std;

template <class Type>
class LLC{
	public:
	LLC();
	LLC(const LLC &copy);

	void operator=(LLC const &obj);

	LLC operator+(LLC const &obj);

	void operator+=(int n);

	friend ostream & operator<<(ostream &out, const LLC<Type> &obj){
	Node<Type> *temp = obj.headNode;
	if(obj.headNode==NULL){
		out << "This list is empty!";
		return out;
	}
	out << "[";
	while(temp!=NULL){
		out << temp->element << ", ";
		temp = temp->next;
	}
	out << "]";
	return out;
	}


	bool contains(const Type &check);

 	bool insert(const Type &data);

	void remove(const Type &data);

	void shuffle();

	void head(int n);

	int len();

	void join(LLC other);

	Type tail();

	~LLC();

	Node<Type> *headNode;
	Node<Type> *tailNode;

	private:

};

template <class Type>
LLC<Type>::LLC(){
	tailNode = NULL;
	headNode = NULL;
}

template <class Type>
LLC<Type>::~LLC(){
	Node<Type> *current = headNode;
	while(current!=NULL){
		Node<Type> *next = current->next;
		delete current;
		current = next;
	}
}

template <class Type>
LLC<Type>::LLC(const LLC &obj){
	tailNode=NULL;
	headNode=NULL;
	Node<Type> *traverser = obj.headNode;
	while(traverser!=NULL){
		Type el = traverser->element;
		insert(el);
		traverser=traverser->next;
	}
}

template <class Type>
void LLC<Type>::operator=(LLC const &obj){
	Node<Type> *current = headNode;
	while(current!=NULL){
		Node<Type> *next = current->next;
		delete current;
		current = next;
	}
	Node<Type> *traverser = obj.headNode;
	while(traverser!=NULL){
		insert(traverser->element);
		traverser=traverser->next;
	}
}

template <class Type>
void LLC<Type>::operator+=(int n){
	Node<Type> *next=headNode->next;
	int i=0;
	while (i<n && headNode!=NULL){
		insert(headNode->element);
		delete headNode;
		headNode = next;
		next=headNode->next;
		/*Node *temp= new Node();
		temp->element=headNode->element;
		if(tailNode==NULL){
			headNode=temp;
		}else{
			tailNode->next=temp;
		}
		tailNode=temp;*/
		i++;
	}
	//TODO:GET THIS TO WORK
}

/*bool LLC::insert(const string &data){
	bool tf=false;
	Node *temp= new Node();
	temp->element=data;
	if(tailNode==NULL){
		headNode=temp;
		tf=true;
	}else{
		tailNode->next=temp;
		tf=true;
	}
	tailNode=temp;
	return tf;
}*/

template <class Type>
bool LLC<Type>::insert(const Type &data){
	bool tf=false;
	Node<Type> *temp= new Node<Type>();
	temp->element=data;
	if(tailNode==NULL){
		headNode=temp;
		tf=true;
	}else{
		tailNode->next=temp;
		tf=true;
	}
	tailNode=temp;
	return tf;
}

/*
template <class Type>
ostream & operator<<(ostream &out, const LLC<Type> &obj){
	Node *temp = obj.headNode;
	if(obj.headNode==NULL){
		out << "This list is empty!";
		return out;
	}
	out << "[";
	while(temp!=NULL){
		out << temp->element << ", ";
		temp = temp->next;
	}
	out << "]";
	return out;
}*/

template <class Type>
int LLC<Type>::len(){
	Node<Type> *traverser = headNode;
	int size=0;
	while(traverser!=NULL){
		size++;
		traverser=traverser->next;
	}
	return size;
}

template <class Type>
bool LLC<Type>::contains(const Type &check){
	bool tf = false;
	Node<Type> *traverser = headNode;
	while(traverser!=NULL){
		if((traverser->element)==check){
			tf=true;
		}
		traverser=traverser->next;
	}
	return tf;
}

template <class Type>
void LLC<Type>::head(int n){
	Node<Type> *traverser = headNode;
	cout << "[";
	int x=1;
	while(traverser!=NULL && x<n+1){
		cout << traverser->element << ", ";
		traverser=traverser->next;
		x++;
	}
	cout << "]";
}

template <class Type>
Type LLC<Type>::tail(){
	if(tailNode!=NULL){
		return tailNode->element;
	}
}

template <class Type>
void LLC<Type>::join(LLC other){
	Node<Type> *traverser = other.headNode;
	while(traverser!=NULL){
		Type el = traverser->element;
		insert(el);
		traverser=traverser->next;
	}
	//tailNode->next=other.headNode;
	//cout <<"headnode next of other: " << other.headNode->next->element; << "tailnode of other: " << other.tailNode->element;
	//tailNode=other.tailNode;
	//cout << tailNode->element;
	//delete other.headNode;
	//delete other.tailNode;
	//TODO:MAKE THIS WORK!
}

/*template <class Type>
void LLC<Type>::remove(const Type &check){
	//cout << "0";
	Node<Type> *prev=headNode;
	Node<Type> *current=headNode->next;
	if(headNode==NULL){
		//cout << "1";
		return;
	}else if(prev->element==check){
		//cout << "2";
		headNode->next=current->next;
		headNode=current;
		delete prev;
		prev=headNode;
		current=headNode->next;
	}
	while(current!=NULL){
		if(prev->element==check){
			//cout << "3";
			headNode->next=current->next;
			headNode=current;
			delete prev;
			prev=headNode;
			current=headNode->next;
		}else if(current->element==check){
			//cout << "4";
			prev->next=current->next;
			if(current->next==tailNode->next && current->element==tailNode->element){
				tailNode=prev;
				tailNode->next=NULL;
			}
			delete current;
			//current=prev->next;
		}
		//cout << "5";
		prev=prev->next;
		current=current->next;
	}
}*/

template <class Type>
void LLC<Type>::remove(const Type &check){
	//cout << "0";
	Node<Type> *current=headNode;
	if(headNode==NULL){
		//cout << "1";
		return;
	}else if(headNode->element==check){
		//cout << "2";
		if(current->next!=NULL){
			Node<Type> *newHead = headNode->next;
			delete headNode;
			headNode=newHead;
			return;
		}else{
			delete headNode;
			headNode=NULL;
			tailNode=NULL;
			return;
		}		
	}
	while(current!=NULL && !(current->next->element==check)){
		current=current->next;
	}
	if(current->next==NULL){
		return;
	}
	Node<Type> *del = current->next;
	if(current->next->next==NULL){
		tailNode = current;
	}
	current->next=current->next->next;
	delete del;
}

/*template <class Type>
void LLC<Type>::shuffle(){
	int length = this->len();
	double shufflenum = length / 3;
	int realshuffle = ceil(shufflenum);
	*this+=realshuffle;
}*/

template <class Type>
void LLC<Type>::shuffle(){
	Type elemToShuf;
	//cout << "RANDOM NUMMMMMMMM" << randomNum;
	int length = this->len();
	double shufflenum = length / 2;
	for(int i=0;i<200;i++){
		int randomNum = rand() % this->len()-10;
		Node<Type>* traverser = headNode;
		for(int i=0;i<randomNum;i++){
			traverser=traverser->next;
		}
		elemToShuf=traverser->element;
		this->remove(elemToShuf);
		this->insert(elemToShuf);
	}
}

template <class Type>
LLC<Type> LLC<Type>::operator+(const LLC &obj){
	LLC *newList = new LLC();
	Node<Type> *list1 = headNode;
	Node<Type> *list2 = obj.headNode;
	while(list1!=NULL){
		Type el = list1->element;
		newList->insert(el);
		list1=list1->next;
	}
	while(list2!=NULL){
		Type el = list2->element;
		newList->insert(el);
		list2=list2->next;
	}
	return *newList;
}


/*
if(current!=NULL){
			headNode->element=headNode->next->element;
			Node<Type> *del = headNode->next;
			headNode->next=headNode->next->next;
			delete del;
		}else{
			delete headNode;
			headNode=NULL;
			tailNode=NULL;
		}	
*/
