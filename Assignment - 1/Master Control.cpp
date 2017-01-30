#include "Master Control.h"
#include <iostream>
#include <string>
using namespace std;

const string MasterControl::MESSAGE_WELCOME = "KWIC Index System";
const string MasterControl::MESSAGE_INPUT_MOVIES = "Enter name of the text file containing the movies (FileName.txt): ";
const string MasterControl::MESSAGE_INPUT_KeyWordsToIgnore = "Enter name of the text file containing the keywords to ignore (FileName.txt): ";
const string MasterControl::MESSAGE_ERROR_INPUT = "Incorrect file name. Please enter the file name again. ";
const string MasterControl::MESSAGE_BYE = "The solution is stored in 'Output.txt'.\n\nGoodbye!\n\n";
string MasterControl::movieFileName;
string MasterControl::keywordsFileName;

void MasterControl::printWelcomeMsg() {
	cout << endl << MESSAGE_WELCOME << endl << endl;
}

//While reading the text file, it checks if the file empty or the name is incorrect. If so, it asks for user input again.
void MasterControl::getMoviesFile() {
	cout << MESSAGE_INPUT_MOVIES << endl;
	getline(cin, movieFileName);
	bool validMovies;
	validMovies = input.readMovies(movieFileName, movies);
	while (movieFileName.empty() || validMovies==false) {
		cout << MESSAGE_ERROR_INPUT << endl;
		getline(cin, movieFileName);
		validMovies = input.readMovies(movieFileName, movies);
	}
}

//While reading the text file, it checks if the file empty or the name is incorrect. If so, it asks for user input again.
void MasterControl::getKeywordsFile() {
	cout << endl << endl << MESSAGE_INPUT_KeyWordsToIgnore << endl;
	getline(cin, keywordsFileName);
	bool validKeywords = input.readKeywordsToIgnore(keywordsFileName, movies);
	while (keywordsFileName.empty() || validKeywords ==false) {
		cout << MESSAGE_ERROR_INPUT << endl;
		getline(cin, keywordsFileName);
		validKeywords = input.readKeywordsToIgnore(keywordsFileName, movies);
	}
}

void MasterControl::doCircularShift() {
	shift.setup(movies);
}

void MasterControl::doSorting() {
	alpha.sortMovies(shift);
}

void MasterControl::displayOutput() {
	display.printMovies(alpha);
}

void MasterControl::storeOutput() {
	display.storeOutputinFile(alpha);
}

void MasterControl::displayExitMsg() {
	cout << endl << MESSAGE_BYE << endl;
}

void main() {
	MasterControl control;
	control.printWelcomeMsg();
	control.getMoviesFile();
	control.getKeywordsFile();
	control.doCircularShift();
	control.doSorting();
	control.displayOutput();
	control.storeOutput();
	control.displayExitMsg();
	system("PAUSE");
}



