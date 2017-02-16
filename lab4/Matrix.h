/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name: Zach Wibbenmeyer
 * Date: October 6, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */


#ifndef MATRIX_H_
#define MATRIX_H_

//Include the necessary modules
#include "Vec.h"
#include <iostream>        // cout, cerr, ...
#include <cstdlib>         // exit()
#include <stdexcept>       // range_error, ...
#include <cassert>			//assert
#include <fstream>
using namespace std;

//Create a typedef of Item
typedef double Item;

//Create a class Matrix
class Matrix {
public:
	//Implement methods
	Matrix();
	unsigned getRows() const;
	unsigned getColumns() const;
	//unsigned getSize() const;
	Matrix(unsigned rows, unsigned columns);
	const Vec<Item>& operator[](unsigned index) const;
	Vec<Item>& operator[](unsigned index);
	bool operator==(const Matrix& m2) const;
private:
	unsigned myRows;
	unsigned myColumns;
	Vec< Vec<Item> > myVec;
	//Make a friend of MatrixTester
	friend class MatrixTester;
};


#endif
