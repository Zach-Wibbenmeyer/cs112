/* array.cpp defines "C style" array operations
 * Name: Zach Wibbenmeyer
 * Date: Sept 22, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */
 
#include "array.h"

void initialize(double *a, int size) {
	int val = 0;
	for (int i = 0; i < size; i++) {
		val = i+1;
		a[i] = val;
	}
}

void print(double *a, int size) {
	for (int i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}		

/* average() searches the variables and prints the average of the numbers
 * @param: *a --> double, size --> int
 * @return: the sum divided by the size of the variable
 */
double average(double *a, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i];
	}
	return (sum / size);
}
