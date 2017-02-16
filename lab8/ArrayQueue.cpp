/* ArrayQueue.cpp defines the methods for class ArrayQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name:
 * Date:
 */

#include "ArrayQueue.h"
#include <cstring>      // memcpy()
using namespace std;


ArrayQueue::ArrayQueue(const ArrayQueue& original) {
	makeCopyOf(original);
}

void ArrayQueue::makeCopyOf(const ArrayQueue& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirst = original.myFirst;
	myLast = original.myLast;
	myArray = new Item[myCapacity];
	memcpy(myArray, original.myArray, myCapacity*sizeof(Item) );
}

ArrayQueue::~ArrayQueue() {
	delete [] myArray;
	myArray = NULL;
	mySize = myFirst = myLast = 0;
}


ArrayQueue& ArrayQueue::operator=(const ArrayQueue& aQueue) {
	if (this != &aQueue) {
		delete [] myArray;
		makeCopyOf(aQueue);
	}
	return *this;
}

bool ArrayQueue::isEmpty() const {
	return mySize == 0;
}

bool ArrayQueue::isFull() const {
	return getSize() == myCapacity;
}

unsigned ArrayQueue::getCapacity() const {
	return myCapacity;
}

unsigned ArrayQueue::getSize() const {
	return mySize;
}

/* Arrayqueue() Constructor - if capacity is greater than 0, set the constructor, otherwise throw
 * 			a QueueException error
 * @param: unsigned capacity
 */
ArrayQueue::ArrayQueue(unsigned capacity) {
	if (capacity > 0) {
		myCapacity = capacity;
		mySize = 0;
		myFirst = 0;
		myLast = 0;
		myArray = new Item[capacity];
	}
	else {
		throw QueueException("capacity: ", "Capacity is negative");
	}
}

/* getFirst() method - returns the first item in the queue
 * @param: None
 * @return: myArray[myFirst]
 */
Item ArrayQueue::getFirst() const {
	if (mySize == 0) {
		throw EmptyQueueException("Queue is empty");
	}
	else {
		return myArray[myFirst];
	}
}

/* getLast() method - returns the last item in the queue
 * @param: None
 * @return: myArray[(myLast - 1 + myCapacity) % myCapacity]
 */
Item ArrayQueue::getLast() const {
	if (mySize == 0) {
		throw EmptyQueueException("Queue is empty");
	}
	else {
		return myArray[(myLast - 1 + myCapacity) % myCapacity];
	}
}

/* append() method - appends an Item to the queue
 * @param: const Item& it
 * Precondition: Queue must not be full
 * Postcondition: and item will be appended to the queue
 */
void ArrayQueue::append(const Item& it) {
	if ( isFull() ) {
		throw FullQueueException("Queue is full");
	}
	else {
		myArray[myLast] = it;
		myLast = (myLast + 1) % myCapacity;
		mySize++;
	}
}

/* remove() method - removes an item from the queue
 * @param: None
 * @return: result, an unsigned variable
 * Precondition: queue must not be empty
 * Postcondition: Item will be removed from queue
 */
Item ArrayQueue::remove() {
	if ( isEmpty() ) {
		throw EmptyQueueException("Queue is empty");
	}
	else {
		Item result;
		result = myArray[myFirst];
		myFirst = (myFirst + 1) % myCapacity;
		mySize--;
		return result;
	}
}

