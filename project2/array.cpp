/* array.cpp defines "C style" array operations


 * Name: Zach Wibbenmeyer
 * Date: Sept 28, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */
 
#include "array.h"
using namespace std;

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
 * @param: double --> *a, int --> size
 * @return: the sum divided by the size of the variable
 */
double average(double *a, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i];
	}
	return (sum / size);
}

/*sum() searches the arrays and returns the sum of all the inputs
 * @param: double --> a*, int --> size
 * @return: The sum of the inputs in the arrays
 */
double sum(double *a, int size) {
	double total = 0;
	for (int x = 0; x < size; x++) {
		total += a[x];
	}
	return total;
}

/* read() reads size values from in and stores them in a
 * @param: istream& --> in, double --> *a, int --> size
 */
void read(istream& in, double *a, int size) {
	for (int x = 0; x < size; x++) {
		in >> a[x];
	}
}

/* fill () opens an ifstream, reads an integer from fileName into numValues,
 * 		dynamically allocates an array of numValues double values,disposes of the old array
 * 		storing address in a, reads numValues from the file and stores them in the dynamic array,
 * 		and then closes the ifstream
 * @param: string& --> fileName, double --> *&a, int --> &numValues
 */
void fill(const string& fileName, double *&a, int &numValues) {
	ifstream fin(fileName.c_str());
	assert (fin.is_open());
	fin >> numValues;
	delete [] a;
	a = new double[numValues];
	read(fin, a, numValues);
	fin.close();
}

/* resize() changes the size of the array from oldSize to newSize. If
 * 		newSize is greater than oldSize, all of the values in the array are
 * 		copied into the new array.  If newSize is less than oldSize, the end-elements
 * 		of the array will be truncated.  The old array is then disposed of.
 * @param: double --> *&a, int --> oldSize, int --> newSize
 */
void resize(double *&a, int oldSize, int newSize) {
	if (oldSize != newSize) {
		double * b = new double[newSize];
		if (newSize > oldSize) {
			for (int x = 0; x < oldSize; x++) {
				b[x] = a[x];
			}
			for (int x = oldSize; x < newSize; x++) {
				b[x] = 0;
			}
		}
		else if (oldSize > newSize) {
			for (int x = 0; x < newSize; x++) {
				b[x] = a[x];
			}
		}
		delete [] a;
		a = b;
	}
}

/* concat() passes back an array (a3) containing the values of a1 followed by those
 * 		of a2, sets size3 = size1 + size2.  Also disposes of the old array
 * @param: double --> *a1, int --> size1, double --> *a2, int --> size2,
 * 		double --> *&a3, int --> &size3
 */
void concat(double *a1, int size1, double *a2, int size2, double *&a3, int &size3) {
	int c = (size1 + size2);
	double* newArray = new double[c];
	for (int x = 0; x < size1; x++) {
		newArray[x] = a1[x];
	}
	for (int x = size1; x < c; x++) {
		newArray[x] = a2[x - size1];
	}
	delete [] a3;
	a3 = newArray;
	size3 = c;
}
