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
		}
		else if (currentLine.find(BOOL_GRAMMAR) != std::string::npos) {
			// Change to <boolean> grammar
			Grammar_Stack.push(BOOL_GRAMMAR);
		}
		else if (currentLine.find(SET_GRAMMAR) != std::string::npos) {
			// Change to <sets> grammar
			Grammar_Stack.push(SET_GRAMMAR);
		}
		else if (currentLine.find(ALG_GRAMMAR) != std::string::npos) {
			// Change to <algebra> grammar
			Grammar_Stack.push(ALG_GRAMMAR);
		}
		else if (currentLine.find(EXIT_GRAMMAR) != std::string::npos) {
			// Cross out the top of the Grammar_Stack
			Grammar_Stack.pop();
		}
		else { // Same Scope so evaluate the expression with the current scope...
			correctSyntax = IdentifyGrammarAndVerify(currentLine);
			if (correctSyntax) {
				cout << "-\"" << currentLine << "\"" << " is a VALID expression for the " << Grammar_Stack.top() << " grammar" << endl;
				cout << endl;
				Output_Queue.push_back("Valid");
			}
			else {
				cout << "-\"" << currentLine << "\"" << " is an INVALID expression for the " << Grammar_Stack.top() << " grammar" << endl;
				cout << endl;
				Output_Queue.push_back("Invalid");
			}
		}
		lines.pop_front();
	}
}