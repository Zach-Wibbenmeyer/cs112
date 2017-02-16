/*
 * PalindromeDetector.cpp
 *
 *  Created on: Nov 17, 2015
 *      Author: zdw3
 */

#include "PalindromeDetector.h"

/*
 * Detects the palindromes
 */
bool PalindromeDetector::isPalindrome(string& str) {
	str = str + " ";
	stringstream ss(str);
	char c;
	Stack<char> s1(1);
	ArrayQueue<char> q1(1);
	while (ss) {
		ss.get(c);
		if ( isupper(c) ) {
			c = tolower(c);
		}
		if ( isalpha(c) ) {
			try {
				s1.push(c);
				q1.append(c);
			} catch (StackException& se) {
				s1.setCapacity(s1.getCapacity() * 2);
				s1.push(c);
				q1.setCapacity(q1.getCapacity() * 2);
				q1.append(c);
			}
		}
	}
	if ( s1.getSize() == 0 ) {
		return false;
	}
	while (!s1.isEmpty() ) {
		char ch1 = s1.pop();
		char ch2 = q1.remove();
		if (ch1 != ch2) {
			return false;
		}
	}
	return true;
}


/*
 * Detects the palindromes in a string and returns ***
 */
void PalindromeDetector::detectPalindromes() {
	ifstream fin(myInputFile.c_str() );
	ofstream fout(myOutputFile.c_str() );
	assert( fin.is_open() );
	assert( fout.is_open() );
	while (fin) {
		string s;
		getline(fin, s);
		if ( isPalindrome(s) ) {
			s = s + " ***";
		}
		fout << s << endl;
	}
	fin.close();
	fout.close();
}

/*
 * Explicit Value constructor
 */
PalindromeDetector::PalindromeDetector(const string& inputFile, const string& outputFile) {
	myInputFile = inputFile;
	myOutputFile = outputFile;
}
