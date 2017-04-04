#include "Grammar.h"
#include "SymbolTable.h"
using namespace std;

bool IdentifyGrammarAndVerify(string line) {
	bool IdentityHolds = false;
	string expression = "";
	for (int i = 0; i < line.size(); i++) {
		/**
		*  Boolean will be set equal to the grammar we call from this statment
		*/
		if (line == "string") {
			// IdentityHolds = stringGrammar();
		}
		else if (line == "algebra") {
			// IdentityHolds = algebraGrammar();
		}
		else if (line == "set") {
			// IdentityHolds = setGrammar();
		}
		else if (line == "boolean") {
			// IdentityHolds = BooleanVerification():
		}
		else {
			/**
			* There was something wrong with the string
			*/
		}
	/**
	 * The first thing that need to be is parse the line
	 /
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == '=') {
			expression = "";
		}
		else {

		}
	}*/
	return IdentityHolds;
}