/* BST_Tester.h declares a class to test class BST.
 * Student: Zach Wibbenmeyer
 * Joel Adams, for CS 112 at Calvin College.
 */

#ifndef BST_TESTER_H_
#define BST_TESTER_H_

#include "BST.h"
#include <cassert>
#include <iostream>
using namespace std;

class BST_Tester
{
public:
	void runTests();
	void testConstructor();
	void testInsert();
	void testContains();
	void testTraverse();
	void testGetHeight();
};

#endif /*BST_TESTER_H_*/
