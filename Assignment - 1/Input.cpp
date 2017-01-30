#include "Input.h"
#include <iostream>
#include <fstream>

using namespace std;

//Reads the words to ignore that are stored in the file and sends them to Line Storage to store. If the file is unable to open(incorrect file name or the file is empty), it sends a false message to the Master Control. The master control then handles this exception.
bool Input::readKeywordsToIgnore(string keywordsFileName, LineStorage L1) {
	ifstream File1(keywordsFileName);
	string keywords;
	if (File1.peek() == std::ifstream::traits_type::eof()) {
		return false;
	}
	else {
		while (!File1.eof()) {
			getline(File1, keywords);
			if (!keywords.empty()) {
				L1.storeKeywords(keywords);
			}
		}
		return true;
	}
	File1.close();
}

//Reads the movies that are stored in the file and sends them to Line Storage to store. If the file is unable to open(incorrect file name or the file is empty), it sends a false message to the Master Control. The master control then handles this exception.
bool Input::readMovies(string fileName, LineStorage L1) {
	ifstream myFile(fileName);
	string line;
	if (myFile.peek() == std::ifstream::traits_type::eof()) {
		return false;
	}
	else {
		while (!myFile.eof()) {
			getline(myFile, line);
			if (!line.empty()) {
				L1.storeMovies(line);
			}
		}
	}
	myFile.close();
}