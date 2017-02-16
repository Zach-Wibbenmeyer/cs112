/*
 * PalindromeDetectorTester.cpp
 *
 *  Created on: Nov 17, 2015
 *      Author: zdw3
 */

#include "PalindromeDetectorTester.h"

void PalindromeDetectorTester::runTests() const {
	cout << "Testing PalindromeDetector class... " << endl;
	testConstructors();
	testIsPalindrome();
	testDetectPalindromes();
	cout << "All tests passed! " << endl;
}

void PalindromeDetectorTester::testConstructors() const {
	cout << "Testing constructors... " << flush;
	string s1 = "testFile1.txt";
	string s2 = "testFile2.txt";
	PalindromeDetector p1(s1, s2);
	assert(p1.myInputFile == s1);
	assert(p1.myOutputFile == s2);
	cout << " Passed! " << endl;
}


void PalindromeDetectorTester::testIsPalindrome() const {
	cout << "Testing isPalindrome method... " << flush;
	string s1 = "testFile1.txt";
	string s2 = "testFile2.txt";
	PalindromeDetector p1(s1, s2);
	string s3 = " ";
	assert(!p1.isPalindrome(s3));
	cout << " 1 " << flush;
	string s4 = "z";
	assert(p1.isPalindrome(s4));
	cout << " 2 " << flush;
	string s5 = "za";
	assert(!p1.isPalindrome(s5));
	cout << " 3 " << flush;
	string s6 = "zz";
	assert(p1.isPalindrome(s6));
	cout << " 4 " << flush;
	string s7 = "racecar";
	assert(p1.isPalindrome(s7));
	cout << " 5 " << flush;
	string s8 = "fda...''dasf;;;";
	assert(!p1.isPalindrome(s8));
	cout << " 6 " << flush;
	string s9 = "A man, a plan, a canal, Panama";
	assert(p1.isPalindrome(s9));
	cout << " 7 " << flush;
	cout << " Passed! " << endl;
}

void PalindromeDetectorTester::testDetectPalindromes() const {
	cout << "Testing detectPalindromes method... " << flush;
	string s1 = "inputText.txt";
	string s2 = "outputText.txt";
	PalindromeDetector p1(s1, s2);
	p1.detectPalindromes();
	cout << " Passed! " << endl;
}
