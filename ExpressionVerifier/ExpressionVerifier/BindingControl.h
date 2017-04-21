#pragma once
////////////////////////////////////////////////////////////////
// BindingControl checks the statements for valid format, 
// it will push or pop a grammar accordingly, otherwise, it 
// will pass the line to Grammars for verification of 
// identities.
////////////////////////////////////////////////////////////////
#include <string>

using namespace std;

void WriteValidity(string line, string grammar, string validity);

void RunVerification();