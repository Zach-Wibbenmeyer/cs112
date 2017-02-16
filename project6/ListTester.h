/* ListTester.h declares the test-class for class List.
 * Joel Adams, for CS 112 at Calvin College.
 */

using namespace std;

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

//Create a class ListTester
class ListTester {
public:
	//Implement all the tests
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testInequality();
	void testWriteToStream();
	void testReadFromFile();
	void testGetIndexOf();
	void testRemove();
	void testInsert();
	void testPrepend();
	void testReadfromStream();
	void testWriteToString();
	void testSort();
};

#endif /*LISTTESTER_H_*/
