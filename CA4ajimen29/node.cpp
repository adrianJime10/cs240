#include <string>
#include <stdlib.h>
//#include "node.h"

using namespace std;

template <class Type>
class Node{
	public:
	Node();

	Node<Type> *next;
	Type element;

	private:

};

template <class Type>
Node<Type>::Node(){
	next=NULL;
	//element="";
}
