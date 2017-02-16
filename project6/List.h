/*
 * List.h
 * Student Name: Zach Wibbenmeyer
 * Date: July 14, 2015
 * Begun By: Zach Wibbenmeyer, for CS 112 at Calvin College
 */

//Include the necessary modules
#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;

#ifndef LIST_H_
#define LIST_H_

//Create a typedef of Item
typedef double Item;

template <class Item>

//Create a class List
class List {
public:
	//Implement all the methods
	List();
	virtual ~List();
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	List(const List& original);
	List& operator=(const List& original);
	bool operator!=(const List& list2);
	bool operator==(const List& list2);
	void readFrom(const string& fileName);
	void writeTo(ostream& out) const;
	int getIndexOf(const Item& index);
	Item remove(const int index);
	void sortList();
	void divide(List<Item>& l1, List<Item>& l2);
	List<Item> merge(List<Item>& v2);
	void insert(const Item& it, int index);
	void writeTo(const string& fileName);
	void prepend(const Item& item);
	void readFrom(istream& in);
private:
	//Implement methods for the Node
	struct Node {
		Item myItem;
		Node * myNext;
		Node();
		Node(Item it, Node * next);
		~Node();
		// Use ListTester
		friend class ListTester;
	};
	unsigned mySize;
	Node * myFirst;
	Node * myLast;
	// Use ListTester
	friend class ListTester;
};

/* DefaultConstructor() - Initializes the variables
 * PostCondition - The list will have its default values
 */
template <class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}

/* Desconstructor() - Clears the instance variables so memory isn't leaked
 * PostCondition: The memory of the instance variables for the list will
 * 		be cleared
 */
template <class Item>
List<Item>::~List() {
	delete myFirst;          // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
	myFirst = myLast = NULL; // clear myFirst and myLast (optional)
	mySize = 0;              // clear mySize (optional)
}

/*
 * Default Node Constructor() - Initializes the instance variables in the node constructor
 * Post-Condition - The Node will have its default values
 */
template <class Item>
List<Item>::Node::Node() {
	myItem = 0;
	myNext = NULL;
}

//Node Deconstructor() - Clears the instance variables so memory is not leaked
template <class Item>
List<Item>::Node::~Node() {
	delete myNext;  // delete the next node, invoking ~Node() in it
				  	// (does nothing if myNext == NULL)
	myNext = NULL;  // clear myNext (optional)
	myItem = 0;     // clear myItem (optional)
}

/* NodeExplicitConstructor() - Assigns myItem to it and myNext to next
 * @param: Item --> it, Node* --> next
 */
template <class Item>
List<Item>::Node::Node(Item it, Node * next) {
	myItem = it;
	myNext = next;
}

/* getSize() method
 * @return: mySize
 */
template <class Item>
unsigned List<Item>::getSize() const {
	return mySize;
}

/* getFirst() method - if mySize is negative or myFirst is empty, throws an exception
 * 		otherwise it returns the value of myItem in the Node whose address is
 * 		myFirst
 * @return: myFirst -> myItem
 */
