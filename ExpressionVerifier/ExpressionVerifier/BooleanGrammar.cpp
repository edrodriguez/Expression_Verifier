////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////
#include "BooleanGrammar.h"
stack<char> boolStack;

bool AND(bool id1, bool id2) {
	return id1 && id2;
}

bool OR(bool id1, bool id2) {
	return id1 || id2;
}

void solveExp() {
	bool id1, result;
	if (boolStack.top == '0') {
		id1 = false;
	}
	else {
		id1 = true;
	}
	boolStack.pop();
	if (boolStack.top == '+') {
		boolStack.pop();
		result = AND(id1, boolStack.top());
	}
	else {
		boolStack.pop();
		result = OR(id1, boolStack.top());
	}
	boolStack.pop();
	boolStack.push(result);
}

bool BooleanVerification(string identity) {
	bool IndentityHolds, identifier1, identifier2;
	IndentityHolds = identifier1 = identifier2 = false;
	int index, end;
	index = end = 0;

	for (int i = 0; i < identity.length(); i++) {
		if (identity[i] == ' ' || identity[i] == '(') {
			continue;
		}
		else if (identity[i] == '=') {
			solveExp();
			IndentityHolds = IndentityHolds && boolStack.top();
			boolStack.pop();
			end = 0;
		}
		else if (identity[i] == ')') {
			solveExp();
		}
		else {
			boolStack.push(identity[i]);
			end++;
		}
	}

	return IndentityHolds;
}