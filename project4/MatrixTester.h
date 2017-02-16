/* MatrixTester.h declares test-methods for class Matrix.
 * Student Name: Zach Wibbenmeyer
 * Date: October 12, 2015
 * Begun By: Joel C. Adams, for CS 112 at Calvin College.
 */
 
#ifndef MATRIXTESTER_H_
#define MATRIXTESTER_H_

//Include the necessary modules
#include "Matrix.h"
using namespace std;

//Create a class MatrixTester
class MatrixTester {
public:
	//Implement the tests
	void runTests();
	void testDefaultConstructor();
	void testExplicitConstructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testInequality();
	void testSubscripts();
	void testReadSubscript(const Matrix& mat);
	void testTranspose();
	void testAddition();
	void testSubtraction();
	void testMultiply();
	void testReadFromStream();
	void testReadFromFile();
	void testWriteToStream();
	void testWriteToFile();
};

#endif /*MATRIXTESTER_H_*/
