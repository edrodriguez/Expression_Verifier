////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////
#include "BindingControl.h"
#include "SymbolTable.h"

void RunVerification() {
	bool correctSyntax = false;
	string currentLine = ""; 

	for (int i = 0; i <= lines.size(); i++) {
		currentLine = lines.front();
		lines.pop_front();

		//Check if the current line is a change of scope
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
		else {
			// Same Scope so evaluate the expression with the current scope...
			correctSyntax = IdentifyGrammarAndVerify(currentLine);
			if (correctSyntax) {
				cout << "Valid expression\n";
			}
			else {
				cout << "Invalid expression\n";
			}
		}
	}
}