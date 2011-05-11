#include "parserdef.h"
#include "keyword.h"

//Mutators:

void Parser::setInput(std::string input)
{
	Input = input;
}

void Parser::setWordByIndex(std::string word, int index)
{
	Keyword[index].Word = word;
}

void Parser::addKeyword(std::string word, std::string symbol)
{

	keyword new_keyword;
	new_keyword.Word = word;
       	new_keyword.Symbol = symbol;

	Keyword.push_back(new_keyword);

}

void Parser::setCommentLine(std::string comment_line)
{
	CommentLine = comment_line;
}

void Parser::setCommentStart(std::string start_comment)
{
	CommentStart = start_comment;
}

void Parser::setCommentEnd(std::string end_comment)
{
	CommentEnd = end_comment;
}
