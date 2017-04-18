////////////////////////////////////////////////////////////////
// IdentifyGrammarAndVerify will check the current grammar by 
// checking the top of the Grammar_Stack contained in the 
// Symbol_Table.
////////////////////////////////////////////////////////////////
#include "Grammar.h"
#include "SymbolTable.h"

bool IdentifyGrammarAndVerify(string line) {
	string expression = "";
	bool IdentityHolds = false;
	 /**
	 * The first thing is to check the scope
	 */
	if (Grammar_Stack.top() == STR_GRAMMAR) {
		// IdentityHolds = StringsVerification(line);
	}
	else if (Grammar_Stack.top() == ALG_GRAMMAR) {
		// IdentityHolds = AlgebraVerification(line);
	}
	else if (Grammar_Stack.top() == SET_GRAMMAR) {
		//IdentityHolds = SetsVerification(line);
	}
	else if (Grammar_Stack.top() == BOOL_GRAMMAR) {
		IdentityHolds = BooleanVerification(line);
	}
	else {
		/**
		* There was something wrong with the string
		*/
		return false;
	}
	return IdentityHolds;
}