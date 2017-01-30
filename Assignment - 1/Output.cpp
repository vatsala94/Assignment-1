#include "Output.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//Prints the movies on the CMD window 
void Output::printMovies(Alphabetizer A1) {
	vector <string> sortedLines = A1.getSortedLines();
	cout << endl << "The output is: " << endl;
	cout << endl << "**************************************************" << endl << endl;
	for (int i = 0;i < sortedLines.size();i++) {
		cout << sortedLines[i] << endl << endl;
	}
	cout << "**************************************************" << endl << endl;
}

//Stores the output in a text file by the name of "Output.txt"
void Output::storeOutputinFile(Alphabetizer A1) {
	string fileName = "Output.txt";
	vector <string> sortedLines = A1.getSortedLines();
	ofstream myFile;
	myFile.open(fileName);
	for (int i = 0;i < sortedLines.size();i++) {
		myFile << sortedLines[i] << endl;
	}
	myFile.close();
}