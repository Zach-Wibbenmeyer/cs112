/* VecTester.h provides unit tests for Vec, a simple vector class.
 * Student Name: Zach Wibbenmeyer
 * Date: October 5, 2015
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VECTESTER_H_
#define VECTESTER_H_

//Include the necessary modules
#include "Vec.h"
using namespace std;

//Create a class for the VecTester sourcefile
class VecTester {
public:
	//Implement the tests
	void runTests() const;
	void testDefaultConstructor() const;
	void testExplicitConstructor() const;
	void testDestructor() const;
	void testGetSize() const;
	void testSetItem() const;
	void testGetItem() const;
	void testSetSize() const;
	void testCopyConstructor() const;
	void testAssignment() const;
	void testEquality() const;
	void testWriteToStream() const;
	void testReadFromStream() const;
	void testInequality() const;
	void testAddition() const;
	void testSubtraction() const;
	void testDotProduct() const;
	void testReadFromFile() const;
	void testWriteToFile() const;
	void testSubscriptOperator() const;
};

#endif /*VECTESTER_H_*/