template <class Item>
Item List<Item>::getFirst() const {
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
template <class Item>
Item List<Item>::getLast() const {
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
template <class Item>
void List<Item>::append(const Item& it) {
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
template <class Item>
List<Item>::List(const List<Item>& original) {
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
template <class Item>
List<Item>& List<Item>::operator=(const List<Item>& original) {
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

// Tammie wrote this method
template <class Item>
bool List<Item>::operator==(const List<Item>& list2) {
	if (mySize == 0 and list2.getSize() == 0) {
		return true;
	}
	else if (mySize != list2.getSize()) {
		return false;
	}
	else {
		Node * Ptr1 = myFirst;
		Node * Ptr2 = list2.myFirst;
		while (Ptr1) {
			if (Ptr1 -> myItem != Ptr2 -> myItem) {
				return false;
			}
			Ptr1 = Ptr1 -> myNext;
			Ptr2 = Ptr2 -> myNext;
		}
	}
	return true;
}

/* operator!=() method - creates the != operator
 * @param: const List& list2
 * @return: a bool
 */
template <class Item>
bool List<Item>::operator!=(const List<Item>& list2) {
	if (mySize == 0 and list2.getSize() == 0) {
		return false;
	}
	else if (mySize != list2.getSize()) {
		return true;
	}
	else {
		Node * Ptr1 = myFirst;
		Node * Ptr2 = list2.myFirst;
		while (Ptr1) {
			if (Ptr1 -> myItem != Ptr2 -> myItem) {
				return true;
			}
			Ptr1 = Ptr1 -> myNext;
			Ptr2 = Ptr2 -> myNext;
		}
	}
	return false;
}

/* readFrom(fileName) method - reads a list from a file
 * @param: const string& -> fileName
 * Postcondition: the list will be read from a file
 */
template <class Item>
void List<Item>::readFrom(const string& fileName) {
	ifstream fin(fileName.c_str());
	Item it;
	delete myFirst;
	delete myLast;
	mySize = 0;
	while (!fin.eof()) {
		fin >> it;
		append(it);
	}
}

/* writeTo(cout) method - writes the list to an ostream
 * @param: ostream& -> out
 * Postcondition: List will be written to an ostream
 */
template <class Item>
void List<Item>::writeTo(ostream& out) const {
	Node * Ptr1 = myFirst;
	while (Ptr1) {
		out << Ptr1 -> myItem;
		Ptr1 = Ptr1 -> myNext;
		if (Ptr1) {
			out << "\t\t";
		}
	}
}

/* getIndexOf() method - Uses a pointer to iterate through a list and get the the item in the index
 * @param: const Item& -> index
 * @return: an int, which is the item of the index searched for
 * 			-1 if the index is not found
 * Postcondition: Index searched for will be returned
 */
template <class Item>
int List<Item>::getIndexOf(const Item& index) {
	Node * Ptr1 = myFirst;
	int number = 0;
	while (Ptr1) {
		if (Ptr1 -> myItem == index) {
			return number;
		}
		number++;
		Ptr1 = Ptr1 -> myNext;
	}
	return -1;
}

/* remove() method - Uses two pointers to iterate through a list and return the item of
 * 		the number removed
 * @param: const Item& -> index
 * @return: Item of index removed and -1, and int
 * Postcondition: Index in list will be removed
 */
template <class Item>
Item List<Item>::remove(const int index) {
	Item temp;
	Node * Ptr1 = myFirst;
	Node * Ptr2;
	if (mySize == 1) {
		temp = myFirst -> myItem;
		delete myFirst;
		myLast = NULL;
		mySize--;
		return temp;
	}
	if (index <= 0) {
		myFirst = Ptr1 -> myNext;
		temp = Ptr1 -> myItem;
		Ptr1 -> myItem = NULL;
		Ptr1 -> myNext = NULL;
		mySize--;
		return temp;
	}
	for (int x = 0; x < index - 1; x++) {
		if (Ptr1 -> myNext == myLast) {
			temp = myLast -> myItem;
			myLast -> myItem = NULL;
			myLast -> myNext = NULL;
			myLast = Ptr1;
			mySize--;
			return temp;
		}
		Ptr1 = Ptr1 -> myNext;
		if (Ptr1 -> myNext == myLast) {
			temp = myLast -> myItem;
			myLast -> myItem = NULL;
			myLast -> myNext = NULL;
			myLast = Ptr1;
			mySize--;
			return temp;
		}
	}
	Ptr2 = Ptr1 -> myNext;
	Ptr1 -> myNext = Ptr2 -> myNext;
	temp = Ptr2 -> myItem;
	Ptr2 -> myItem = NULL;
	Ptr2 -> myNext = NULL;

//	delete Ptr1;
	mySize--;
	return temp;
}

/* sortList() method - Used to split a list into two subsequences and sort the list
 * @param: None
 * @return: *this
 * Precondition: List must be greater than 1
 * Postcondition: List will be sorted
 */
template<class Item>
void List<Item>::sortList() {
   if (mySize > 1){
      List<Item> s1, s2;
      divide(s1, s2);  // split s into s1 and s2
      s1.sortList();            // recursively sort s1
      s2.sortList();            // recursively sort s2
      *this = s1.merge(s2);   // merge the two sorted subsequences
   }                 //  so that s is sorted
}

/* divide() method - Divides the two subsequences
 * @param: List<Item> l1, List<Item> l2
 * Postcondition: List will be effectively sorted
 */
template<class Item>
void List<Item>::divide(List<Item>& l1, List<Item>& l2){
    unsigned j =mySize/2;
    unsigned k = mySize-mySize/2;
    Node * nPtr = myFirst;
    for (unsigned i = 0; i < j; i++){
        l1.append(nPtr -> myItem);
        nPtr=nPtr -> myNext;
    }
    for (unsigned i = j; i < mySize; i++){
        l2.append(nPtr -> myItem);
        nPtr = nPtr -> myNext;
    }
}

/* merge() method - merges the two subsequences of the list together
 * @param: List<Item> v2
 * @return: List<Item>
 */
template<class Item>
List<Item> List<Item>::merge(List<Item>& v2){
    unsigned r = mySize;
    unsigned q = v2.mySize;
    List<Item> v3;
    Node * nPtr1=myFirst;
    Node * nPtr2=v2.myFirst;
    //List<Item> v1 = *this;
    for(unsigned k=0; k<(r+q); k++){
        if(nPtr1==NULL){
            v3.append(nPtr2->myItem);
            nPtr2=nPtr2->myNext;
        } else if(nPtr2==NULL){
            v3.append(nPtr1->myItem);
            nPtr1=nPtr1->myNext;
        } else if(nPtr1->myItem<=nPtr2->myItem){
            v3.append(nPtr1->myItem);
            nPtr1=nPtr1->myNext;
        } else if(nPtr1->myItem>=nPtr2->myItem){
            v3.append(nPtr2->myItem);
            nPtr2=nPtr2->myNext;
        }
    }
    return v3;
}

//Judy wrote this method
/* readFrom(istream) method - fuction for streams
 * @param: an istream to read from
 * Precondition - if mySize is not 0 initialize to zero.
 * Postcondition - the string in the line is read into the list.
 */
template<class Item>
void List<Item>::readFrom(istream& in) {

	if (mySize != 0) { //if list is non-empty, delete content
		delete myFirst;
		myFirst = myLast = NULL;
		mySize = 0;
	}

	Item item = 0;
	while (true) {
		in >> item;
		this->append(item);
		char nextch = in.peek();
		if (nextch == '\n') {
			break;
		}
	}

}

//Judy wrote this method
/* prepend() method - prepends items to the front of the list and increments the size
 * @param: const Item& --> it
 * Precondition - if mySize is 0 myLast = myFirst
 *  				or else myFirst = item ->myFirst will be returned
 * Postcondition - myFirst will = item, myFirst and mySize will be incremented
 */
template <class Item>
void List<Item>::prepend(const Item& item) {
	myFirst = new Node(item, myFirst);
	if (mySize == 0) {
		myLast = myFirst;
	}
	mySize++;
}

//Judy wrote this method
/* writeTo(fileName) method - writes a list to a file
 * @param: const string& -> fileName
 * Postcondition: the list will be written to a file
 */
template <class Item>
void List<Item>::writeTo(const string& fileName) {
	ofstream fout(fileName.c_str()); // open file
	//assert(fout.is_open());
	Node* ptr = myFirst;
	while (ptr) { //while ptr doesn't reach end when myNext is null.
		fout << ptr->myItem << "\n" ; //print myItem
		ptr = ptr->myNext; //move on to next Item through pointer myNext
	}
	fout.close();
}

//Judy wrote this method
/* insert() function for lists.
 * @param: an item to insert, and the index at which it should be inserted.
 *
 * Postcondition: the item in the parameter is inserted at the index specified.
 * The Node Pointer of the term before is set to the address of the new node,
 * and the node pointer of the new node is set to the following node.
 * If the index is at the beginning or the end of the list, myFirst or myLast
 * is updated.
 */


//Judy wrote this method
template<class Item>
void List<Item>::insert(const Item& it, int index) {
	if (mySize == 0) {
		append(it);
	}

	else if (index <= 0) {
		prepend(it);
	}
	else if (index >= mySize) {
		append(it);
	}
	else {
		Node * nodePtr1 = new Node(it, NULL);
		Node * nodePtr2 = myFirst;

		for (int i = 0; i < index; i++) {
			if (i == index -1) {
				nodePtr1->myNext = nodePtr2->myNext;
				nodePtr2->myNext = nodePtr1;
			}
		}
		mySize++;
	}
}


#endif /* LIST_H_ */
