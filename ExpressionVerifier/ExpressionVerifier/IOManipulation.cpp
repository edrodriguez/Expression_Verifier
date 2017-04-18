////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <vector>
#include "SymbolTable.h"
using namespace std;

//Extract each line of the file indicated by filename and
//write each line as an entry in the vector instructions
void ReadFile(string fileName) {
	ifstream inputFile;
	string line;

	inputFile.open(fileName);

	if (inputFile.good()) {
		while (!inputFile.eof()) {
			getline(inputFile, line);
			//Ignore empty lines
			if (line != "")
				lines.push_back(line);
		}
	}
	else
		cout << "Cannot read input file." << endl;

	inputFile.close();
}