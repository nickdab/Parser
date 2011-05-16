/*This class attempts to make it easier for a programmer to make a parser that examines some input text and parses out keywords,
special characters, etc...*/

#ifndef PARSERDEF_H
#define PARSERDEF_H


#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "keyword.h"

class Parser
{
    private:
    int CurrNum;                                        //keep track of how many keywords have been added.
	int InputIndex;					   					 // keep track of which character in the input we are on

   	std::string Input;                                  //This will define some input text
	std::vector<keyword> Keyword;				//I decided to use a vector rather than a linked list because--although vectors cost a lot more when adding, random accesses are much quicker than with a linked list. I can envision there being a lot of random accesses when it comes to keywords.

	std::string CommentLine;
	std::string CommentStart;
	std::string CommentEnd;


    public:
        //default constructor:
        Parser();                              //notice that a programmer MUST declare the number of keywords they will define before creating a parser. The easiest way to do this would be to make it a constant at the top of a program.

        //other constructors
        Parser(std::string input);           //this allows the programmer to create the parser with an input text

        //Accessors:
	bool 		EndOfFile();
        std::string getInput();
        std::string getWordByIndex(int index);           //index follows normal cpp rules, i.e. the first in array is 0, NOT 1
        std::string getWordByName(std::string keyword);   //this gets the keyword by name
	std::string getSymbolByWord(std::string word);
	int getKeywordSize();
        std::string getCommentLine();
        std::string getCommentStart();
        std::string getCommentEnd();


        //Mutators:
        void setInput(std::string input);

        void setWordByIndex( std::string word, int index);
        void addKeyword(std::string word, std::string symbol);
        void setCommentLine(std::string comment_line);
        void setCommentStart(std::string comment_start);
        void setCommentEnd(std::string comment_end);

        //Overloaded Operators:
        friend std::istream& operator>>(std::istream& in, Parser &parser);
        friend std::ostream& operator<<(std::ostream& out, Parser &parser);
		friend bool operator==(Parser &parser1, Parser &parser2);
		friend bool operator!=(Parser &parser1, Parser &parser2);

		//This class member opens a file and transfers its content to the Input member variable
		void Open(std::string file_name);

		//This memeber returns the next word after a given index
		std::string ReadNextWord();
		void ReplaceCurrWord(std::string new_word);

		//This member resets the InputIndex to 0
		void ResetInputIndex();


};
#endif // PARSERDEF_H

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

int Parser::getKeywordSize()
{
	int size = Keyword.size();

	return size;
}


std::istream& operator>>(std::istream& in, Parser& parser)
{
	/*I've changed this a lot. Now, it goes through the input, finds all of the comments, and ignores them.
	This takes that burden off of the programmer who uses this library to find  a way to ignore comments
	in the input.*/
    std::string in_text = "";
	char comment_line_first = parser.CommentLine[0];
	char comment_start_first = parser.CommentStart[0];

    if (in == std::cin) //if the parser is getting an input directly from the console, we have to use getline so that it can be terminated by the enter, or return key.
    {
        char user_input[256] = {};
        in.getline(user_input, 256);
        in_text = user_input;
    }
    else
    {
        char this_char = in.get();	//get the input character by character.
        while (in) //this loop exists while the input has not reached the end of file character
        {
			 if ((this_char == comment_line_first) || (this_char == comment_start_first))	//if the input character is the same as the first character of our ignore symbols, we need to check for the rest of the symbol.
			 {
					std::string rest_of_word = "";	//we already have the first character, so now we need to get the rest of the word.
					std::string full_word = "";		//this will store the character we already have, plus  the rest of the word that we got.

					//first we will check for the comment_line symbol:
					for (int i = 0; i < parser.CommentLine.size()-1; i++)
					{
					    char temp_in = in.get();
						rest_of_word = rest_of_word + temp_in;
					}

					full_word = this_char + rest_of_word;

					if (full_word == parser.CommentLine)
					{
						while (this_char != '\n' && in)
						{
							this_char = in.get(); //ignore the rest of the line
						}
					}
					else	//we need to put everything back and check for the other comment symbol.
					{
						for (int i = parser.CommentLine.size()-1; i>=0; i--) //we need to put this back in the exact opposite way we got it.
						{
							in.putback(full_word[i]);
						}

						full_word = "";

						for (unsigned int i = 0; i < parser.CommentStart.size(); i++)
						{
						    char temp_in = in.get();
							full_word = full_word + temp_in;
						}

						if(full_word == parser.CommentStart)
						{
							full_word = "";

							while (full_word != parser.CommentEnd)
							{
								this_char = in.get(); //ignore

								if (this_char == parser.CommentEnd[0])
								{
									rest_of_word = "";

									for (unsigned int i = 0; i < parser.CommentEnd.size()-1; i++)
									{
									    char temp_in = in.get();
										rest_of_word = rest_of_word + temp_in;
									}

									full_word = this_char + rest_of_word;

									if (full_word !=parser.CommentEnd)
									{
										full_word = "";
									}
								}
							}
						}
						else    //the input was not a comment. we need to add this to our input.
						{
							in_text = in_text + full_word;
						}
					}
            }
            else
            {
            in_text = in_text + this_char;
            }

        this_char = in.get();
        }
    }

    parser.Input = in_text;

    return in;
}

