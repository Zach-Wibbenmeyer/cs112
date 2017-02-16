/* StackTester.h declares a test-class for a dynamically allocated (array) Stack.
 * Joel Adams, for CS 112 at Calvin College
 * Student: Zach Wibbenmeyer
 * Date: July 23, 2015
 */

#ifndef STACKTESTER_H_
#define STACKTESTER_H_
using namespace std;

//Test the methods
class StackTester {
public:
	void runTests();
	void testConstructor();
	void testIsEmpty();
	void testPushAndIsFull();
	void testGetTop();
	void testPop();
	void testCopyConstructor();
	void testAssignment();
	void testDestructor();
	void testGetCapacity();
	void testGetSize();
	void testSetCapacity();
};

#endif /*STACKTESTER_H_*/
