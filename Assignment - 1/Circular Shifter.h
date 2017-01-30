#ifndef Circular_Shifter_H
#define Circular_Shifter_H

#include <string>
#include <vector>
#include "Line Storage.h"

using namespace std;

class CircularShifter {

private:
	static vector <string> shiftedLines;
public:
	void setup(LineStorage);
	void circularShift(string, LineStorage);
	vector <string> stringToWords(string);
	vector <string> getShiftedLines();
	void printWords(vector<string>);
	void printShiftedMovies();
	bool checkIfKeyword(vector <string>, LineStorage);
	string toLowerCase(string);
};

#endif

