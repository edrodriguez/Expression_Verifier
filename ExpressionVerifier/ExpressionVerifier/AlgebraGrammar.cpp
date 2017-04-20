#include "Grammar.h"
#include "AlgebraGrammar.h"
#include <vector>
#include <iterator>
#include <algorithm>
vector<char> algebraVector;

using namespace std;


bool checkAlgDigits() {
	char validDigits[] = { '0', '1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' };
	char validOperators[] = { '+', '-', '*', '^' };
	char expression = ' ';
	int digit, oper;
	digit = oper = 0;

	for (size_t i = 0; i < algebraVector.size(); i++) {
		expression = algebraVector[i];

		if (find(begin(validOperators), end(validOperators), expression) != end(validOperators)) {
			if (expression == ('-') && (i == 0 || algebraVector[i - 1] == '('))
				continue;
			else
				oper++;
		}
		else if (find(begin(validDigits), end(validDigits), expression) != end(validDigits)) {
			digit++;
		}
		else if (expression != '(')
			return false;

		if (digit > oper + 1)
			return false;
	}

	if (digit > oper)
		return true;
	else
		return false;

}

bool AlgebraVerification(string line) {
	bool correctSyntax;
	correctSyntax = true;

	//clear things remaining in stack from previous run if any
	algebraVector.clear();

	if (MatchedParentheses(line)) {
		line.erase(remove(line.begin(), line.end(), ')'), line.end());

		for (size_t i = 0; i < line.size(); i++) {
			if (line[i] == '=') {
				correctSyntax = checkAlgDigits();
				algebraVector.clear();
			}
			else {
				algebraVector.push_back(line[i]);
			}

			if (!correctSyntax)
				return false;
		}
		correctSyntax = checkAlgDigits();
		return correctSyntax;
	}
	else
		return false;
}