/* main.cpp runs a series of experiments comparing vector and list operations.
 * Joel Adams, for CS 112 at Calvin College.
 */

//Include the necessary modules
#include "Experiment0.h"
#include "Experiment1.h"
#include "Experiment2.h"

//Main program
 int main() {
	//Invoke the experiments
 	Experiment0 exp0;
 	exp0.run();
 	Experiment1 exp1;
 	exp1.run();
 	Experiment2 exp2;
 	exp2.run();
 	
}
