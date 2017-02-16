/* Matrix.cpp defines Matrix class methods
 * Student Name: Zach Wibbenmeyer
 * Date: October 6, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

//Include the necessary modules
#include "Matrix.h"

/* Matrix() method, sets the default constructors
 * Postcondition: the vectors will now have default constructors
 */
Matrix::Matrix() {
	myRows = myColumns = 0;
}

/* getRows() method
 * @return: myRows
 */
unsigned Matrix::getRows() const {
	return myRows;
}

/* getColumns() method
 * @return: myColumns
 */
unsigned Matrix::getColumns() const {
	return myColumns;
}

/* CopyConstructor, sets the size of the columns in myVec
 * @param: unsigned --> rows, unsigned --> columns
 */
Matrix::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}

/* Subscript operator (read version), returns index of myVec, otherwise it throws an exception
 * @param: unsigned --> index
 * @return: index of myVec
 */
const Vec<Item>& Matrix::operator[](unsigned index) const {
	if (index < myVec.getSize()) {
		return myVec[index];
	}
	else {
		throw std::range_error("Your index is out of range");
	}
}

/* Subscript Operator (write version) - returns index of myVec, otherwise it throws an exception
 * @param: unsigned --> index
 * @return: index of myVec
 */
Vec<Item>& Matrix::operator[](unsigned index) {
	if (index < myVec.getSize()) {
		return myVec[index];
	}
	else {
		throw std::range_error("Your index is out of range");
	}
}

/* Equality Operator - returns false if myRows does not equal m2 rows,
 * 		or if myColumns does not equal m2 columns, otherwise returns myVec
 * 		equal to m2 Vec
 * @param: const Matrix& --> m2
 * @return: false, or myVec == m2.myVec
 */
bool Matrix::operator==(const Matrix& m2) const {
  if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
	   return false;
  } else {
	   return myVec == m2.myVec;
  }
}


