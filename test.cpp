#include <iostream>
#include "parserdef.h"


using namespace std;

int main()
{
	Parser parser;

	parser.setCommentStart("/*");
	parser.setCommentEnd("*/");
	parser.setCommentLine("//");

	parser.Open("in.txt");

	cout << parser;

	return 0;
}
