/*
 * List.cpp
 * Student Name: Zach Wibbenmeyer
 * Date: October 13, 2015
 * Begun By: Zach Wibbenmeyer, for CS 112 at Calvin College
 */

//include the necessary modules
#include "List.h"
using namespace std;

/* DefaultConstructor() - Initializes the variables
 * PostCondition - The list will have its default values
 */
List::List() {
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}

/* Desconstructor() - Clears the instance variables so memory isn't leaked
 * PostCondition: The memory of the instance variables for the list will
 * 		be cleared
 */
List::~List() {
	delete myFirst;          // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
	myFirst = myLast = NULL; // clear myFirst and myLast (optional)
	mySize = 0;              // clear mySize (optional)
}

/*
 * Default Node Constructor() - Initializes the instance variables in the node constructor
 * Post-Condition - The Node will have its default values
 */
List::Node::Node() {
	myItem = 0;
	myNext = NULL;
}

//Node Deconstructor() - Clears the instance variables so memory is not leaked
List::Node::~Node() {
	delete myNext;  // delete the next node, invoking ~Node() in it
				  	// (does nothing if myNext == NULL)
	myNext = NULL;  // clear myNext (optional)
	myItem = 0;     // clear myItem (optional)
}

/* NodeExplicitConstructor() - Assigns myItem to it and myNext to next
 * @param: Item --> it, Node* --> next
 */
List::Node::Node(Item it, Node * next) {
	myItem = it;
	myNext = next;
}

/* getSize() method
 * @return: mySize
 */
unsigned List::getSize() const {
	return mySize;
}

/* getFirst() method - if mySize is negative or myFirst is empty, throws an exception
 * 		otherwise it returns the value of myItem in the Node whose address is
 * 		myFirst
 * @return: myFirst -> myItem
 */
Item List::getFirst() const {
	if ((mySize < 0) or (myFirst == NULL)) {
		throw std::underflow_error("mySize is negative or myFirst is NULL");
	}
	return myFirst -> myItem;
}

/* getLast() method - if mySize is negative or myLast is empty, throws an exception
 * 		otherwise returns the value of myItem in the Node whose address
 * 		is in myFirst
 * @return: myLast -> myItem
 */
Item List::getLast() const {
	if ((mySize < 0) or (myLast == NULL)) {
		throw std::underflow_error("mySize is negative or myLast is NULL");
	}
	return myLast -> myItem;
}

/* append() method - appends items to the end of the list and increments the size
 * @param: const Item& --> it
 * Precondition - mySize must be 0 or else myLast -> myNext = nodePtr
 * 		will be returned
 * Postcondition - myLast will = nodePtr and mySize will be incremented
 */
void List::append(const Item& it) {
	Node * nodePtr = new Node(it, NULL);
	if (mySize == 0) {
		myFirst = nodePtr;
	}
	else {
		myLast -> myNext = nodePtr;
	}
	myLast = nodePtr;
	mySize++;
}


/* List CopyConstructor() -
 * @param: const List& --> original
 * Precondition: size of original must be greater than 0
 */
List::List(const List& original) {
  myFirst = myLast = NULL;          //  set pointers
  mySize = 0;                       //   and size to 'empty' values
  if (original.getSize() > 0) {     //  if there are nodes to copy:
	 Node * oPtr = original.myFirst; //  start at the first node
	 while (oPtr != NULL) {         //  while there are more nodes:
		append(oPtr->myItem);       //   append the item in that node
		oPtr = oPtr->myNext;        //   advance to next node
	 }
  }
}

/* AssignmentOperator -
 * @param: const List& --> original
 * @return: *this
 * Precondition: original and I must be two distinct lists and size of
 * 		original must be greater than 0
 * Postcondition: *this will be returned
 */
List& List::operator=(const List& original) {
	if (this != &original) {
		delete myFirst;
		myFirst = myLast = NULL;
		mySize = 0;
		if (original.getSize() > 0) {
			Node * nPtr = original.myFirst;
			while (nPtr != NULL) {
				append(nPtr -> myItem);
				nPtr = nPtr -> myNext;
			}
		}
	}
	return *this;
}
