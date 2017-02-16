/*
 * main.cpp
 *
 *  Created on: Apr 28, 2014
 *      Author: Joel
 */


#include <iostream>
//#include "MatrixTester.h"
#include "Rawr.h"

using namespace std;

int main() {
//	cout << "doing stuff" << endl;
//	MatrixTester mt;
//	mt.runTests();
//
//
//	cout << "done doing stuff" << endl;


	Rawr rawry;
	Rawr r2(3);
	Rawr r3;

	// rawry will be referencable by *this in the function printMe()
	rawry.printMe();

	cout << &rawry.pointer << "Rawr" << rawry.pointer << endl;

	r3 = rawry = r2;
	// rawry and such will be deleted by the destructor we made at the following curly brace
}




