#include "Line Storage.h"
#include <iostream>

using namespace std;

vector <string> LineStorage::Movies;
vector <string> LineStorage::Keywords;

void LineStorage::storeMovies(string line) {
	Movies.push_back(line);
}

void LineStorage::storeKeywords(string keyword) {
	Keywords.push_back(keyword);
}

string LineStorage::getMovie(int index) {
	return Movies[index];
}

string LineStorage::getKeyword(int index) {
	return Keywords[index];
}

int LineStorage::numberOfMovies() {
	return Movies.size();
}

int LineStorage::numberOfKeywords() {
	return Keywords.size();
}

void LineStorage::printMovies() {
	while (!Movies.empty()) {
		cout << Movies.back() << endl;
		Movies.pop_back();
	}
}