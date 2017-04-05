////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////
#include "Grammar.h"

bool IdentifyGrammarAndVerify(string line) {
	string expression = "";
	bool IdentityHolds;
	 /**
	 * The first thing is to check the scope
	 */
	if (Grammar_Stack.top() == "strings") {
		// return StringsVerification(line);
	}
	else if (Grammar_Stack.top() == "algebra") {
		// return AlgebraVerification(line);
	}
	else if (Grammar_Stack.top() == "sets") {
		// return SetsVerification(line);
	}
	else if (Grammar_Stack.top() == "boolean") {
		return BooleanVerification(line);
	}
	else {
		/**
		* There was something wrong with the string
		*/
		return false;
	}
}