std::ostream& operator<<(std::ostream& out, Parser& parser)
{
    out << parser.Input;

    return out;
}



bool  operator==(Parser& parser1, Parser& parser2)
{
        if (parser1.Input != parser2.Input)
        {
            return false;
        }

    for (int i = 0; i < parser1.Keyword.size(); i++)
    {
        if (parser1.Keyword[i].Word != parser2.Keyword[i].Word)
        {
            return false;
        }
    }

    return true;
}

bool operator!=(Parser& parser1, Parser& parser2)
{
      if (parser1.Input != parser2.Input)
        {
            return true;
        }

    for (int i = 0; i < parser1.Keyword.size(); i++)
    {
        if (parser1.Keyword[i].Word != parser2.Keyword[i].Word)
        {
            return true;
        }
    }

    return false;
}

void Parser::Open(std::string file_name)
{
	std::ifstream input;
	input.open(file_name.c_str());

	if (!input)
	{
		Input = "[Parser Error]Open: file name \"" + file_name + "\" could not be read. Check if it exists.\n";
		input.close();
		return;
	}

	    Parser temp;

	    temp.setCommentLine(CommentLine);
	    temp.setCommentStart(CommentStart);
	    temp.setCommentEnd(CommentEnd);

	    input >> temp;

	    Input = temp.Input;

	input.close();
}

//This ignores whitespace, providing an easy to understand method of getting input from the Input word by word

//This requires too much knowledge of the class, I know, but I didn't see how this would be useful if the index was built in. That would just return a word and increment the index from the start of the file to the end of the file. This is more useful because it returns a word from some index, allowing the user to return a word from some beginning point.

//note that this changes the given index

bool is_whitespace(char input)
{
	if((input == 0) || (input == ' ') || (input == '\t') || (input == 10) || (input == 14) || (input == 13) || (input == 9) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Parser::ResetInputIndex()
{
    InputIndex = 0;
}

std::string Parser::ReadNextWord()
{
	char curr_char;
	std::string word = "";

	curr_char = Input[InputIndex];


	while ((is_whitespace(curr_char)) && (InputIndex <= Input.size()))
	{
		InputIndex++;
		curr_char = Input[InputIndex];
	}

	while ((is_whitespace(curr_char) == false) && (InputIndex <=Input.size()))
	{
		word = word + curr_char;
		InputIndex++;
		curr_char = Input[InputIndex];
	}

	return word;
}

void Parser::ReplaceCurrWord(std::string new_word)
{
	int temp_index = InputIndex;
	temp_index--;
	int word_end = temp_index+1;
	std::string word = "";
	char curr_char = Input[temp_index];

	while ((!is_whitespace(curr_char)) && (InputIndex >= 0))
	{
		word = word + curr_char;
		temp_index--;
		curr_char = Input[temp_index];
	}

	int word_start = temp_index+1;

	Input.replace(word_start,word_end-word_start,new_word);

}
//accessors:

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
