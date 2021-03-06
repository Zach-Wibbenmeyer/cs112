/* tester.cpp drives the testing of our Vec template and Matrix class.
 * Student: Zach Wibbenmeyer
 * Date: October 12, 2015
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

//Include the necessary modules
#include "VecTester.h"
#include "MatrixTester.h"
#include "Application.h"
using namespace std;

//Main Program
int main() {
	//Implement the tests
	VecTester vt;
	vt.runTests();
	MatrixTester mt;
	mt.runTests();
	Application ap;
	ap.runApplication();
}
