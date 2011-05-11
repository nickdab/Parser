#include "parserdef.h"
#include "keyword.h"

bool Parser::EndOfFile()
{
	if (InputIndex >= Input.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string Parser::getInput()
{
    return Input;
}

std::string Parser::getWordByIndex(int index)
{
    std::string err_msg = "";

    if (index >= Keyword.size())
    {
        err_msg = "[Parser Error]GetKeywordByIndex: index out of bounds.\n";
        return err_msg;
    }

    return Keyword[index].Word;
}

std::string Parser::getWordByName(std::string name)
{
    std::string err_msg = "";

    for (int i = 0; i < Keyword.size(); i++)
    {
        if ( Keyword[i].Word == name)
        {
            return Keyword[i].Word;
        }
    }

    err_msg = "[Parser Error]GetKeywordByName: no keyword matched argument \"" + name + "\"\n";

    return err_msg;
}

std::string Parser::getSymbolByWord(std::string word)
{
	for (int i = 0; i < Keyword.size(); i++)
	{
		if (Keyword[i].Word == word)
		{
			return Keyword[i].Symbol;
		}
	}

	std::string err_msg = "[Parser Error]GetSymbolByWord: no word matched argument \"" + word + "\"\n";

	return err_msg;
}





std::string Parser::getCommentLine()
{
	return CommentLine;
}

std::string Parser::getCommentStart()
{
	return CommentStart;
}

std::string Parser::getCommentEnd()
{
	return CommentEnd;
}
