#include "Grammar.h"
#include "SetsGrammar.h"
#include <vector>
#include <iterator>
#include <algorithm>
vector<char> setsVector;

using namespace std;


bool checkSetsOperations() {
	char validDigits[] = { '0', '1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' };
	char validLetters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
		'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	char validDelimiters[] = { '(', ')', '{', '}', ','};
	char validOperators[] = { '+', '*' };
	char expression = ' ';

	for (size_t i = 0; i < setsVector.size(); i++) {
		expression = setsVector[i];

		if (find(begin(validOperators), end(validOperators), expression) != end(validOperators)) {
			if (i != 0 && (setsVector[i - 1] == ')' || setsVector[i - 1] == '}')) {
				continue;
			}
			else if (i < setsVector.size() - 1 && i != 0 && (setsVector[i + 1] == '(' || setsVector[i + 1] == '{')) {
				continue;
			}
			else
				return false;
		}
		else if (find(begin(validDigits), end(validDigits), expression) != end(validDigits)) {
			continue;
		}
		else if (find(begin(validLetters), end(validLetters), expression) != end(validLetters)) {
			continue;
		}
		else if (find(begin(validDelimiters), end(validDelimiters), expression) != end(validDelimiters)) {
			continue;
		}
		else
			return false;
	}

	return true;

}

bool checkInsideOfBraces(size_t &currentIndex) {
	char expression = ' ';
	char validDigits[] = { '0', '1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' };
	char validLetters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
		'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	char validOperator = ',';
	int digit, oper;
	digit = oper = 0;

	for (size_t i = currentIndex + 1; i < setsVector.size(); i++) {
		expression = setsVector[i];
		if (expression == '}') {
			currentIndex = i;
			break;
		}

		if (expression == validOperator) {
			oper++;
		}
		else if ((find(begin(validDigits), end(validDigits), expression) != end(validDigits)) || 
			(find(begin(validLetters), end(validLetters), expression) != end(validLetters))) {
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

bool checkBraces() {
	char expression = ' ';
	int openCount, closeCount;
	openCount = closeCount = 0;

	for (size_t i = 0; i < setsVector.size(); i++) {
		expression = setsVector[i];
		if (expression == '{') {
			openCount++;
			if (!checkInsideOfBraces(i)) {
				return false;
			}
			if (setsVector[i] == '}') {
				closeCount++;
			}
		}
		else if ((expression == '}'))
			closeCount++;

		if (closeCount > openCount)
			return false;
	}

	if (openCount != closeCount)
		return false;
	else
		return true;

}

bool checkParentheses() {
	int openCount, closeCount;
	openCount = closeCount = 0;
	char expression;

	for (size_t i = 0; i < setsVector.size(); i++) {
		expression = setsVector[i];
		if (expression == '(') {
			openCount++;
		}
		else if (expression == ')') {
			closeCount++;
		}

		if (closeCount > openCount)
			return false;
	}
	if (openCount != closeCount)
		return false;
	else
		return true;
}

bool SetsVerification(string line) {
	bool correctSyntax;
	correctSyntax = true;

	//clear things remaining in stack from previous run if any
	setsVector.clear();

	for (size_t i = 0; i < line.size(); i++) {
		if (line[i] == '=') {
			correctSyntax = checkBraces();
			if (!correctSyntax)
				return false;
			correctSyntax = checkParentheses();
			if (!correctSyntax)
				return false;

			correctSyntax = checkSetsOperations();
			setsVector.clear();
		}
		else {
			setsVector.push_back(line[i]);
		}

		if (!correctSyntax)
			return false;
	}
	correctSyntax = checkBraces();
	if (!correctSyntax)
		return false;
	correctSyntax = checkParentheses();
	if (!correctSyntax)
		return false;

	correctSyntax = checkSetsOperations();

	return correctSyntax;
}