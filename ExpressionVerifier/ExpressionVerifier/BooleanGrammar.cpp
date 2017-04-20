////////////////////////////////////////////////////////////////
// BooleanVerification will call different internal methods 
// that will aid with the verification of the identity. 
// Such methods would handle the different operators of this 
// grammar. The implementation of this grammar will include a 
// stack for a pushdown automata like operation. Expressions 
// would be broken down to identifiers, true or false, then 
// operations (and, or, not) will join the expressions to a 
// simple boolean.
////////////////////////////////////////////////////////////////
#include "BooleanGrammar.h"
#include "Grammar.h"
#include <iterator>
#include <algorithm>
stack<char> boolStack;

//bool checkCount (int count){
//	return count == 0;
//}

bool simplifyExp() {
	char validDigits[] = { '0', '1'};
	char validOperators[] = { '+', '*' };
	char expression = ' ';
	int digit, oper;
	digit = oper = 0;

	while (!boolStack.empty()) {
		expression = boolStack.top();
		boolStack.pop();

		if (find(begin(validOperators), end(validOperators), expression) != end(validOperators)) {
			oper++;
		}
		else if (find(begin(validDigits), end(validDigits), expression) != end(validDigits)) {
			digit++;
		}
		else
			return false;

		if (digit > oper + 1)
			return false;
	}

	if (digit > oper)
		return true;
	else
		return false;
}

bool BooleanVerification(string line) {
	bool correctSyntax;
	correctSyntax = true;

	if (MatchedParentheses(line)) {
		line.erase(remove(line.begin(), line.end(), '('), line.end());
		line.erase(remove(line.begin(), line.end(), ')'), line.end());

		for (size_t i = 0; i < line.size(); i++) {
			if (line[i] == '=') {
				correctSyntax = simplifyExp();
			}
			else {
				boolStack.push(line[i]);
			}

			if (!correctSyntax)
				return false;
		}
		correctSyntax = simplifyExp();
		return correctSyntax;
	}
	else
		return false;

	//bool IndentityHolds, identifier;
	//IndentityHolds = identifier = true;
	//int index, count, num;
	//index = count = num = 0;

	//for (int i = 0; i < identity.length(); i++) {
	//	//cout << endl << identity[i];
	//	if (identity[i] == '(') {
	//		count++;
	//	}
	//	else if (identity[i] == '=') {
	//		identifier = checkCount(count);
	//		IndentityHolds = IndentityHolds && identifier;
	//		identifier = simplifyExp(num);
	//		IndentityHolds = IndentityHolds && identifier;
	//		count = num = 0;
	//	}
	//	else if (identity[i] == ')') {
	//		count--;
	//	}
	//	else {
	//		boolStack.push(identity[i]);
	//		num++;
	//	}
	//}

	//identifier = checkCount(count);
	//IndentityHolds = IndentityHolds && identifier;
	//identifier = simplifyExp(num);
	//IndentityHolds = IndentityHolds && identifier;

	/*return IndentityHolds;*/
}