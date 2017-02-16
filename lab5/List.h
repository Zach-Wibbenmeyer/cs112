/*
 * List.h
 * Student Name: Zach Wibbenmeyer
 * Date: October 13, 2015
 * Begun By: Zach Wibbenmeyer, for CS 112 at Calvin College
 */

//Include the necessary modules
#include <iostream>
#include <stdexcept>
using namespace std;

#ifndef LIST_H_
#define LIST_H_

//Create a typedef of Item
typedef double Item;

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
private:
	//Implement methods for the Node
	struct Node {
		Item myItem;
		Node * myNext;
		Node();
		Node(Item it, Node * next);
		~Node();
	};
	unsigned mySize;
	Node * myFirst;
	Node * myLast;
	friend class ListTester;
};

#endif /* LIST_H_ */
