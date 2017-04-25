////////////////////////////////////////////////////////////////
// BindingControl checks the statements for valid format, 
// it will push or pop a grammar accordingly, otherwise, it 
// will pass the line to Grammars for verification of 
// identities.
////////////////////////////////////////////////////////////////
#include "BindingControl.h"
#include "Grammar.h"
#include "SymbolTable.h"
#include <iterator>
#include <algorithm> 
#include <sstream>

void WriteValidity(string line, string grammar, string validity) {
	string verification = line;
	verification += ":";
	verification += validity;
	verification += ":";
	verification += grammar;
	Output_Queue.push_back(verification);
}

void RunVerification() {
	bool linePopped = false;
	bool correctSyntax = false;
	bool endSemi = false;
	string currentLine = ""; 

	while (!lines.empty()) {
		linePopped = false;
		endSemi = false;
		currentLine = lines.front();
		//remove spaces
		currentLine.erase(remove_if(currentLine.begin(), currentLine.end(), isspace), currentLine.end());

		// Check if the current line is a change of scope
		if (currentLine.find("<") != std::string::npos) {

			//check that there are not a start and an end with anything in between
			if (lines.size() > 1) {
				vector<string> validGrammars = { ALG_GRAMMAR, BOOL_GRAMMAR, SET_GRAMMAR, STR_GRAMMAR };
				if (find(begin(validGrammars), end(validGrammars), currentLine) != end(validGrammars)){
					string nextLine = *(++lines.begin());
					nextLine.erase(remove_if(nextLine.begin(), nextLine.end(), isspace), nextLine.end());
					if (nextLine.find(EXIT_GRAMMAR) != std::string::npos) {
						string jointLines = currentLine + nextLine;
						WriteValidity(jointLines, BINDING_GRAMMAR, INVALID);
						linePopped = true;
						lines.pop_front();
						lines.pop_front();
						continue;
					}
				}
			}

			if (currentLine.find(STR_GRAMMAR) != std::string::npos) {
				// Change to <strings> grammar
				Grammar_Stack.push(STR_GRAMMAR);
				Output_Queue.push_back(STR_GRAMMAR);
			}
			else if (currentLine.find(BOOL_GRAMMAR) != std::string::npos) {
				// Change to <boolean> grammar
				Grammar_Stack.push(BOOL_GRAMMAR);
				Output_Queue.push_back(BOOL_GRAMMAR);
			}
			else if (currentLine.find(SET_GRAMMAR) != std::string::npos) {
				// Change to <sets> grammar
				Grammar_Stack.push(SET_GRAMMAR);
				Output_Queue.push_back(SET_GRAMMAR);
			}
			else if (currentLine.find(ALG_GRAMMAR) != std::string::npos) {
				// Change to <algebra> grammar
				Grammar_Stack.push(ALG_GRAMMAR);
				Output_Queue.push_back(ALG_GRAMMAR);
			}
			else if (currentLine.find(EXIT_GRAMMAR) != std::string::npos) {
				// Cross out the top of the Grammar_Stack
				if (!Grammar_Stack.empty()) {
					string close = EXIT_GRAMMAR;
					close += ":";
					close += Grammar_Stack.top();
					Output_Queue.push_back(close);
					Grammar_Stack.pop();
				}
				else {
					WriteValidity(currentLine, BINDING_GRAMMAR, INVALID);
				}
			}
			else
				WriteValidity(currentLine, BINDING_GRAMMAR, INVALID);
		}
		else { // line is not scope change so it must be an expression

			//check for semicolons at the end
			if (currentLine[currentLine.size() - 1] == ';') {
				endSemi = true;
				if (find(begin(*(++lines.begin())), end(*(++lines.begin())), '<') != end(*(++lines.begin()))) {
					//if semicolon at the end and next line is not an expression then it is invalid
					WriteValidity(currentLine, BINDING_GRAMMAR, INVALID);
					lines.pop_front();
					linePopped = true;
					continue;
				}
				else { //just remove the semicolon and evaluate
					//currentLine.pop_back();
				}
			}
			else { //if no semicolon at the end and if next line is not a scope change then it is invalid
				string jointLines = currentLine;
				int countOfLines = 1;

				for (std::list<string>::const_iterator it = ++lines.begin(), end = lines.end(); it != end; ++it) {
					string nextLine = *(it);
					nextLine.erase(remove_if(nextLine.begin(), nextLine.end(), isspace), nextLine.end());

					if (find(nextLine.begin(), nextLine.end(), '<') == nextLine.end()) {
						countOfLines++;
						jointLines += nextLine;
					}
					else
						break;
				}

				if (countOfLines > 1) {
					WriteValidity(jointLines, BINDING_GRAMMAR, INVALID);
					for (int i = 0; i < countOfLines; i++) {
						lines.pop_front();
					}
					linePopped = true;
					continue;
				}
			}

			//search for middle semicolons
			auto foundIt = find(begin(currentLine), end(currentLine), ';');
			if (foundIt != end(currentLine)) {
				//split the string
				stringstream ss(currentLine);
				string item;
				vector<string> tokens;
				char delim = ';';
				while (getline(ss, item, delim)) {
					tokens.push_back(item);
				}

				if (tokens.size() > 0) {
					currentLine = tokens[0];
					lines.pop_front();
					linePopped = true;

					for (size_t i = tokens.size() - 1; i >= 1; i--) {
						if ((i == tokens.size() - 1 && endSemi) || i != tokens.size() - 1)
							tokens[i] += ";";
						lines.push_front(tokens[i]);
					}
				}

			}

			//evaluate correctness of current expression
			correctSyntax = IdentifyGrammarAndVerify(currentLine);
			if (correctSyntax) {
				WriteValidity(currentLine, Grammar_Stack.top(), VALID);
			}
			else {
				WriteValidity(currentLine, Grammar_Stack.top(), INVALID);
			}
			
		}
		if (!linePopped)
			lines.pop_front();
	}
}