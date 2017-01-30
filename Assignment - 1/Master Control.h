#ifndef Master_H
#define Master_H

#include <string>
#include "Line Storage.h"
#include "Input.h"
#include "Circular Shifter.h"
#include "Alphabetizer.h"
#include "Output.h"
using namespace std;

class MasterControl {

private:
	static string movieFileName;
	static string keywordsFileName;
	static const string MESSAGE_WELCOME;
	static const string MESSAGE_INPUT_MOVIES;
	static const string MESSAGE_INPUT_KeyWordsToIgnore;
	static const string MESSAGE_ERROR_INPUT;
	static const string MESSAGE_BYE;
	Input input;
	LineStorage movies;
	CircularShifter shift;
	Alphabetizer alpha;
	Output display;


public:
	void printWelcomeMsg();
	void getMoviesFile();
	void getKeywordsFile();
	void doCircularShift();
	void doSorting();
	void displayOutput();
	void storeOutput();
	void displayExitMsg();

};

#endif

