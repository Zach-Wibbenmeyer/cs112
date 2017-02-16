/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Zach Wibbenmeyer
 * Date: Sept 29, 2015
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

//Include the necessary modules
#include "Vec.h"
using namespace std;

/* Vec() method, sets the default constructors
 * Postcondition: the vectors will now have default constructors
 */
Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}

/* Destructor() method - clears any memories of arrays
 * Postcondition: Memories of arrays will be cleared
 */
Vec::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}

/* ExplicitValue method - Tests for explicit values in vectors and arrays
 * @param: unsigned --> size
 * Precondition: Arrays must be assigned values in the tests
 * Postcondition: Arrays will be checked for explicit values
 */
Vec::Vec(unsigned size) {
	mySize = size;
	myArray = new Item[mySize];
	for (unsigned x = 0; x < size; x++) {
		myArray[x] = 0;
	}
}

/* CopyConstructor method - copies the values of original into myArray
 * @param: Vec& --> original
 * Postcondition: values from original will be copied into newArray and
 * 		myArray will be set to NULL
 */
Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if (original.mySize > 0) {
		myArray = new Item[mySize];
		for (unsigned x = 0; x < original.mySize; x++) {
			myArray[x] = original.myArray[x];
		}
	}
	else {
		myArray = NULL;
	}

}

/* AssignmentOperator - Makes v2 a copy of v1, overwriting any previous values
 * 		v2 held.  Where the copy constructor returns nothing, the assignment
 * 		operator will return the object to the left of the -sign.
 * 		Deallocates myArray
 * 	@param: Vec& --> original
 */
Vec& Vec::operator=(const Vec& original) {
	if (this != &original) {
		if (mySize != original.mySize) {
			if (mySize > 0) {
				delete [] myArray;
				myArray = NULL;
			}
			if (original.mySize > 0) {
				myArray = new Item[original.mySize];
			}
			mySize = original.mySize;
		}
		for (unsigned x = 0; x < original.mySize; x++) {
			myArray[x] = original.myArray[x];
		}
	}
	return *this;
}

// getSize() method - returns the value of mySize
unsigned Vec::getSize() const {
	return mySize;
}

/* setItem() method - if index is less than mySize, sets the indexes of myArray
 * 		to it.  Otherwise, throws an exception.
 * 	@param: unsigned --> index, Item& --> it
 */
void Vec::setItem(unsigned index, const Item& it) {
	if (index < mySize) {
		myArray[index] = it;
	}
	else {
		throw std::range_error("Your index is out of range!");
	}
}

/* getItem() method - if index is less than mySize, returns the indexes of
 * 		myArray.  Otherwise, throws an exception.
 * @param: unsigned --> index
 */
Item Vec::getItem(unsigned index) const {
	if (index < mySize) {
		return myArray[index];
	}
	else {
		throw std::range_error("Your index is out of range!");
	}
}

/* setSize() method - sets the Vectors size.  Changes the size of the existing
 * 		vector to a new size.
 * @param: unsigned --> newSize
 */
void Vec::setSize(unsigned newSize) {
	if (mySize != newSize) {
		if (newSize == 0) {
			delete [] myArray;
			myArray = NULL;
			mySize = 0;
		}
		else {
			Item * newArray;
			newArray = new Item[newSize];
			if (mySize < newSize) {
				for (unsigned x = 0; x < mySize; x++) {
					newArray[x] = myArray[x];
				}
				for (unsigned x = mySize; x < newSize; x++) {
					newArray[x] = 0;
				}

			}
			else {
				for (unsigned x = 0; x < newSize; x++) {
					newArray[x] = myArray[x];
				}
			}
			mySize = newSize;
			delete [] myArray;
			myArray = newArray;
		}
	}
}

/* Equality operator - Compares two objects and returns true if they are equal,
 * 		false if they are not.
 * @param: Vec& --> v2
 */
bool Vec::operator==(const Vec& v2) {
	if (mySize != v2.mySize) {
		return false;
	}
	for (unsigned x = 0; x < mySize; x++) {
		if (myArray[x] != v2.myArray[x]) {
			return false;
		}
	}
	if (mySize == v2.mySize) {
		return true;
	}
}

/* writeTo() method - Writes a vector to an ostream and displays it on the screen
 * @param: ostream& --> out
 * Precondition: Ostream must be opened
 * PostCondition: Vectors will be displayed on the screen
 */
void Vec::writeTo(ostream& out) const {
	for (unsigned x = 0; x < mySize; x++) {
		out << myArray[x] << "\n\t";
	}
}

/* readFrom() method - reads vector from an istream and lets the user enter values
 * @param: istream& --> in
 * Precondition: Stream must be opened
 * Postcondition: User can write values into the vector using the stream
 */
void Vec::readFrom(istream& in) {
	for (unsigned x = 0; x < mySize; x++) {
		in >> myArray[x];
	}
}
