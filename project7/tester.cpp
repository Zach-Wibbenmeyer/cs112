/* tester.cpp is a "driver" to run the tests in the StackTester class.
 * Joel Adams, for CS 112 at Calvin College.
 * Student: Zach Wibbenmeyer
 * Date: July 23, 2015
 */

//Include the necessary libraries
#include "StackTester.h"
#include "Application.h"
#include <string>
using namespace std;

//Main program
int main() {
	StackTester st;
	st.runTests();
	Application ap;
	string s1 = "test.txt";
	string s2 = "test2.txt";
	ap.runApplication(s1, s2);
}

