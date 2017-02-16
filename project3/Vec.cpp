/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Zach Wibbenmeyer
 * Date: October 5, 2015
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

//Zach wrote this method
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

//Write version
//Zach wrote this method
/* operator[] writes the value at the specified index from the Vector
 * @param: unsigned --> index
 * @return: myArray[index]
 */
Item& Vec::operator[](unsigned index) {
	if (index >= mySize) {
		throw range_error("Subscript[] index is too large");
	}
	return myArray[index];
}

//Read version
//Kemal wrote this method
/* operator[] reads the value at the specified index from the Vector.
 * @param: unsigned --> index
 * @return: myArray[index]
 */
const Item& Vec::operator[](unsigned index) const {
	if (index >= mySize) {
		throw range_error("Subscript[] index is too large");
	}
	return myArray[index];
}

//Zach wrote this method
/* writeTo() method to write the size and values of each array in the vector
 * 		class
 * @param: string --> fileName
 */
void Vec::writeTo(const string& fileName) const {
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
Vec Vec::operator+(const Vec& v2) const {
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

//Zach and Kemal wrote this method
/*operator* computes the dot product of two vectors if their sizes are equal
 * @param: const Vec& --> v2, and "this" vector
 * @return: a double "dProd"
 */
double Vec::operator*(const Vec& v2) const {
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

/*Written by Kemal
 * This inequality compares two vectors and returns a bool T/F.
 * It checks if they are empty arrays and if so, return false. Next, it compares the sizes, if they're not the same, it returns true.
 * If the sizes are the same it compares each element in the array and returns false if they're exactly the same. IF they're not the same it true.
 * @param: const Vec& v2
 * @return: boolean value
 *
 */
bool Vec::operator!=(const Vec& v2) {
	 return !(*this == v2);
}

/*
 * Written by Kemal
 * minus operator subtracts the value of elements at the same index in Vec v1 and Vec v2 and returns the new Vec v3
 * @param: const Vec& v2
 * @return : v3
 */
Vec Vec::operator-(const Vec& original) const {
	if (mySize != original.mySize) {
		throw invalid_argument("Vectors are not of the same size");
	}
	Vec v1(mySize);
	v1.myArray = new Item[mySize];
	for (unsigned i = 0; i < mySize; i++) {
		v1.myArray[i]=myArray[i]-original.myArray[i];
	}
	return v1;
}

/* written by Kemal
 * readFrom method fills v3 with values stored in fileName.
 * @param:  const string& fileName
 *
 */
void Vec::readFrom(const string& fileName) {
	ifstream fin(fileName.c_str());
	unsigned size;
	if (fin.is_open() ){
		fin >> size;
		this -> setSize(size);
		for (unsigned i = 0; i < mySize; i++){
			fin >> myArray[i];
		}
	}
	fin.close();
}
