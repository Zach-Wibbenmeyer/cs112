#ifndef MOVIE_H_
#define MOVIE_H_

//Include all the necessary modules
#include <string>
#include <fstream>
#include <cassert>
using namespace std;

//Class for running the different constructors
class Movie {
public:
   Movie();
   Movie(const string& title, int year, const string& director);
   void readFrom(istream& in);
   void writeTo(ostream& out) const;
   bool operator==(const Movie& movie2);
   string getTitle() const;
   int    getYear() const;
   string getDirector() const;
private:
   string myTitle;
   int    myYear;
   string myDirector;
};

#endif /*MOVIE_H_*/
