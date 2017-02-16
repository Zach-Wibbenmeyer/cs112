/* LinkedQueue.cpp defines the methods for class LinkedQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name:
 * Date:
 */

#include "LinkedQueue.h"


LinkedQueue::LinkedQueue(const LinkedQueue& original) {
	makeCopyOf(original);
}

void LinkedQueue::makeCopyOf(const LinkedQueue& original) {
	mySize = original.mySize;
	if ( mySize == 0 ) {
		myFirst = myLast = NULL;
	} else {
		myFirst = new Node(original.getFirst(), NULL);
		Node * temp0 = original.myFirst->myNext;
		Node * temp1 = myFirst;
		while (temp0 != NULL) {
			temp1->myNext = new Node(temp0->myItem, NULL);
			temp1 = temp1->myNext;
			temp0 = temp0->myNext;
		}
		myLast = temp1;
	}
}

LinkedQueue::~LinkedQueue() {
	delete myFirst;
	myFirst = myLast = NULL;
	mySize = 0;
}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& aQueue) {
	if (this != &aQueue) {
		delete myFirst;    // invokes recursive ~Node()
		makeCopyOf(aQueue);
	}
	return *this;
}

/* LinkedQueue() Constructor
 * @param: None
 * @return: Nothing
 */
LinkedQueue::LinkedQueue() {
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}

/* getFirst() method - gets the first item of the queue
 * @param: None
 * @return: myFirst->myItem
 * Precondition: Queue must not be empty
 * Postcondition: The first item will be returned
 */
Item LinkedQueue::getFirst() const {
	if ( isEmpty() ) {
		throw EmptyQueueException("Queue is empty");
	}
	else {
		return myFirst -> myItem;
	}
}

/* getLast() method - returns the last item of the queue
 * @param: None
 * @return: myLast->myItem
 * Precondition: Queue must not be empty
 * Postcondition: the last item of the queue will be returned
 */
Item LinkedQueue::getLast() const {
	if ( isEmpty() ) {
		throw EmptyQueueException("Queue is empty");
	}
	else {
		return myLast -> myItem;
	}
}

/* append() method - appends an item to the queue
 * @param: const Item& it
 * @return: Nothing
 */
void LinkedQueue::append(const Item& it) {
	try {
		Node* nPtr = new Node(it, NULL);
		if ( isEmpty() ) {
			myFirst = nPtr;
		} else {
			myLast -> myNext = nPtr;
		}
		myLast = nPtr;
		mySize++;
	} catch (bad_alloc& ba) {
		throw FullQueueException("Queue is full");
	}
}

/* remove() method - removes an item from the queue
 * @param: None
 * @return: result, an Item
 * Precondition: The queue must not be empty
 * Postcondition: An item will be removed from the queue
 */
Item LinkedQueue::remove() {
	if ( isEmpty() ) {
		throw EmptyQueueException("Queue is empty");
	} else {
		Item result;
		result = myFirst -> myItem;
		Node* nPtr = myFirst;
		myFirst = myFirst -> myNext;
		nPtr -> myNext = NULL;
		delete nPtr;
		mySize--;
		return result;
	}
}


