/*
 * MovieCollection.cpp
 *
 *  Created on: Sept 15, 2015
 *      Author: zdw3
 */

#include "MovieCollection.h"
#include <fstream>
using namespace std;

MovieCollection::MovieCollection(const string& fileName) {
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	Movie aMovie;
	while (true) {
		aMovie.readFrom(fin);
		if ( !fin ) break;
		string blankLine;
		getline(fin, blankLine);
		myMovies.push_back(aMovie);
	}
	fin.close();
}

vector<Movie> MovieCollection::searchByDirector(const string& directorName) const {
   vector<Movie> v;
   for (unsigned i = 0; i < myMovies.size(); i++) {
      if ( myMovies[i].getDirector().find(directorName) != string::npos ) {
         v.push_back( myMovies[i] );
      }
   }
   return v;
}

