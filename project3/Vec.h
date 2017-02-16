/* Vec.h provides a simple vector class named Vec.
 * Student Name: Zach Wibbenmeyer
 * Date: October 5, 2015
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

typedef double Item;

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
	bool operator==(const Vec& v2);
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	const Item& operator[](unsigned index) const;
	Item& operator[](unsigned index);
	bool operator!=(const Vec& v2);
	void writeTo(const string& fileName) const;
	Vec operator+(const Vec& v2) const;
	double operator*(const Vec& v2) const;
	Vec operator-(const Vec& original) const;
	void readFrom(const string& fileName);
private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};

#endif /*VEC_H_*/
