/* tester.cpp drives the testing of our Vec class.
 * Student: Zach Wibbenmeyer
 * Date: October 5, 2015
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

//Include the necessary modules
#include "VecTester.h"
#include "Application.h"
using namespace std;

//Main program
int main() {
	//Implement all of the tests
	VecTester vt;
	vt.runTests();
	Application ap;
	ap.runApplication();
}
