/*
 * MovieCollection.h

 *
 *  Created on: Sept 22, 2015
 *      Author: Zach Wibbenmeyer
 */

#ifndef MOVIECOLLECTION_H_
#define MOVIECOLLECTION_H_

#include <string>

//Include all the necessary modules
using namespace std;
#include "Movie.h"
#include <vector>
#include <cassert>
#include <fstream>
#include <ostream>

//Class for the collection of movies
class MovieCollection {
public:
	MovieCollection(const string& fileName);
	vector<Movie> searchByDirector(const string& directorName) const;
	vector<Movie> searchByYear(int year);
	vector<Movie> searchByTitlePhrase(const string& phrase);
	void addMovie(const Movie& newMovie);
	void removeMovie(const Movie& aMovie);
	void save() const;
private:
	//Create a vector for the collection of movies
	vector<Movie> myMovies;
	string srcFileName;
};

#endif /* MOVIECOLLECTION_H_ */
