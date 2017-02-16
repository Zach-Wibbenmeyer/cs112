/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name:
 * Date:
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == NULL ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
using namespace std;


//Create a template
template <class Item>
// class BST
class BST {
public:

	virtual ~BST();
	BST();
	bool isEmpty() const;
	unsigned getNumItems() const;

	void insert(const Item& it);
	bool contains(const Item& it) const;
	void traverseInorder();
	void traversePreorder();
	void traversePostorder();
	unsigned getHeight() const;

private:
	// Node structure
	struct Node {
	    Node(const Item& it);
            virtual ~Node();

            void insert(const Item& it);
            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();
            bool contains(const Item& it) const;
            unsigned getHeight() const;
		
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};

template <class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}


// Default constructor
template <class Item>
BST<Item>::BST() {
	myRoot = NULL;
	myNumItems = 0;
}

template <class Item>
BST<Item>::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}

template <class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}

template <class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}

template <class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}

template <class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

template <class Item>
void BST<Item>::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

template <class Item>
void BST<Item>::Node::processItem() {
		cout << ' ' << myItem;
}

template <class Item>
void BST<Item>::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

template <class Item>
void BST<Item>::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

template <class Item>
void BST<Item>::Node::traverseInorder() {
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}

template <class Item>
void BST<Item>::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}

/* insert() method - inserts a Node into the BST
 * @param: const Item& it
 * @return: Nothing
 * Precondition: BST must not be empty
 * Postcondition: a node will be inserted into the BST
 */
template <class Item>
void BST<Item>::insert(const Item& it) {
	if ( isEmpty() ) {
		myRoot = new Node(it);
	} else {
		try {
		myRoot->insert(it);
		} catch (Exception& e) {
			throw Exception ("insert(Item)", "item is already in set");
		}
	}
		myNumItems++;
}

template <class Item>
void BST<Item>::Node::insert(const Item& it){
	if ( it < myItem) {
		if (myLeft == NULL) {
			myLeft = new Node(it);
		} else {
			myLeft->insert(it);
		}
	} else if ( it > myItem) {
		if (myRight == NULL) {
			myRight = new Node(it);
		} else {
			myRight->insert(it);
		}
	} else {
		throw Exception("Node::insert(item)","item is already in set");
	}
}

/* contains() method - checks if the BST contains something
 * @param: const Item& it
 * @return: myRoot->contains(it)
 * Postcondition: BST must not be empty
 */
template <class Item>
bool BST<Item>::contains (const Item& it) const {
	if ( isEmpty() ){
		return false;
	}
	return myRoot->contains(it);
}

template <class Item>
bool BST<Item>::Node::contains(const Item& it) const {
	if (myItem == it) {
		return true;
	} else if (myItem > it) {
		if( !myLeft ) {
			return false;
		} else {
			return(myLeft->contains(it));
		}
	} else {
		if( !myRight ) {
			return false;
		} else {
			return(myRight->contains(it));
		}
	}
}

/* getHeight() method - returns the height of the BST
 * @param: None
 * @return: Height of BST
 * Precondition: BST must not be empty
 * Postcondition: the height will be returned
 */
template <class Item>
unsigned BST<Item>::getHeight() const {
	if ( isEmpty() ) {
		return 0;
	} else {
		return myRoot->getHeight();
	}
}


template <class Item>
unsigned BST<Item>::Node::getHeight() const {
	if (!myLeft and !myRight) {
		return 1;
	} else if (myLeft and !myRight) {
		return myLeft->getHeight() + 1;
	} else if (!myLeft and myRight) {
		return myRight->getHeight() + 1;
	} else {
		unsigned hLeft = myLeft->getHeight();
		unsigned hRight = myRight->getHeight();
		if (hLeft > hRight) {
			return hLeft + 1;
		} else {
			return hRight + 1;
		}
	}
}

#endif /*BST_H_*/

