#include <iostream>
#include "parserdef.h"


using namespace std;

int main()
{
	Parser parser;

	parser.Open("in.txt");
	
	parser.addKeyword("keyword","symbol");

	cout << parser.getSymbolByWord("keyword");

	cout << parser;

	return 0;
}
