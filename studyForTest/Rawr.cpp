/*
 * Rawr.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: Joel
 */

#include "Rawr.h"

using namespace std;

Rawr::Rawr() {
	pointer = new int[3];
	pointer[1] = 1;
	pointer[2] = 2;
	pointer[3] = 3;
	size = 3;
}

Rawr::Rawr(int i) {
	// dynamic allocation of pointer
	pointer = new int[i];
	// static allocation of number
	int number = 2;
	size = i;
	for (unsigned index = 0; index < size; index++) {
		pointer[index] = index;
	}
	// number will be deleted at the following curly brace
}

Rawr::~Rawr() {
	size = 0;
	delete[] pointer;
	pointer = NULL;
}

void Rawr::printMe() {
	for(unsigned i = 0; i < size; i++) {
		cout << i << endl;
	}

}

Rawr Rawr::operator=(Rawr rawr1) {
	delete[] pointer;
	size = 0;
	pointer = rawr1.pointer;
	size = rawr1.size;
	return *this;
}
