/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Zach Wibbenmeyer
 * Date:
 */
 
#include "BST.h"


BST::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

BST::BST() {
	myRoot = NULL;
	myNumItems = 0;
}

BST::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}

BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

bool BST::isEmpty() const {
	return myNumItems == 0;
}

unsigned BST::getNumItems() const {
	return myNumItems;
}

void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

void BST::Node::processItem() {
		cout << ' ' << myItem;
}

void BST::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

void BST::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

void BST::Node::traverseInorder() {
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}

void BST::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}

void BST::insert(const Item& it) {
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

void BST::Node::insert(const Item& it){
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

bool BST::contains (const Item& it) const {
	if ( isEmpty() ){
		return false;
	}
	return myRoot->contains(it);
}

bool BST::Node::contains(const Item& it) const {
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



