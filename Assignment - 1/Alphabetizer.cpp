#include "Alphabetizer.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

vector <string> Alphabetizer::sortedLines;

void Alphabetizer::sortMovies(CircularShifter shiftedLines) {
	sortedLines = convertToUpper(shiftedLines.getShiftedLines());
	string line;
	for (int i = 0; i < sortedLines.size(); i++) {
		line = sortedLines[i];
		toupper(line[0]);

	}
	sort(sortedLines.begin(), sortedLines.end());
}

vector <string> Alphabetizer::convertToUpper(vector <string> lines) {
	string lineToConvert;
	char firstChar;
	for (int i = 0; i < lines.size(); i++) {
		lineToConvert = lines[i];
		firstChar = toupper(lineToConvert[0]);
		lines[i] = firstChar + lines[i].substr(1);
	}
	return lines;
}

vector <string> Alphabetizer::getSortedLines() {
	return sortedLines;
}