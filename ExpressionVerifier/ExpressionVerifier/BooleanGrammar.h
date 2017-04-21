#pragma once
////////////////////////////////////////////////////////////////
// BooleanVerification will call different internal methods 
// that will aid with the verification of the identity. 
// Such methods would handle the different operators of this 
// grammar. The implementation of this grammar will include a 
// stack for a pushdown automata like operation. Expressions 
// would be broken down to identifiers, true or false, then 
// operations (and, or, not) will join the expressions to a 
// simple boolean.
////////////////////////////////////////////////////////////////
#include <list>
#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

bool BooleanVerification(string identity);

bool simplifyExp();