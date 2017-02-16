/* ArrayQueue.h declares a Queue class using a dynamic array.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Student name:
 * Date:
 * 
 * Class Invariant: 
 *    mySize == 0 ||
 *    mySize > 0 && myArray[myFirst] == getFirst()
 *               && myArray[myLast-1] == getLast().
 * 
 *  (When I am not empty:
 *     myFirst is the index of my oldest value;
 *     myLast is the index of the spot where the next
 *       item to be appended will be placed.)      
 */

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include "QueueException.h"
#include <cstring>			//memcpy()

template <class Item>
class ArrayQueue {
public:

	ArrayQueue(const ArrayQueue<Item>& original);
	virtual ~ArrayQueue();
	ArrayQueue<Item>& operator=(const ArrayQueue<Item>& original);
	unsigned getSize() const;
	unsigned getCapacity() const;
	bool isEmpty() const;
	bool isFull() const;
	ArrayQueue(unsigned capacity);
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	Item remove();
	void setCapacity(unsigned newCapacity);
protected:
	virtual void makeCopyOf(const ArrayQueue<Item>& original);
private:
	unsigned mySize;       // number of items I contain
	unsigned myCapacity;   // how many items I can store
	unsigned myFirst;      // index of oldest item (if any)
	unsigned myLast;       // index of next available spot for append (if any)
	Item*    myArray;      // dynamic array of items

	friend class ArrayQueueTester;
};

template <class Item>
ArrayQueue<Item>::ArrayQueue(const ArrayQueue<Item>& original) {
	makeCopyOf(original);
}

template <class Item>
void ArrayQueue<Item>::makeCopyOf(const ArrayQueue<Item>& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirst = original.myFirst;
	myLast = original.myLast;
	myArray = new Item[myCapacity];
	memcpy(myArray, original.myArray, myCapacity*sizeof(Item) );
}

template <class Item>
ArrayQueue<Item>::~ArrayQueue() {
	delete [] myArray;
	myArray = NULL;
	mySize = myFirst = myLast = 0;
}


template <class Item>
ArrayQueue<Item>& ArrayQueue<Item>::operator=(const ArrayQueue<Item>& aQueue) {
	if (this != &aQueue) {
		delete [] myArray;
		makeCopyOf(aQueue);
	}
	return *this;
}

template <class Item>
bool ArrayQueue<Item>::isEmpty() const {
	return mySize == 0;
}

template <class Item>
bool ArrayQueue<Item>::isFull() const {
	return getSize() == myCapacity;
}

template <class Item>
unsigned ArrayQueue<Item>::getCapacity() const {
	return myCapacity;
}

template <class Item>
unsigned ArrayQueue<Item>::getSize() const {
	return mySize;
}

/* Arrayqueue() Constructor - if capacity is greater than 0, set the constructor, otherwise throw
 * 			a QueueException error
 * @param: unsigned capacity
 */
template <class Item>
ArrayQueue<Item>::ArrayQueue(unsigned capacity) {
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
template <class Item>
Item ArrayQueue<Item>::getFirst() const {
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
template <class Item>
Item ArrayQueue<Item>::getLast() const {
	if ( isEmpty() ) {
		throw EmptyQueueException("Queue is empty");
	} else {
		return myArray[(myLast - 1 + myCapacity) % myCapacity];
	}
}

/* append() method - appends an Item to the queue
 * @param: const Item& it
 * Precondition: Queue must not be full
 * Postcondition: and item will be appended to the queue
 */
template <class Item>
void ArrayQueue<Item>::append(const Item& it) {
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
template <class Item>
Item ArrayQueue<Item>::remove() {
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

/* setCapacity() method - sets the capacity of a queue
 * @param: unsigned newCapacity
 */
template <class Item>
void ArrayQueue<Item>::setCapacity(unsigned newCapacity) {
	if (newCapacity == 0 or newCapacity < getSize() ) {
		throw QueueException("setCapacity", "new Capacity is too small");
	} else {
		Item* newArray = new Item[newCapacity];
		for (unsigned x = 0; x < mySize; x++) {
			newArray[x] = myArray[myFirst];
			myFirst = (myFirst + 1) % myCapacity;
		}

		myFirst = 0;
		myLast = mySize;
		myCapacity = newCapacity;
		myArray = newArray;
	}
}


#endif /*ARRAY_QUEUE_H_*/
