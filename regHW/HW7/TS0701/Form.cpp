#include "Form.h"

void Form::SetInputWord(std::string inputWord) {
	Word = inputWord;
}

void Form::ProcessInputWord() {
	letter = countLetter(Word);
}

void Form::SetFileName(std::string filename) {
	FileName = filename;
}

void Form::Load_CompareWord() {
	std::ifstream fin(FileName);
	std::string word;
	while (fin >> word) {
		std::vector<int> word_letter = countLetter(word);
		bool isSub = true;
		for (int i = 0; i < 26; i++) {
			if (word_letter[i] > letter[i]) {
				isSub = false;
				break;
			}
		}
		if (isSub) {
			FoundWord.push_back(word);
		}
	}
}

void Form::PrintFoundWords() {
	for (std::string word : FoundWord) {
		std::cout << word << std::endl;
	}
}

std::vector<int> Form::countLetter(std::string input) {
	std::vector<int> letter(26, 0);
	for (auto& s : input) {
		letter[tolower(s) - 'a']++;
	}
	return letter;
}

