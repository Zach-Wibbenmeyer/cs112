/*
 * Experiment.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: zdw3
 */

#include "Experiment.h"
using namespace std;

/*
 * Experiment that runs through the BST files
 */
void Experiment::runExperiment() {
	cout << "Please enter a file: " << flush;
	string fileName;
	cin >> fileName;
	ifstream fin( fileName.data() );
	long var = 0;
	unsigned numRepeats = 0;
	BST<long> bst;
	assert( fin.is_open() );
	while (true) {
		fin >> var;
		if ( fin.eof() ) {
			break;
		} try {
			bst.insert(var);
		} catch (Exception& e) {
			numRepeats++;
		}
	}
	fin.close();
	cout << "The Height is " << bst.getHeight() << " and there were " << numRepeats << " repeats." << endl;
}
