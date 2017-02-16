/*
 * Movie.cpp

 *
 *  Created on: Jun 10, 2015
 *      Author: zdw3
 */
/*
 * Movie.cpp
 * Student Name: Zach Wibbenmeyer (zdw3)
 * Date: Sept 22, 2015
 * Begun by: Joel Adams, for CS 112 at Calvin College
 */

#include "Movie.h"

//Default Constructors
Movie::Movie() {
	myTitle = "";
	myYear = 0;
	myDirector = "";
}

//Getter for the movie title
string Movie::getTitle() const {
	return myTitle;
}

//Getter for the movie year
int Movie::getYear() const {
	return myYear;
}

//Getter for the director
string Movie::getDirector() const {
	return myDirector;
}

//Assign variables
Movie::Movie(const string& title, int year, const string& director) {
	myTitle = title;
	myYear = year;
	myDirector = director;
}

/* readFrom() reads movies from the collection
 * @param: in
 */
void Movie::readFrom(istream& in) {
	getline(in, myTitle);
	in >> myYear;
	string newLine; getline(in, newLine);
	getline(in, myDirector);
}

/* writeTo() writes a movie to the collection
 * @param: out
 */
void Movie::writeTo(ostream& out) const {
	out << myTitle << '\n'
	    << myYear  << '\n'
	    << myDirector << '\n';
}

/*operator== tests if two movies are equal to each other
 * @param: movie2, a second movie that is compared to the first movie
 * @return: a True statement if the movies are the same, false if they are not
 */
bool Movie::operator==(const Movie& movie2) {
	if (myTitle == movie2.getTitle()) {
		if (myYear == movie2.getYear()) {
			if (myDirector == movie2.getDirector()) {
				return true;
			}
		}
	}
	return false;
}
