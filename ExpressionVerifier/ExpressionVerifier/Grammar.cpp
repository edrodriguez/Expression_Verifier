////////////////////////////////////////////////////////////////
//
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
		// return StringsVerification(line);
	}
	else if (Grammar_Stack.top() == ALG_GRAMMAR) {
		// return AlgebraVerification(line);
	}
	else if (Grammar_Stack.top() == SET_GRAMMAR) {
		// return SetsVerification(line);
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