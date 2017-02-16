/* MovieTester.h

 * Student Name: Zach Wibbenmeyer (zdw3)
 * Date: Sept 22, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef MOVIETESTER_H_
#define MOVIETESTER_H_

//Include all the necessary modules
#include "Movie.h"
#include <iostream>
#include <cassert>
#include <fstream>
using namespace std;

//Class for running the tests in MovieTester
class MovieTester {
public:
   void runTests() const;
   void testDefaultConstructor() const;
   void testExplicitConstructor() const;
   void testReadFrom() const;
   void testWriteTo() const;
   void testOperator() const;
};

#endif /*MOVIETESTER_H_*/