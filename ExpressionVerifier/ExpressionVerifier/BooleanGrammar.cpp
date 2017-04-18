////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////
#include "BooleanGrammar.h"
stack<char> boolStack;

bool checkCount (int count){
	return count == 0;
}

bool simplifyExp(int end) {
	char expression = ' ';
	int a, b;
	a = b = 0;

	for (int i = 0; i < end; i++) {
		expression = boolStack.top();
		boolStack.pop();
		if (expression == '*') {
			b++;
		}
		else if (expression == '+') {
			b++;
		}
		else if (expression == '0') {
			a++;
		}
		else if (expression == '1') {
			a++;
		}
	}

	if (a > b) {
		return true;
	}
	else {
		return false;
	}
}

bool BooleanVerification(string identity) {
	bool IndentityHolds, identifier;
	IndentityHolds = identifier = true;
	int index, count, num;
	index = count = num = 0;

	for (int i = 0; i < identity.length(); i++) {
		//cout << endl << identity[i];
		if (identity[i] == '(') {
			count++;
		}
		else if (identity[i] == '=') {
			identifier = checkCount(count);
			IndentityHolds = IndentityHolds && identifier;
			identifier = simplifyExp(num);
			IndentityHolds = IndentityHolds && identifier;
			count = num = 0;
		}
		else if (identity[i] == ')') {
			count--;
		}
		else {
			boolStack.push(identity[i]);
			num++;
		}
	}

	identifier = checkCount(count);
	IndentityHolds = IndentityHolds && identifier;
	identifier = simplifyExp(num);
	IndentityHolds = IndentityHolds && identifier;

	return IndentityHolds;
}