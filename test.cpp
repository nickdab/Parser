#include <iostream>
#include "parserdef.h"


using namespace std;

int main()
{
	Parser parser;

	parser.Open("in.txt");

	cout << parser;

	return 0;
}
