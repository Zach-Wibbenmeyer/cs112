/*
 * PalindromeDetector.h
 *
 *  Created on: Nov 17, 2015
 *      Author: zdw3
 */

#ifndef PALINDROMEDETECTOR_H_
#define PALINDROMEDETECTOR_H_

//Include the necessary libraries
#include "Stack.h"
#include "ArrayQueue.h"
#include "StackException.h"
#include <iostream>
#include <cctype>
#include <sstream>
#include <fstream>
#include <cassert>
#include <string>
using namespace std;

//Create a class for the PalindromeDetector
class PalindromeDetector {
public:
	bool isPalindrome(string& str);
	void detectPalindromes();
	PalindromeDetector(const string& inputFile, const string& outputFile);
private:
	string myInputFile;
	string myOutputFile;
	friend class PalindromeDetectorTester;
};

#endif /* PALINDROMEDETECTOR_H_ */
