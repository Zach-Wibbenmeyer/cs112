/* Matrix.cpp defines Matrix class methods
 * Student Name: Zach Wibbenmeyer
 * Date: October 12, 2015
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
		throw range_error("Your index is out of range");
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
		throw range_error("Your index is out of range");
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
  }
  else {
	   return myVec == m2.myVec;
  }
}

/* writeTo method - writes values of m to cout
 * @param: ostream& out
 * Postcondition: values will be written to cout
 */
void Matrix::writeTo(ostream& out) const {
	out << endl;
	for (unsigned x = 0; x < myRows; x++) {
		for (unsigned y = 0; y < myColumns; y++) {
			out << myVec[x][y] << "\t\t";
		}
		out << endl;
	}
}

/* readFrom File method - fills m with values of m stored in fileName
 * @param: const string& fileName
 * Postcondition: Values from fileName will be stored in m
 */
void Matrix::readFrom(const string& fileName) {
	ifstream fin(fileName.c_str());
	fin >> myRows >> myColumns;
	myVec.setSize(myRows);
	for (unsigned x = 0; x < myRows; x++) {
		myVec[x].setSize(myColumns);
		for (unsigned y = 0; y < myColumns; y++) {
			fin >> myVec[x][y];
		}
	}
	fin.close();
}

/* Subtraction method - should assert that matrices should be able to subtract
 * @param: const Matrix& m2
 * @return: a Matrix, m3
 * Precondition: Matrices must be able to subtract
 * Postcondition: Matrices will be subracted
 */
Matrix Matrix::operator-(const Matrix& m2) {
	if (myRows == m2.myRows and myColumns == m2.myColumns) {
		Matrix m3(myRows, myColumns);
		for (unsigned i = 0; i < myRows; i++) {
			m3[i] = myVec[i] - m2[i];
		}
		return m3;
	}
	else {
		throw invalid_argument("The matrices are not the same size");
	}
}

/* getTranspose method - returns a matrix whose columns are m's rows, and whose rows are m's columns
 * @param: None
 * @return: a Matrix, m3
 * @Postcondition: Matrix will be transposed
 */
Matrix Matrix::getTranspose() {
	Matrix m3(myColumns, myRows);
	for (unsigned x = 0; x < myRows; x++) {
		for (unsigned y = 0; y < myColumns; y++) {
		m3.myVec[y][x] = myVec[x][y];
		}
	}
	return m3;
}

//Jesse wrote this method
void Matrix::readFrom(istream& in) {
	for(unsigned i = 0; i < myRows; i++) {
		for(unsigned j = 0; j < myColumns; j++) {
			in >> myVec[i][j];
		}
	}
}

//Jesse wrote this method
void Matrix::writeTo(string fileName) {
	ofstream fout (fileName.c_str());
	fout << myRows << ' ' << myColumns << '\n';
	for(unsigned i = 0; i < myRows; i++) {
		for(unsigned j = 0; j < myColumns; j++) {
			fout << myVec[i][j] << ' ';
		}
		fout << '\n';
	}
}

//Jesse wrote this method
bool Matrix::operator!=(const Matrix& m) const {
	if ( myRows != m.getRows() || myColumns != m.getColumns() ) {
		return true;
	} else {
		return !(myVec == m.myVec);
	}
}

//Jesse wrote this method
Matrix Matrix::operator+(const Matrix& m) {
	Matrix temp(myRows, myColumns);
	if (myRows != m.getRows() || myColumns != m.getColumns()) {
		throw invalid_argument("rhs and lhs are not matrices of the same size");
	} else {
		for(unsigned i = 0; i < myRows; i++) {
			for(unsigned j = 0; j < myColumns; j++) {
				temp.myVec[i][j] = m.myVec[i][j] + myVec[i][j];
			}
		}
	}
	return temp;
}
