/*
 * MovieCollection.cpp

 *
 *  Created on: Jun 10, 2015
 *      Author: zdw3
 */
/*
 * MovieCollection.cpp
 *
 *  Created on: Sept 22, 2015
 *      Author: zdw3
 */

#include "MovieCollection.h"
using namespace std;

/* MovieCollection() constructs our collection using the data
*   in a given source file.
*
* @param: fileName, a string.
* Precondition: fileName contains the name of an input file
*                containing the data of N Movies (N >= 1),
*                separated by blank lines, ending with a newline.
* Postcondition: myMovies.size() == N &&
*                myMovies contains the Movies in fileName.
*/
MovieCollection::MovieCollection(const string& fileName) {
	srcFileName = fileName;
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

/* searchByDirector() searches the collection for movies by a given director.
*
* @param: director, a string containing the director's name (or a part of it)
* @return: a vector containing all movies in the collection
*           for whom director is a substring of myDirector.
*/
vector<Movie> MovieCollection::searchByDirector(const string& directorName) const {
   vector<Movie> v;
   for (unsigned i = 0; i < myMovies.size(); i++) {
      if ( myMovies[i].getDirector().find(directorName) != string::npos ) {
         v.push_back( myMovies[i] );
      }
   }
   return v;
}

/* searchByYear() searches the collection for movies by a given year.
 *
 * @param: year, an int containing the year being searched
 * @return: a vector containing all movies in the collection
 * 		containing the inputed year
 */
vector<Movie> MovieCollection::searchByYear(int year) {
	vector<Movie> v;
	for (unsigned x = 0; x < myMovies.size(); x++) {
		if ( myMovies[x].getYear() == year) {
			v.push_back(myMovies[x]);
		}
	}
	return v;
}

/* searchByTitlePhrase() searches the collection for movies by a given
 * 		title phrase
 * 	@param: phrase, a string containing the title phrase searched by
 * 	@return: a vector containing all movies in the collection containing
 * 		the inputed title phrase
 */
vector<Movie> MovieCollection::searchByTitlePhrase(const string& phrase) {
	vector<Movie> v;
	for (unsigned x = 0; x < myMovies.size(); x++) {
		if ( myMovies[x].getTitle().find(phrase) != string::npos) {
			v.push_back( myMovies[x]);
		}
	}
	return v;
}

/* addMovie() adds a movie to the collection
 * @param: newMovie, a string containing the movie inputed
 *
 */
void MovieCollection::addMovie(const Movie& newMovie) {
	myMovies.push_back(newMovie);
}

/* removeMovie() removes a movie from the collection
 * @param: aMovie, a string that contains the movie inputed
 * Precondition: The movie inputed must already exist in the collection
 * Postcondition: The movie will be removed from the collection
 */
void MovieCollection::removeMovie(const Movie& aMovie) {
	for (unsigned x = 0; x < myMovies.size(); x++) {
		if ( myMovies[x] == aMovie) {
			myMovies.erase(myMovies.begin() + x);
		}
	}
}

/* save() Saves a movie and writes it to the collection
 * Precondition: A Movie must have been added or removed
 * PostCondition: The movie will be written in the collection or removed from it
 */
// Taken from the internet http://www.cplusplus.com/forum/beginner/131232/
void MovieCollection::save() const {
	ofstream outputFile;
	outputFile.open(srcFileName.c_str());

	Movie aMovie;
	for (unsigned x = 0; x < myMovies.size(); x++) {
		myMovies[x].writeTo(outputFile);
		outputFile << "\n";
	}
	outputFile.close();
}

