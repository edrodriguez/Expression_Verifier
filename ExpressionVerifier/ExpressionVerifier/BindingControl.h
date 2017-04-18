#pragma once
////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////
#include "SymbolTable.h"
#include "Grammar.h"
/**
 * RunVerification If the read statement is one of these,
 * it will push or pop a grammar accordingly, 
 * otherwise, it will pass the line to Grammars for verification of identities. 
 * It will then return a list with the verification results.
 */
void RunVerification();