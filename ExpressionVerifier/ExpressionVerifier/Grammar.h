#pragma once
////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////
#include <list>
#include <string>
#include <vector>
#include <iostream>
#include "SymbolTable.h"
using namespace std;

/**
 * IdentifyGrammarAndVerify will take in a line which will represent 
 * an identity and will check what is the current grammar scope. 
 * After this, it will pass the line to the respective sub module 
 * corresponding to the current grammar for performing the actual verification.
 */
bool IdentifyGrammarAndVerify(string line) { bool IndentityHolds; };

class BooleanGrammar {
public:
	/**
	 *  BooleanVerification will be called to verify that a given identity holds true. 
	 *  It will take in a string and return a bool indicating the result of the verification.
	 */
	bool BooleanVerification(string identity) { bool IndentityHolds; };
};