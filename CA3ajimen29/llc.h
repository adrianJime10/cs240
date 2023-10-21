#include <iostream>
#include "node.h"
#include <string>

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

