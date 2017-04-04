#include <vector>
#include <iostream>
#include <string>
#include "IOManipulation.h"
#include "BindingControl.h"

using namespace std;

int main(int argc, char* argv[])
{
	//Check for input parameters
	if (argv[1] != nullptr)
	{
		string filename = argv[1];

		ReadFile(filename);

		RunVerification();

	}
	else
		cout << "Error running the Verifier. You need to provide a source file." << endl;
	return 0;
}