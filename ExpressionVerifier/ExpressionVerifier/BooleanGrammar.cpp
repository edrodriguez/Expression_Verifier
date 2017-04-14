////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////
#include "BooleanGrammar.h"
stack<char> boolStack;

bool simplifyExp(string expression) {
	bool end_Value = false;
	string endVal = "";

	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == '*') {
			// Do something
		}
		else {
			// Do something
		}
	}

	return end_Value
}

bool BooleanVerification(string identity) {
	bool IndentityHolds, identifier;
	IndentityHolds = identifier = false;
	string expression = "";
	int index, count, num;
	index = count = num = 0;

	for (int i = 0; i < identity.length(); i++) {
		if (identity[i] == ' ') {
			continue;
		}
		else if (identity[i] = '(') {
			count++;
		}
		else if (identity[i] == '=') {
			identifier = simplifyExp(expression);
			IndentityHolds = IndentityHolds && identifier;
			expression = "";
			num = 0;
		}
		else if (identity[i] == ')') {
			count--;
		}
		else {
			expression[num] = identity[i];
			num++;
		}
	}

	return IndentityHolds;
}