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
	char delim = ',';
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	
	cout << "**********Grammar " << tokens[1] << " Closed***************" << endl << endl;
}

void WriteVerification (string verification) {
	stringstream ss(verification);
	string item;
	vector<string> tokens;
	char delim = ';';
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}

	if (tokens[1] == "VALID") {
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

	while (!Output_Queue.empty()) {
		if (Output_Queue.front().find(EXIT_GRAMMAR) != std::string::npos) {
			WriteGrammarClose(Output_Queue.front());
			Output_Queue.pop_front();
		}
		else if (find(begin(validGrammars), end(validGrammars), Output_Queue.front()) != end(validGrammars)) {
			WriteGrammarChange(Output_Queue.front());
			Output_Queue.pop_front();
		}
		else{
			WriteVerification(Output_Queue.front());
			Output_Queue.pop_front();
		}
	}
}