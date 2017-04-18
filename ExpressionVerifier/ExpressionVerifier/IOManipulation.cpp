////////////////////////////////////////////////////////////////
// Extract each line of the file indicated by filename and
// write each line as an entry in the vector instructions
// ReadFile will scan the file indicated in the path and will 
// create a list populated with each line of the file in 
// separate entries. WriteResults will write each line that 
// was to be verified as an identity along with the scope 
// that was used for verification and the result of the 
// verification
////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <vector>
#include "SymbolTable.h"
using namespace std;

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

void WriteResults(string fileName) {
	ofstream outputFile;
	string line;
	fileName.append(".out");
	outputFile.open(fileName);
	if (outputFile.good()) {
		while (!Output_Queue.empty()) {
			outputFile << Output_Queue.front();
			Output_Queue.pop_front();
		}
		cout << "Successful operation of interpreter. Check results in " << fileName << endl;
	}
	else
		cout << "Could not write to output file." << endl;

	outputFile.close();
}