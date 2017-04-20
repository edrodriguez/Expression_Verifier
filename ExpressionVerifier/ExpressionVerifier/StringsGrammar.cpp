#include "Grammar.h"
#include "StringsGrammar.h"
#include <stack>
#include <iterator>
#include <algorithm>
stack<char> stringStack;

using namespace std;


bool checkChars() {
	char validDigits[] = {'0', '1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'};
	char validOperators[] = { '+', '*'};
	char expression = ' ';
	int digit, oper;
	digit = oper = 0;

	while (!stringStack.empty()){
		expression = stringStack.top();
		stringStack.pop();

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

bool StringsVerification(string line) {
	bool correctSyntax;
	correctSyntax = true;

	//clear things remaining in stack from previous run if any
	while (!stringStack.empty())
		stringStack.pop();

	if (MatchedParentheses(line)) {
		line.erase(remove(line.begin(), line.end(), '('), line.end());
		line.erase(remove(line.begin(), line.end(), ')'), line.end());

		for (size_t i = 0; i < line.size(); i++) {
			if (line[i] == '=') {
				correctSyntax = checkChars();
			}
			else {
				stringStack.push(line[i]);
			}

			if (!correctSyntax)
				return false;
		}
		correctSyntax = checkChars();
		return correctSyntax;
	}
	else
		return false;
}
