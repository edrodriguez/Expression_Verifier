////////////////////////////////////////////////////////////////
// RunVerification If the read statement is one of these, 
// it will push or pop a grammar accordingly, otherwise, it 
// will pass the line to Grammars for verification of 
// identities. It will then return a list with the 
// verification results.
////////////////////////////////////////////////////////////////
#include "BindingControl.h"
#include "Grammar.h"
#include "SymbolTable.h"
#include <iterator>
#include <algorithm> 

void RunVerification() {
	bool correctSyntax = false;
	string currentLine = ""; 

	while (!lines.empty()) {
		currentLine = lines.front();
		//remove spaces
		currentLine.erase(remove_if(currentLine.begin(), currentLine.end(), isspace), currentLine.end());

		// Check if the current line is a change of scope
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
			string close = EXIT_GRAMMAR;
			close += ",";
			close += Grammar_Stack.top();
			Output_Queue.push_back(close);
			Grammar_Stack.pop();
		}
		else { // Same Scope so evaluate the expression with the current scope...
			correctSyntax = IdentifyGrammarAndVerify(currentLine);
			if (correctSyntax) {
				string verification = currentLine;
				verification += ";";
				verification += "VALID";
				verification += ";";
				verification += Grammar_Stack.top();
				Output_Queue.push_back(verification);
			}
			else {
				string verification = currentLine;
				verification += ";";
				verification += "INVALID";
				verification += ";";
				verification += Grammar_Stack.top();
				Output_Queue.push_back(verification);
			}
		}
		lines.pop_front();
	}
}