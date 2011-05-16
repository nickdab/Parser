#include "parserdef.h"

//This ignores whitespace, providing an easy to understand method of getting input from the Input word by word

//This requires too much knowledge of the class, I know, but I didn't see how this would be useful if the index was built in. That would just return a word and increment the index from the start of the file to the end of the file. This is more useful because it returns a word from some index, allowing the user to return a word from some beginning point.

//note that this changes the given index

bool is_whitespace(char input)
{
	if((input == 0) || (input == ' ') || (input == '\t') || (input == 10) || (input == 14) || (input == 13) || (input == 9))
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

