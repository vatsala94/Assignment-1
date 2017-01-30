#ifndef Input_H
#define Input_H

#include <string>
#include "Line Storage.h"
using namespace std;

class Input {

public:
	bool readMovies(string, LineStorage);
	bool readKeywordsToIgnore(string, LineStorage);
};

#endif
