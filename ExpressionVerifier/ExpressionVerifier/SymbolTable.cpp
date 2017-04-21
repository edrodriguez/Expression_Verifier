////////////////////////////////////////////////////////////////
// SymbolTable contains constants and data structures to be
// used by the verifier machine
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
// The Reference to variables:
//	lines		  -- hold all the lines contained in the file 
//					 in sequential order.
//	Grammar_Stack -- a stack that will hold the grammars as 
//				     they appear on the input. It will push a 
//					 grammar when we run into an opening 
//					 statement and pop it when we read a 
//					 closing statement.
//	Output_Queue  -- hold the Strings that will be passed 
//					 to the output device.
////////////////////////////////////////////////////////////////
#include "SymbolTable.h"

list<string> lines;

stack<string> Grammar_Stack;

list<string> Output_Queue;

const string STR_GRAMMAR = "<strings>";
const string BOOL_GRAMMAR = "<boolean>";
const string SET_GRAMMAR = "<sets>";
const string ALG_GRAMMAR = "<algebra>";
const string EXIT_GRAMMAR = "</>";
const string BINDING_GRAMMAR = "<binding_control>";
const string VALID = "VALID";
const string INVALID = "INVALID";