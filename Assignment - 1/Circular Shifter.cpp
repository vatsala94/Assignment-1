#include "Circular Shifter.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

vector <string> CircularShifter::shiftedLines;

void CircularShifter::setup(LineStorage lines) {
	int size = lines.numberOfMovies();
	int index;
	string movie;
	vector <string> words;
	for (index = 0; index < size; index++) {
		movie = lines.getMovie(index);
		circularShift(movie,lines);
	}
}

void CircularShifter::circularShift(string line, LineStorage L1) {
	vector <string> wordsOfMovie;
	string rotatedMovie;
	wordsOfMovie = stringToWords(line);
	for (int i = 0; i < wordsOfMovie.size(); i++) {
		rotate(wordsOfMovie.begin(), wordsOfMovie.begin() + 1, wordsOfMovie.end());
		if (checkIfKeyword(wordsOfMovie, L1)) {
			for (int j = 0; j < wordsOfMovie.size(); j++) {
				rotatedMovie = rotatedMovie + wordsOfMovie[j] + " ";
			}
			shiftedLines.push_back(rotatedMovie);
			rotatedMovie = "";
		}
	}
}

bool CircularShifter::checkIfKeyword(vector <string> line, LineStorage L1) {
	int size = L1.numberOfKeywords();
	string keyword;
	for (int i = 0; i < size; i++) {
		keyword = L1.getKeyword(i);
		if (toLowerCase(line.front()) == toLowerCase(keyword)) {
			return false;
		}
	}
	return true;
}

vector <string> CircularShifter::stringToWords(string line) {
	int startIndex = 0;
	int endIndex = 0;
	int length = line.length();
	int index, i;
	int positionIndex=0;
	string word;
	vector <string> wordsOfMovie;
	for (index = startIndex; index < length && positionIndex!=-1; index++) {
		startIndex = line.find_first_not_of(" ", positionIndex);
		endIndex = line.find_first_of(" \n", startIndex);
		if (endIndex == -1) {
			word = line.substr(startIndex);
		}
		else {
			for (i = startIndex; i < endIndex; i++) {
				word = word + line[i];
			}
		}
		wordsOfMovie.push_back(word);
		word = "";
		positionIndex = endIndex;
	}
	return wordsOfMovie;
}

void CircularShifter::printWords(vector <string> words) {
	for (int i = 0;i < words.size();i++) {
		cout << words[i] << endl;
	}
}

void CircularShifter::printShiftedMovies() {
	for (int i = 0;i < shiftedLines.size();i++) {
		cout << shiftedLines[i] << endl;
	}
}

vector <string> CircularShifter::getShiftedLines() {
	return shiftedLines;
}

string CircularShifter::toLowerCase(string line) {
	char lowercase;
	string lowercaseLine;
	for (int i = 0; i < line.length(); i++) {
		lowercase = tolower(line[i]);
		lowercaseLine = lowercaseLine + lowercase;
	}
	return lowercaseLine;
}