#ifndef ALphabetizer_H
#define ALphabetizer_H

#include <string>
#include <vector>
#include "Circular Shifter.h"

using namespace std;

class Alphabetizer {

private:
	static vector <string> sortedLines;
public:
	void sortMovies(CircularShifter);
	vector <string> getSortedLines();
	vector <string> convertToUpper(vector <string>);
};

#endif

