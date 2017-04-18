////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////
#include "BindingControl.h"

void RunVerification() {
	bool identityHolds = false;
	stack<string> scope;
	string currentLine = ""; 
	string str  = "< strings >";
	string boo  = "< boolean >";
	string set	= "< sets >";
	string alg	= "< algebra >";
	string ext	= "< / >";

	for (int i = 0; i <= lines.size(); i++) {
		currentLine = lines.front();
		lines.pop_front();
		if (currentLine.find(str) != std::string::npos) {
			// Change to <strings> grammer
			Grammar_Stack.push(str);
		}
		else if (currentLine.find(boo) != std::string::npos) {
			// Change to <boolean> grammer
			Grammar_Stack.push(boo);
		}
		else if (currentLine.find(set) != std::string::npos) {
			// Change to <sets> grammer
			Grammar_Stack.push(set);
		}
		else if (currentLine.find(alg) != std::string::npos) {
			// Change to <algebra> grammer
			Grammar_Stack.push(alg);
		}
		else if (currentLine.find(ext) != std::string::npos) {
			// Cross out the top of the Grammar_Stack
			Grammar_Stack.pop();
		}
		else {
			// Same Scope continue...
			identityHolds = IdentifyGrammarAndVerify(currentLine);
			if (identityHolds) {
				cout << "Valid expression\n";
			}
			else {
				cout << "Invalid expression\n";
			}
		}
	}
}