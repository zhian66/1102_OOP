#include <iostream>
#include <fstream>
#include <vector>
#include<string>

class Form
{
private:
	std::string Word;
	std::string FileName;
	std::vector<int> letter;
	std::vector<std::string> FoundWord;

public:
	std::vector<int> countLetter(std::string input);
	void SetInputWord(std::string inputWord); // set input
	void ProcessInputWord(); // process input
	void SetFileName(std::string fileName); // set file name
	void Load_CompareWord(); // read-in data and compare
	void PrintFoundWords(); // print answers
};

