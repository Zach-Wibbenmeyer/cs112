/* CollectionTester.h tests the MovieCollection class.

 * Student Name: Zach Wibbenmeyer (zdw3)
 * Date: Sept 22, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

//Include the necessary modules
#ifndef COLLECTIONTESTER_
#define COLLECTIONTESTER_
#include <iostream>
#include <cassert>
#include <vector>
#include "MovieCollection.h"
using namespace std;

//Class for all the tests being run
class CollectionTester {
public:
	void testConstructor() const;
    void runTests() const;
    void testSearchByYear() const;
    void testSearchByTitlePhrase() const;
    void testAddMovie() const;
    void testRemoveMovie() const;
    void testSave() const;
};

#endif /*COLLECTIONTESTER_*/
