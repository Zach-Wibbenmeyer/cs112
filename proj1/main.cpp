/*
 * main.cpp

 * Student Name: Zach Wibbenmeyer (zdw3)
 * Created on: Sept 22, 2015
 * Professor: Serita Nelesen
 */

//import the necessary modules
#include "Menu.h"
#include "Movie.h"
#include "MovieCollection.h"
#include "CollectionTester.h"
#include "MovieTester.h"
using namespace std;

int main() {
	//Implement Movie Tester and Collection Tester
	MovieTester mt;
	mt.runTests();
	CollectionTester ct;
	ct.runTests();

	MovieCollection mc("testCollection.txt");
	int opt = -1;
	Menu m;

	//While loop for running the menu
	while (opt != 0) {
	opt = m.createMenu();
		//Option for searching a movie by director
		if (opt == 1) {
			string tmp;
			string director;
			cout << "Please specify the director you wish to search by: " << flush;
			getline(cin, tmp);
			getline(cin, director);
			vector<Movie> results = mc.searchByDirector(director);
			for (unsigned x = 0; x < results.size(); x++) {
				cout << "\n Movie: " << results[x].getTitle() << endl;
				cout << "Year: " << results[x].getYear() << endl;
				cout << "Director: " << results[x].getDirector() << endl;
			}
		}
		//Option for searching for a movie by a given year
		else if (opt == 2) {
			int year;
			cout << "Please specify the year you wish to search by: " << flush;
			cin >> year;
			vector<Movie> results = mc.searchByYear(year);
			for (unsigned x = 0; x < results.size(); x++) {
				cout << "\n Movie: " << results[x].getTitle() << endl;
				cout << "Year: " << results[x].getYear() << endl;
				cout << "Director: " << results[x].getDirector() << endl;
			}
		}
		//Option for searching for a movie by a given title phrase
		else if (opt == 3) {
			string tmp2;
			string title;
			cout << "Please specify the title phrase you wish to search by: " << flush;
			getline(cin, tmp2);
			getline(cin, title);
			vector<Movie> results = mc.searchByTitlePhrase(title);
			for (unsigned x = 0; x < results.size(); x++) {
				cout << "\n Movie: " << results[x].getTitle() << endl;
				cout << "Year: " << results[x].getYear() << endl;
				cout << "Director: " << results[x].getDirector() << endl;
			}
		}
		//Option for adding a movie to the collection
		else if (opt == 4) {
			string tmp3;
			string tmp4;
			string title;
			cout << "\n Please type in the movie title: " << flush;
			getline(cin, tmp3);
			getline(cin, title);
			int year;
			cout << "\n Please enter the year of the movie: " << flush;
			cin >> year;
			string director;
			cout << "\n Please enter the director of the movie: " << flush;
			getline(cin, tmp4);
			getline(cin, director);
			Movie newMovie(title, year, director);
			mc.addMovie(newMovie);
			mc.save();
		}
		//Option for removing a movie from the collection
		else if (opt == 5) {
			string tmp5;
			string tmp6;
			string title;
			cout << "\n Please type in the movie title: " << flush;
			getline(cin, tmp5);
			getline(cin, title);
			int year;
			cout << "\n Please enter the year of the movie: " << flush;
			cin >> year;
			string director;
			cout << "\n Please enter the director of the movie: " << flush;
			getline(cin, tmp5);
			getline(cin, director);
			Movie aMovie(title, year, director);
			mc.removeMovie(aMovie);
			mc.save();
		}
	}
}


