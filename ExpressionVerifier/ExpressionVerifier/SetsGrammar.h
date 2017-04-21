#pragma once
////////////////////////////////////////////////////////////////
// SetsGrammar will call different internal methods 
// that will aid with the verification of the expression. 
// Such methods would handle the different operators of this 
// grammar.
////////////////////////////////////////////////////////////////
#include <string>

using namespace std;

bool checkSetsOperations();

bool checkInsideOfBraces(size_t &currentIndex);

bool checkBraces();

bool checkParentheses();

bool SetsVerification(string line);
