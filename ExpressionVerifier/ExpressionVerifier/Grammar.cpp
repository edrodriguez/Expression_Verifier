////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////
#include "Grammar.h"

bool IdentifyGrammarAndVerify(string line) {
	string expression = "";
	bool IdentityHolds = false;
	string str = "< strings >";
	string boo = "< boolean >";
	string set = "< sets >";
	string alg = "< algebra >";
	 /**
	 * The first thing is to check the scope
	 */
	if (Grammar_Stack.top() == str) {
		// return StringsVerification(line);
	}
	else if (Grammar_Stack.top() == alg) {
		// return AlgebraVerification(line);
	}
	else if (Grammar_Stack.top() == set) {
		// return SetsVerification(line);
	}
	else if (Grammar_Stack.top() == boo) {
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