#include "parserdef.h"
//Default Constructor:

Parser::Parser()
{
    Input = "";
    InputIndex = 0;
    
    CurrNum = 0;
	CommentLine = "";
	CommentStart = "";
	CommentEnd = "";

  
 


}

Parser::Parser(std::string input)
{
    Input = input;
 
    CurrNum = 0;
    InputIndex = 0;
	CommentLine = "";





}



