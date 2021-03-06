////////////////////////////////////////////////////////////////
// SymbolTable contains constants and data structures to be
// used by the verifier machine
////////////////////////////////////////////////////////////////
#include <list>
#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

extern list<string> lines;

extern stack<string> Grammar_Stack;

extern list<string> Output_Queue;

extern const string STR_GRAMMAR;
extern const string BOOL_GRAMMAR;
extern const string SET_GRAMMAR;
extern const string ALG_GRAMMAR;
extern const string EXIT_GRAMMAR;
extern const string BINDING_GRAMMAR;
extern const string VALID;
extern const string INVALID;