/* tester.cpp drives the testing of the Queue classes.
 * Joel Adams, for CS 112 at Calvin College.
 */

#include "ArrayQueueTester.h"
#include "LinkedQueueTester.h"
#include "PalindromeDetectorTester.h"
 
//Main program
 int main() {
 	ArrayQueueTester aqt;
 	aqt.runTests();
 	LinkedQueueTester lqt;
 	lqt.runTests();
 	PalindromeDetectorTester p;
 	p.runTests();
 }
 
 
