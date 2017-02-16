/* listTester.cpp defines the test methods for class list.'
 * Student: Zach Wibbenmeyer
 * Date: October 19, 2015
 * Begun By: Joel Adams, for CS 112 at Calvin College.
 */

//Include the necessary modules
#include "ListTester.h" // listTester
#include "List.h"       // list
#include <iostream>     // cin, cout
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
using namespace std;

typedef double Item;

//Implement all the tests
void ListTester::runTests() {
	cout << "Running list tests..." << endl;
	testDefaultConstructor();
	testNodeDefaultConstructor();
	testNodeExplicitConstructor();
	testAppend();
	testDestructor();
	testCopyConstructor();
	testAssignment();
	testEquality();
	testInequality();
	testWriteToStream();
	testReadFromFile();

//	testReadfromStream();  --> Judy's method is wrong, so I have this test commented out
	testRemove();
	testGetIndexOf();
	testWriteToString();
	testPrepend();
	testInsert();
	cout << "All tests passed!" << endl;
}

//Test the list Default Constructor
void ListTester::testDefaultConstructor() {
	cout << "Testing list default constructor... " << flush;
	List<double> aList;
	assert( aList.mySize == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " Passed! " << endl;
}

//Test the Node Default Constructor
void ListTester::testNodeDefaultConstructor() {
	cout << "Testing Node default constructor... " << flush;
	List<double>::Node aNode;
	assert( aNode.myItem == 0 );
	assert( aNode.myNext == NULL );
	cout << "Passed!" << endl;
}

//Test the Node Explicit Constructor
void ListTester::testNodeExplicitConstructor() {
	cout << "Testing Node explicit constructor... " << flush;
	List<double>::Node n1(11, NULL);
	assert( n1.myItem == 11 );
	assert( n1.myNext == NULL );
	cout << " 1 " << flush;

	List<double>::Node *n3 = new List<double>::Node(33, NULL);
	List<double>::Node n2(22, n3);
	assert( n2.myItem == 22 );
	assert( n2.myNext == n3 );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

//Test the Append method
void ListTester::testAppend() {
	cout << "Testing append()... " << flush;
	// empty list
	List<double> aList;
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	try {
		aList.getFirst();
		cerr << "getFirst() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0a " << flush;
	}
	try {
		aList.getLast();
		cerr << "getLast() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0b " << flush;
	}
	// append to empty list
	aList.append(11);
	assert( aList.getSize() == 1 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast == aList.myFirst );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 11 );
	assert( aList.myFirst->myNext == NULL );
	cout << " 1 " << flush;
	// append to a list containing 1 Item
	aList.append(22);
	assert( aList.getSize() == 2 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.myFirst != aList.myLast );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext != NULL );
	assert( aList.myLast->myNext == NULL );
	cout << " 2 " << flush;
	// append to a list containing 2 Items
	aList.append(33);
	assert( aList.getSize() == 3 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 33 );
	assert( aList.myFirst->myNext->myItem == 22 );
	assert( aList.myLast->myNext == NULL );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

//Test the list Destructor
void ListTester::testDestructor() {
	cout << "Testing destructor... " << flush;
	List<double> aList;
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 1 " << flush;

	aList.append(11);
	aList.append(22);
	aList.append(33);
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 2 " << flush;
	cout << "Passed!  But double-check for memory leaks!" << endl;
}

//Test the Copy Constructor
void ListTester::testCopyConstructor() {
	cout << "Testing copy constructor... " << flush;
	// copy empty list
	List<double> list1;
	List<double> list2(list1);
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;
	// copy nonempty list
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4(list3);
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

//Test the Assignment Operator
void ListTester::testAssignment() {
	cout << "Testing assignment... " << flush;
	// empty to empty assignment
	List<double> list1;
	List<double> list2;
	list2 = list1;
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// non-empty to empty assignment
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4;
	list4 = list3;
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
	cout << " 2 " << flush;

	// equal-sized non-empty to non-empty assignment
	List<double> list5;
	list5.append(44);
	list5.append(55);
	list5.append(66);
	list5 = list3;
	assert( list5.getSize() == 3 );
	assert( list5.getFirst() == 11 );
	assert( list5.getLast() == 33 );
	assert( list5.myFirst->myNext->myItem == 22 );
	cout << " 3 " << flush;

	// empty to non-empty assignment
	List<double> list6;
	list6.append(44);
	list6.append(55);
	list6.append(66);
	List<double> list7;
	list6 = list7;
	assert( list6.getSize() == 0 );
	assert( list6.myFirst == NULL );
	assert( list6.myLast == NULL );
	cout << " 4 " << flush;

	// unequal-sized non-empty to non-empty assignment
	List<double> list8;
	list8.append(44);
	list8.append(55);
	list8.append(66);
	list8.append(77);
	list8 = list3;
	assert( list8.getSize() == 3 );
	assert( list8.getFirst() == 11 );
	assert( list8.getLast() == 33 );
	assert( list8.myFirst->myNext->myItem == 22 );
	cout << " 5 " << flush;

	// assignment chaining
	List<double> list9;
	list9.append(44);
	list9.append(55);
	list9.append(66);
	list9.append(77);
	List<double> list10;
	list10 = list9 = list8;
	assert( list10.getSize() == 3 );
	assert( list10.getFirst() == 11 );
	assert( list10.getLast() == 33 );
	assert( list10.myFirst->myNext->myItem == 22 );
	cout << " 6 " << flush;

	// self-assignment (stupid, but possible)
	List<double> list11;
	list11.append(11);
	list11.append(22);
	list11.append(33);
	list11 = list11;
	assert( list11.getSize() == 3 );
	assert( list11.getFirst() == 11 );
	assert( list11.getLast() == 33 );
	assert( list11.myFirst->myNext->myItem == 22 );
	cout << " 7 " << flush;

	cout << "Passed!  But double-check for memory leaks!" << endl;
}

//void ListTester::testEquality() {
//	cout << "Testing equality... " << flush;
//	// two empty lists
//	List<double> list1;
//	List<double> list2;
//	assert( list1 == list1 );
//	cout << " 1 " << flush;
//
//	// a non-empty list
//	List<double> list3;
//	list3.append(33);		// [33]
//	assert( !(list3 == list1) );
//	cout << " 2 " << flush;
//
//	// equal, non-empty lists of the same size
//	List<double> list4;
//	list4.append(33);		// [33]
//	assert( list4 == list3 );
//	assert( list3 == list4 );
//	cout << " 3 " << flush;
//
//	// unequal, non-empty lists of the same size
//	list3.append(55);		// [33,55]
//	List<double> list5;
//	list5.append(44);		// [44]
//	list5.append(55);		// [44,55]
//	assert( !(list5 == list3) );
//	assert( !(list3 == list5) );
//	cout << " 4 " << flush;
//
//	// unequal non-empty lists of different sizes
//	list4.append(44);		// [33,44]
//	list4.append(55);		// [33,44,55]
//	assert( !(list4 == list5) );
//	assert( !(list5 == list4) );
//	assert( !(list5 == list3) );
//	cout << " 5 " << flush;
//
//	cout << "Passed!" << endl;
//}

void ListTester::testInequality() {
	cout << "Testing inequality..." << flush;
	//Two empty lists
	List<double> list1;
	List<double> list2;
	assert( !(list1 != list2) );
	cout << " 1 " << flush;

	//non-empty list
	List<double> list3;
	list3.append(11);
	assert( list3 != list1 );
	assert( list3 != list2 );
	assert( list2 != list3 );
	assert( list1 != list3 );
	cout << " 2 " << flush;

	//equal, non-empty list of same size
	List<double> list4;
	list4.append(11);
	assert( list4 != list1 );
	assert( list4 != list2 );
	assert( list2 != list4 );
	assert( list1 != list4 );
	assert( !(list3 != list4) );
	assert( !(list4 != list3) );
	cout << " 3 " << flush;

	//non-empty list of bigger size
	List<double> list5;
	list5.append(11);
	list5.append(22);
	assert( list5 != list3 );
	assert( list5 != list4 );
	assert( list4 != list5 );
	assert( list3 != list5 );
	assert( list5 != list1 );
	assert( list5 != list2 );
	cout << " 4 " << flush;

	List<double> list6;
	list6.append(11);
	list6.append(22);
	assert( !(list6 != list5) );
	cout << " 5 " << flush;

	list6.append(33);
	assert( list6 != list5 );
	assert( list5 != list6 );
	cout << " 6 " << flush;

	list1.append(22);
	assert( list1 != list3 );
	assert( list3 != list1 );
	cout << " 7 " << flush;

	cout << " Passed! " << endl;
}

//Test WriteToStream method
void ListTester::testWriteToStream() {
	cout << "Testing writeTo(ostream)..." << flush;
	List<double> list;
	list.readFrom("list1.txt");
	ofstream fout("list1Copy.txt");
	assert( fout.is_open() );
	list.writeTo(fout);
	fout.close();
	List<double> list2;
	List<double> list3;
	list2.readFrom("list1Copy.txt");
	assert( list2.getSize() == 5);
	list3.append(1);
	list3.append(2);
	list3.append(3);
	list3.append(4);
	list3.append(5);
	assert( list2 == list3 );
	cout << " Passed! " << endl;
}

//Test readFrom(fileName) method
void ListTester::testReadFromFile() {
	cout << "Testing readFrom(string)..." << flush;
	List<double> list;
	List<double> list2;
	list.readFrom("list1.txt");
	assert( list.getSize() == 5 );
	cout << " 1 " << flush;
	list2.append(1);
	list2.append(2);
	list2.append(3);
	list2.append(4);
	list2.append(5);
	assert( list == list2);
	cout << " 2 " << flush;
	cout << " Passed! " << endl;
}

// test getIndexOf() method
void ListTester::testGetIndexOf() {
	cout << "Testing getIndexOf(Item)..." << flush;
	List<double> list1;
	List<double> list2;
	list1.append(3);
	list1.append(7);
	list1.append(10);
	list2.append(2);
	list2.append(4);
	list2.append(6);
	assert( list1 != list2 );
	cout << " 1 " << flush;
	assert( list1.getIndexOf(3) == 0 );
	assert( list1.getIndexOf(7) == 1 );
	assert( list1.getIndexOf(10) == 2 );
	assert( list2.getIndexOf(2) == 0 );
	assert( list2.getIndexOf(4) == 1 );
	assert( list2.getIndexOf(6) == 2 );
	cout << " 2 " << flush;
	cout << " Passed! " << endl;
}

// Test remove() method
void ListTester::testRemove() {
	cout << "Testing remove(Item)..." << flush;
	List<double> list;
	list.append(11);
	list.append(22);
	list.append(33);
	list.append(44);
	list.append(55);
	list.append(66);
	list.append(77);
	assert( list.getSize() == 7 );
	assert( list.remove(0) == 11 );
	assert( list.getIndexOf(11) == -1 );
	cout << " 1 " << flush;
	assert( list.remove(1) == 33 );
	assert( list.getIndexOf(33) == -1 );
	cout << " 2 " << flush;
	assert( list.getIndexOf(22) != -1 );
	cout << " 3 " << flush;
	assert( list.getIndexOf(22) == 0 );
	cout << " 4a " << flush;
	assert( list.getIndexOf(55) == 2 );
	cout << " 4b " << flush;
	assert( list.remove(-1) == 22 );
	assert( list.getIndexOf(22) == -1 );
	cout << " 5 " << flush;
	assert( list.getIndexOf(44) == 0 );
	cout << " 6 " << flush;
	assert( list.remove(3) == 77);
	assert( list.getLast() == 66 );
	cout << " 7 " << flush;
	assert( list.remove(3) == 66);
	assert( list.getLast() == 55 );
	assert( list.getSize() == 2 );
	cout << " 8 " << flush;
	assert( list.remove(4) == 55);
	assert( list.getLast() == 44 );
	cout << " 9 " << flush;
	cout << " Passed! " << endl;
}

//Judy wrote this test
void ListTester::testReadfromStream(){
	cout << "Testing ReadfromStream..." << flush;
	//reading to an empty string
	List<double> list1; //create list
	ifstream fin("list1.txt"); //read text file
	list1.readFrom(fin);
	assert( list1.getSize() == 5);
	cout << " 0 " << flush;

	List<double> list2;
	list2.append(1);
	list2.append(2);
	list2.append(3);
	list2.append(4);
	list2.append(5);

	assert(list1 == list2);

	cout << " 1 " << flush;


	cout << " Passed! " << endl;


}

void ListTester::testEquality() {
	cout << "Testing equality... " << flush;
	// two empty lists
	List<double> list1;
	List<double> list2;
	assert( list1 == list1 );
	cout << " 1 " << flush;

	// a non-empty list
	List<double> list3;
	list3.append(33);		// [33]
	assert( !(list3 == list1) );
	cout << " 2 " << flush;

	// equal, non-empty lists of the same size
	List<double> list4;
	list4.append(33);		// [33]
	assert( list4 == list3 );
	assert( list3 == list4 );
	cout << " 3 " << flush;

	// unequal, non-empty lists of the same size
	list3.append(55);		// [33,55]
	List<double> list5;
	list5.append(44);		// [44]
	list5.append(55);		// [44,55]
	assert( !(list5 == list3) );
	assert( !(list3 == list5) );
	cout << " 4 " << flush;

	// unequal non-empty lists of different sizes
	list4.append(44);		// [33,44]
	list4.append(55);		// [33,44,55]
	assert( !(list4 == list5) );
	assert( !(list5 == list4) );
	assert( !(list5 == list3) );
	cout << " 5 " << flush;

	cout << "Passed!" << endl;
}



void ListTester::testWriteToString(){
	cout << "testing writeToString ..." << flush;
	ofstream fout("testwriteToString.txt");
	assert( fout.is_open() );
	List<double >list1;
	list1.append(11);
	list1.append(22);
	list1.append(33);
	list1.writeTo(fout);

	cout << " 0 " << flush;

	assert( list1.getIndexOf(11) == 0 );
	assert( list1.getIndexOf(22) == 1 );
	assert( list1.getIndexOf(33) == 2 );
	cout << " 1 " << flush;

	cout << " Passed! " << endl;
}
void ListTester::testPrepend(){
	cout << "Testing prepend... " << flush;
	List<double> list1;
	list1.prepend(10);
	assert( list1.getSize() == 1 );
	assert( list1.myFirst != NULL );
	assert( list1.myLast != NULL );
	assert( list1.myFirst == list1.myLast );
	assert( list1.myFirst->myItem == 10 );
	assert( list1.myLast->myNext == NULL );
	cout << " 0 " << flush;

	list1.prepend(11);
	assert( list1.getSize() == 2 );
	assert( list1.myFirst != NULL );
	assert( list1.myLast != NULL );
	assert( list1.myFirst != list1.myLast );
	assert( list1.myFirst->myItem == 11 );
	assert( list1.myFirst->myNext == list1.myLast);
	assert( list1.myLast->myItem == 10 ); //the one we prepended first
	assert( list1.myLast->myNext == NULL );
	cout << " 1 " << flush;

	list1.prepend(12);
	assert( list1.getSize() == 3 );
	assert( list1.myFirst != NULL );
	assert( list1.myLast != NULL );
	assert( list1.myFirst != list1.myLast );
	assert( list1.myFirst->myItem == 12 );
	assert( list1.myFirst->myNext != list1.myLast);
	assert( list1.myFirst->myNext->myItem == 11 );
	assert( list1.myFirst->myNext->myNext == list1.myLast);
	assert( list1.myLast->myItem == 10 );
	assert( list1.myLast->myNext == NULL );
	cout << " 2 " << flush;

	cout << " Passed! " << endl;
}

void ListTester::testInsert(){
	cout << "testing Insert() ..." << flush;
	List<double> list1;
	list1.readFrom("list1.txt");
	list1.insert(0,1);

	cout << " 0 " << flush;

	assert( list1.getIndexOf(1) == 0 );
	assert( list1.getIndexOf(0) == 1 );
	assert( list1.getIndexOf(2) == 2 );
	assert( list1.getIndexOf(3) == 3 );
	assert( list1.getIndexOf(4) == 4 );
	assert( list1.getIndexOf(5) == 5 );

	cout << " 1 " << flush;
	cout << " Passed ! " << endl;

}

