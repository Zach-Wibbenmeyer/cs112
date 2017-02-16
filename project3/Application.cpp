/* Student Name: Zach Wibbenmeyer
 * Date: October 5, 2015
 * Begun by: Zach Wibbenmeyer, for CS 112 at Calvin College
 */

//Include the necessary modules
#include "VecTester.h"
#include "Application.h"
using namespace std;

//Create the method for the application
void Application::runApplication() const {

	//Create two signed variables
	signed dimension;
	signed number;

	//Make instances from the Vec class
	Vec start;
	Vec final;
	Vec nextVec;

	//Set a boolean to true
	bool loop = true;

	cout << "\nWelcome to the Vector Machine" << endl;

	//Forever while loop
	while (loop == true) {
		cout << "\nPlease specify the number of dimensions in the vector" << endl;
		cout << "You must start from 1" << endl;
		cout << "Press 0 right now to quit" << endl;

		cout << "\nPlease enter a number of dimensions: " << flush;
		cin >> dimension;

		//If the dimensions are greater than 0
		if (dimension > 0) {

			cout << "\nYou have specified " << dimension << " dimensions" << endl;

			//Use the setSize method for the dimensions
			start.setSize(dimension);
			final.setSize(dimension);
			nextVec.setSize(dimension);

			//For loop that prints the values
			for (unsigned x = 0; x < dimension; x++) {
				int val;
				bool open = true;
				while (open == true) {
					cout << "\n\nPlease enter value " << x + 1 << " for the position: " << flush;
					cin >> val;
					//Checks if the user enters a string
					//http://stackoverflow.com/questions/5864540/infinite-loop-with-cin
					if (cin.fail()) {
						cout << "Please enter integers only";
						// get rid of failure state
						cin.clear();
						// discard 'bad' character(s)
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					else {
						start[x] = val;
						open = false;
					}
				}
			}

			cout << "\n Your starting point is: start {";
			//For loop that prints the starting point
			for (unsigned x = 0; x < dimension; x++) {
				if ((x + 1) == dimension) {
					cout << start[x] << flush;
				}
				else {
					cout << start[x] << "," << flush;
				}
			}
			//Set final equal to start
			final = start;
			cout << "}" << endl;
			//If variable number is greater than 0
			bool run = true;
			while (run == true) {
				cout << "\nPress 0 to quit right now" << endl;
				cout << "\n Please specify the number of additional vectors: " << flush;
				cin >> number;
				if (number > 0) {
					//For loop that asks for additional vectors
					for (unsigned x = 0; x < number; x++) {
							cout << "\n\n For vector " << x + 1 << ":" << endl;;
							for (unsigned x = 0; x < dimension; x++) {
								bool close = true;
								int val = 0;
								while (close == true) {
									//Checks to see if the user enters a string
									//http://stackoverflow.com/questions/5864540/infinite-loop-with-cin
									cout << "\n Enter the position " << x + 1 << " value for current vector: ";
									cin >> val;
									if (cin.fail()) {
										cout << "You must enter integers only" << endl;
										//get rid of failure state
										cin.clear();
										//discard bad characters
										cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
									}
									else {
									nextVec[x] = val;
									close = false;
									}
								}
								//Set final equal to itself plus variable nextVec
								final = final + nextVec;
							}

						//Print the vector(s) entered
						cout << "\n\n The vector you just entered was {";
						for (unsigned x = 0; x < dimension; x++) {
							if ((x + 1) == dimension) {
								cout << nextVec[x] + nextVec[x] << flush;
							}
							else {
								cout << nextVec[x] + nextVec[x] << ", " << flush;
							}
						}
						cout << "}" << endl;
					}

					//Print the starting point
					cout << "\n Your starting point is: start = {";
					for (unsigned x = 0; x < dimension; x++) {
						if ((x + 1) == dimension) {
							cout << start[x] << flush;
						} else {
							cout << start[x] << ", " << flush;
						}
					}

					cout << "}" << endl;
					cout << "The sum of the vectors you entered is: sum = {";
					//For loop that adds the vectors and starting point together
					for (unsigned x = 0; x < dimension; x++) {
						if ((x + 1) == dimension) {
							cout << start[x] + nextVec[x] << flush;
						} else {
							cout << start[x] + nextVec[x] << ", " << flush;
						}
					}

					cout << "}" << endl;
					cout << "\nWould you like the program to run again?" << endl;
					//Forever while loop that asks if you want to run the program again
					while (true) {
						cout << "Enter 1 to run again or 0 to quit: " << flush;
						int answer;
						cin >> answer;
						//If 1, reset the loop and start over
						if (answer == 1) {
							cout << "\nOkay, taking you to the beginning of the program" << endl;
							loop = true;
							run = false;
							break;
						}
						//if 0, quit
						else if (answer == 0) {
							loop = false;
							run = false;
							cout << "\nGoodbye!" << endl;
							break;
						}
					}
				}
				//Throw an exception if the number of additional vectors is less than 0
				else if (number < 0) {
					try {
						throw std::range_error("Your number of additional vectors "
								"are less or equal to 0");
					}
					catch (range_error& y) {
						cout << "An exception occurred: " << y.what() << "\n";
					}
				}
				//Checks to see if the user enters a string
				//http://stackoverflow.com/questions/5864540/infinite-loop-with-cin
				else if (cin.fail()) {
					cout << "You must enter a number greater than 0";

					// get rid of failure state
					cin.clear();

					// discard 'bad' character(s)
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				}
				//If the user enters 0 then quit
				else {
					cout << "Goodbye!" << flush;
					run = false;
					loop = false;
				}
			}
		}
		//Throw an exception for if the dimensions are less than 0
		else if (dimension < 0) {
			try {
				throw std::range_error("Your dimensions are less than 0");
			}
			catch (range_error& x) {
				cout << "An exception occurred: " << x.what() << "\n";
			}
		}
		//Checks to see if the user enters a string
		//http://stackoverflow.com/questions/5864540/infinite-loop-with-cin
		else if (cin.fail()) {
			cout << "You must enter a number greater than 0";

			// get rid of failure state
			cin.clear();

			// discard 'bad' character(s)
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		//If the user enters 0 then quit
		else {
			cout << "\nGoodbye!" << flush;
			break;
		}

	}
}

