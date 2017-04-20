////////////////////////////////////////////////////////////////
// IdentifyGrammarAndVerify will check the current grammar by 
// checking the top of the Grammar_Stack contained in the 
// Symbol_Table.
////////////////////////////////////////////////////////////////
#include "Grammar.h"
#include "SymbolTable.h"
#include "BooleanGrammar.h"
#include "StringsGrammar.h"
#include "AlgebraGrammar.h"
#include "SetsGrammar.h"

bool IdentifyGrammarAndVerify(string line) {
	string expression = "";
	bool IdentityHolds = false;
	 /**
	 * The first thing is to check the scope
	 */
	if (Grammar_Stack.top() == STR_GRAMMAR) {
		IdentityHolds = StringsVerification(line);
	}
	else if (Grammar_Stack.top() == ALG_GRAMMAR) {
		 IdentityHolds = AlgebraVerification(line);
	}
	else if (Grammar_Stack.top() == SET_GRAMMAR) {
		IdentityHolds = SetsVerification(line);
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

bool MatchedParentheses(string line) {
	int openCount, closeCount;
	openCount = closeCount = 0;

	for (size_t i = 0; i < line.size(); i++) {
		if (line[i] == '(') {
			openCount++;
		}
		else if (line[i] == ')') {
			closeCount++;
		}
		else if (line[i] == '=') {
			if (openCount != closeCount)
				return false;
			openCount = closeCount = 0;
		}

		if (closeCount > openCount)
			return false;
	}

	return true;
}