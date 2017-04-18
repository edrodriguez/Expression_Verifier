////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////
#include "SymbolTable.h"

list<string> lines;

stack<string> Grammar_Stack;

list<string> Output_Queue;

const string STR_GRAMMAR = "< strings >";
const string BOOL_GRAMMAR = "< boolean >";
const string SET_GRAMMAR = "< sets >";
const string ALG_GRAMMAR = "< algebra >";
const string EXIT_GRAMMAR = "< / >";