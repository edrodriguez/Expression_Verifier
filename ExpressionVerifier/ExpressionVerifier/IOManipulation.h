#pragma once
////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////
#include <string>
#include <vector>
using namespace std;

//Extract each line of the file indicated by filename
void ReadFile(string fileName);

void WriteGrammarChange(string grammar);

void WriteGrammarClose(string grammar);

void WriteVerification(string verification);

//Write the contents of the Output queue to the file indicated in filename
void WriteResults();
