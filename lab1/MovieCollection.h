/*
 * MovieCollection.h
 *
 *  Created on: Sept 15, 2015
 *      Author: zdw3
 */

#ifndef MOVIECOLLECTION_H_
#define MOVIECOLLECTION_H_

#include <string>

using namespace std;
#include "Movie.h"
#include <vector>
#include <cassert>
class MovieCollection {
public:
	MovieCollection(const string& fileName);
	vector<Movie> searchByDirector(const string& directorName) const;
private:
	vector<Movie> myMovies;
};

#endif /* MOVIECOLLECTION_H_ */