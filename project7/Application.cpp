/*
 * Application.cpp
 *
 *  Created on: Nov 4, 2015
 *      Author: zdw3
 */

#include "Application.h"
using namespace std;

//Execute the Application
void Application::runApplication(string& in, string& out) {
	ifstream fin( in.c_str() );
	ofstream fout( out.c_str() );
	Stack<char> s1(1);
	while (fin) {
		char c;
		fin.get(c);
		if (isalnum(c) ) {
			try {
				s1.push(c);
			}
			catch (StackException& se) {
				s1.setCapacity(s1.getCapacity()*2);
				s1.push(c);
			}
		}
		else {
			while(!(s1.isEmpty()) ) {
				char z = s1.pop();
				fout << z << flush;
			}
			fout << c << flush;
		}
	}
	fin.close();
	fout.close();
	cout << "Problem is finished" << endl;
}
