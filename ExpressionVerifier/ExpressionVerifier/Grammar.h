////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////
#include <string>

using namespace std;

/**
 * IdentifyGrammarAndVerify will take in a line which will represent 
 * an identity and will check what is the current grammar scope. 
 * After this, it will pass the line to the respective sub module 
 * corresponding to the current grammar for performing the actual verification.
 */
bool IdentifyGrammarAndVerify(string line);

bool MatchedParentheses(string line);