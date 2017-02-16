/*
 * Menu.cpp

 * Student Name: Zach Wibbenmeyer (zdw3)
 * Created on: Sept 22, 2015
 * Professor: Serita Nelesen
 */


//Gain access to the necessary modules
#include "Menu.h"
using namespace std;

//Create a method that prints the menu options
int Menu::createMenu() const {
	cout << "\n Welcome to Phil's Movie Collection Manager!" << endl;
	cout << "\n Please enter: "<< endl;
	cout << "1 - to search the collection for movies by a given director" << endl;
	cout <<	"2 - to search the collection for movies made in a given year" << endl;
	cout << "3 - to search the collection for movies with a given phrase in their title" << endl;
	cout << "4 - to add a new movie to the collection" << endl;
	cout << "5 - to remove a movie from the collection" << endl;
	cout << "0 - to quit" << endl;
	cout << "--->";

	//Ask the user to input a choice
	int number;
	cout << "Please make a choice: ";
	cin >> number;
	//If statements for the different choices
	if (number == 1) {
		cout << "\n Okay, let's search for a director!" << endl;
	}
	else if (number == 2) {
		cout << "\n Okay, let's search for a collection of movies in a given year!" << endl;
	}
	else if (number == 3) {
		cout << "\n Okay, let's search for movies with a given phrase in their title!" << endl;
	}
	else if (number == 4) {
		cout << "\n Okay, let's add a movie to the collection!" << endl;
	}
	else if (number == 5) {
		cout << "\n Okay, let's remove a movie from the collection!" << endl;
	}
	else if (number == 0) {
		cout << "\n Goodbye!" << endl;
	}
	else {
		cout << "Please select from the list of options" << endl;
	}

	return number;
}




