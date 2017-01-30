#ifndef Line_Storage_H
#define Line_Storage_H

#include <string>
#include <vector>
using namespace std;

class LineStorage {

private:
	static vector <string> Movies;
	static vector <string> Keywords;
public:
	void storeMovies(string);
	string getMovie(int);
	string getKeyword(int);
	int numberOfMovies();
	int numberOfKeywords();
	void storeKeywords(string);
	void printMovies();

};

#endif
