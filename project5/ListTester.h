/* ListTester.h declares the test-class for class List.
 * Student: Zach Wibbenmeyer
 * Date: October 19, 2015
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
	void testReadfromStream();
	void testPrepend();
	void testWriteToString();
	void testInsert();

};

#endif /*LISTTESTER_H_*/
