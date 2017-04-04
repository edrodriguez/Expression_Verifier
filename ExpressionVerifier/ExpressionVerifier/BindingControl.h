#pragma once
////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////
#include <list>
#include <string>
#include "SymbolTable.h"
using namespace std;

/**
 * RunVerification If the read statement is one of these,
 * it will push or pop a grammar accordingly, 
 * otherwise, it will pass the line to Grammars for verification of identities. 
 * It will then return a list with the verification results.
 */
void RunVerification(list<string> lines);