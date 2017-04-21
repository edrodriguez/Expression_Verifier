#pragma once
////////////////////////////////////////////////////////////////
// IOManipulation will take care of reading the expressions 
// from the file and writing the results of the verification
// to the output device
////////////////////////////////////////////////////////////////
#include <string>
#include <vector>
using namespace std;

//Extract each line of the file indicated by filename
void ReadFile(string fileName);

void WriteGrammarChange(string grammar);

void WriteGrammarClose(string grammar);

void WriteVerification(string verification);

void WriteResults();
