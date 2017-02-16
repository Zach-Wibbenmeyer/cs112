/*
 * Rawr.h
 *
 *  Created on: Jun 25, 2015
 *      Author: Joel
 */

#ifndef RAWR_H_
#define RAWR_H_

#include<iostream>

class Rawr {
public:
	Rawr();
	Rawr(int i);
	~Rawr();
	void printMe();
	Rawr operator=(Rawr rawr1);
	int* pointer;
	unsigned size;
};

#endif /* RAWR_H_ */
