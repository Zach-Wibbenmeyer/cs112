/* tester.cpp
 * Joel Adams, for CS 112 at Calvin College.
 */

//Include the necessary modules
#include "ListTester.h"
#include "VecTester.h"

// Main program
int main() {
	//Implement the tests
	ListTester lt;
	lt.runTests();
	VecTester vt;
	vt.runTests();
}
