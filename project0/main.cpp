/*
 * main.cpp

 * Professor: Serita Nelesen
 *  Created on: Jun 6, 2015
 *      Author: zdw3
 */



#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	cout << "Welcome to the change program!" << endl;

	int charge = 0;
	cout << "Please enter the amount charged for the transaction: \n ";
	cin >> charge;

	int amount_paid = 0;
	cout << "Please enter the amount paid for the transaction: \n ";
	cin >> amount_paid;

	int diff = (amount_paid) - (charge);

	int twenty = (int) diff/20;

	int ten = (int) ((diff%20)/10);

	int five = (int) (((diff%20)%10)/5);

	int one = (int) ((((diff%20)%10)%5)/1);


}
