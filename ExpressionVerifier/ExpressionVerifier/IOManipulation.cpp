////////////////////////////////////////////////////////////////
// IOManipulation will take care of reading the expressions 
// from the file and writing the results of the verification
// to the output device
////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
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

void WriteGrammarChange(string grammar) {
	cout << "**********Grammar " << grammar << " Initialized**********" << endl << endl;
}

void WriteGrammarClose(string grammar) {
	stringstream ss(grammar);
	string item;
	vector<string> tokens;
	char delim = ':';
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	
	cout << "**********Grammar " << tokens[1] << " Closed***************" << endl << endl;
}

void WriteVerification (string verification) {
	stringstream ss(verification);
	string item;
	vector<string> tokens;
	char delim = ':';
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}

	if (tokens[1] == VALID) {
		cout << "-\"" << tokens[0] << "\"" << " is a VALID expression for the " << tokens[2] << " grammar" << endl;
		cout << endl;
	}
	else {
		cout << "-\"" << tokens[0] << "\"" << " is an INVALID expression for the " << tokens[2] << " grammar" << endl;
		cout << endl;
	}
}

void WriteResults() {
	string line;
	vector<string> validGrammars = { ALG_GRAMMAR, BOOL_GRAMMAR, SET_GRAMMAR, STR_GRAMMAR };
	vector<string> validity = { VALID, INVALID };

	while (!Output_Queue.empty()) {
		if (Output_Queue.front().find(VALID) != std::string::npos || Output_Queue.front().find(INVALID) != std::string::npos) {
			WriteVerification(Output_Queue.front());
			Output_Queue.pop_front();
		}
		else if (find(begin(validGrammars), end(validGrammars), Output_Queue.front()) != end(validGrammars)) {
			WriteGrammarChange(Output_Queue.front());
			Output_Queue.pop_front();
		}
		else if (Output_Queue.front().find(EXIT_GRAMMAR) != std::string::npos) {
			WriteGrammarClose(Output_Queue.front());
			Output_Queue.pop_front();
		}
	}
}