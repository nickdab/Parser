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
        std::string getInput();
        std::string getWordByIndex(int index);           //index follows normal cpp rules, i.e. the first in array is 0, NOT 1
        std::string getWordByName(std::string keyword);   //this gets the keyword by name
	std::string getSymbolByWord(std::string word);
        std::string getCommentLine();
        std::string getCommentStart();
        std::string getCommentEnd();
;

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

		//This member resets the InputIndex to 0
		void ResetInputIndex();


};








#endif // PARSERDEF_H
