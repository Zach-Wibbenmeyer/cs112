/*
 * PalindromeDetectorTester.h
 *
 *  Created on: Nov 17, 2015
 *      Author: zdw3
 */

#ifndef PALINDROMEDETECTORTESTER_H_
#define PALINDROMEDETECTORTESTER_H_

#include "PalindromeDetector.h"
#include <iostream>
#include <cassert>
using namespace std;

class PalindromeDetectorTester {
public:
	void runTests() const;
	void testConstructors() const;
	void testIsPalindrome() const;
	void testDetectPalindromes() const;
};

#endif /* PALINDROMEDETECTORTESTER_H_ */
