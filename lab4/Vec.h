/* Vec.h provides a simple vector class named Vec.
 * Student Name: Zach Wibbenmeyer
 * Date: October 6, 2015
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

//Include the necessary modules
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <fstream>
using namespace std;

template <class Item>

//Create a class for the Vec source file
class Vec {
public:
	//Implement all the methods
	Vec();
	virtual ~Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	Vec& operator=(const Vec& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	const Item& operator[](unsigned index) const;
	Item& operator[](unsigned index);
	bool operator!=(const Vec& v2);
	void writeTo(const string& fileName) const;
	Vec operator+(const Vec& v2) const;
	double operator*(const Vec& v2) const;
	Vec operator-(const Vec& v2) const;
	void readFrom(const string& fileName);
private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};

/* Vec() method, sets the default constructors
 * Postcondition: the vectors will now have default constructors
 */
template <class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = NULL;
}

/* Destructor() method - clears any memories of arrays
 * Postcondition: Memories of arrays will be cleared
 */
template <class Item>
Vec<Item>::~Vec() {
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}

/* ExplicitValue method - Tests for explicit values in vectors and arrays
 * @param: unsigned --> size
 * Precondition: Arrays must be assigned values in the tests
 * Postcondition: Arrays will be checked for explicit values
 */
template <class Item>
Vec<Item>::Vec(unsigned size) {
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
template <class Item>
Vec<Item>::Vec(const Vec& original) {
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
template <class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
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
template <class Item>
unsigned Vec<Item>::getSize() const {
	return mySize;
}

/* setItem() method - if index is less than mySize, sets the indexes of myArray
 * 		to it.  Otherwise, throws an exception.
 * 	@param: unsigned --> index, Item& --> it
 */
template <class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
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
template <class Item>
Item Vec<Item>::getItem(unsigned index) const {
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
template <class Item>
void Vec<Item>::setSize(unsigned newSize) {
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
template <class Item>
bool Vec<Item>::operator==(const Vec<Item>& v2) const {
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
template <class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for (unsigned x = 0; x < mySize; x++) {
		out << myArray[x] << "\n\t";
	}
}

/* readFrom() method - reads vector from an istream and lets the user enter values
 * @param: istream& --> in
 * Precondition: Stream must be opened
 * Postcondition: User can write values into the vector using the stream
 */
template <class Item>
void Vec<Item>::readFrom(istream& in) {
	for (unsigned x = 0; x < mySize; x++) {
		in >> myArray[x];
	}
}

//Write version
//Zach wrote this method
/* operator[] writes the value at the specified index from the Vector
 * @param: unsigned --> index
 * @return: myArray[index]
 */
template <class Item>
Item& Vec<Item>::operator[](unsigned index) {
	return myArray[index];
}

//Read version
//Tammie wrote this method
/* operator[] reads the value at the specified index from the Vector.
 * @param: unsigned --> index
 * @return: myArray[index]
 */
template <class Item>
const Item& Vec<Item>::operator[](unsigned index) const {
	return myArray[index];
}

//Zach wrote this method
/* writeTo() method to write the size and values of each array in the vector
 * 		class
 * @param: string --> fileName
 */
template <class Item>
void Vec<Item>::writeTo(const string& fileName) const {
	ofstream fout(fileName.c_str());
	fout << mySize << endl;
	this->writeTo(fout);
	fout.close();
}

//Zach wrote this method
/* operator+() adds the values in each array if they are the same size
 * @param: const Vec& --> v2 and "this" vector
 * @return: The added vectors if they are the same size, if not, throws
 * 		an invalid argument
 */
template <class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item>& v2) const {
	if (mySize != v2.mySize) {
		throw std::invalid_argument("Vectors are not of the same size");
	}
	else {
		Vec v3(mySize);
		v3.myArray = new Item(mySize);
		for (unsigned x = 0; x < mySize; x++) {
			v3[x] = (*this)[x] + v2[x];
		}
		return v3;
	}
}

//Zach and Tammie wrote this method
/*operator* computes the dot product of two vectors if their sizes are equal
 * @param: const Vec& --> v2, and "this" vector
 * @return: a double "dProd"
 */
template <class Item>
double Vec<Item>::operator*(const Vec<Item>& v2) const {
	if (mySize != v2.mySize) {
		throw std::invalid_argument("Vectors are not of the same size");
	}
	else {
		double dProd = 0;
		for (unsigned x = 0; x < mySize; x++) {
			dProd = dProd + (((*this)[x]) * v2[x]);
		}
		return dProd;
	}
}

/*Written by Tammie Thong
 * This inequality compares two vectors and returns a bool T/F.
 * It checks if they are empty arrays and if so, return false. Next, it compares the sizes, if they're not the same, it returns true.
 * If the sizes are the same it compares each element in the array and returns false if they're exactly the same. IF they're not the same it true.
 * @param: const Vec& v2
 * @return: boolean value
 *
 */
template <class Item>
bool Vec<Item>::operator!=(const Vec<Item>& v2) {
	if (this->mySize == 0 && v2.mySize == 0) {
		return false;
	}
	else if (this->mySize != v2.mySize) {
		return true;
	}
	else {
		for (unsigned i = 0; i < mySize; i++) {
			if (this->myArray[i] == v2.myArray[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

/*
 * Written by Tammie Thong
 * minus operator subtracts the value of elements at the same index in Vec v1 and Vec v2 and returns the new Vec v3
 * @param: const Vec& v2
 * @return : v3
 */
template <class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item>& v2) const {
	if (mySize != v2.mySize) {
		throw std::invalid_argument("Vectors are not of the same size");
	}
	else {
		Vec v3(mySize);
		v3.myArray = new Item[mySize];
		for (unsigned i = 0; i < mySize; i++) {
			v3.myArray[i]=myArray[i]-v2.myArray[i];
		}
		return v3;
	}
}

/* written by Tammie Thong
 * readFrom method fills v3 with values stored in fileName.
 * @param:  const string& fileName
 *
 */
template <class Item>
void Vec<Item>::readFrom(const string& fileName) {
	ifstream fin(fileName.c_str());
	fin >> mySize;
	myArray = new Item[mySize];
	this -> readFrom(fin);
	fin.close();
}

#endif /*VEC_H_*/
