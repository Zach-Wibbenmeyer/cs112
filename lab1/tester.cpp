/*
 * tester.cpp tests the classes in our project
 * Student Name: Zach Wibbenmeyer
 * Date: Sept 15, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College
 */


#include "MovieTester.h"
#include "CollectionTester.h"
#include <iostream>
using namespace std;

int main() {
	MovieTester mt;
	mt.runTests();
	CollectionTester ct;
	ct.runTests();
}

