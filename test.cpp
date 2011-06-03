#include <iostream>
#include "parserdef.h"


using namespace std;

int main()
{
	string test1 = "hello, world, I would like to know how you all are today.", test2 = "everybody.";
	Parser parser;

	parser.setInput(test1);

	cout << parser << endl;

	parser.ReadNextWord();
	parser.ReadNextWord();

	parser.ReplaceCurrWord(test2);

	cout << parser<<endl;

	return 0;
}
