#include "Memory.h"

Memory::Memory(int size) {
	SIZE = size;
	MEM = new char[SIZE + 4];
	for (int i = 0; i < SIZE + 4; i++) {
		MEM[i] = 0;
	}
}

Memory::~Memory() {
	delete[] MEM;
}

void Memory::set(const int POS) {
	string TYPE;
	cin >> TYPE;

	if (TYPE == "int") {
		unsigned int input;
		cin >> input;
		if (POS + 4 > SIZE) {
			cout << ERROR_MSM << endl;
		}
		memcpy(&MEM[POS], &input, sizeof(unsigned int)); // copy b to a

	} else if (TYPE == "short") {
		unsigned short input;
		cin >> input;
		if (POS + 2 > SIZE) {
			cout << ERROR_MSM << endl;
		}
		memcpy(&MEM[POS], &input, sizeof(unsigned short));

	} else if (TYPE == "char") {
		unsigned short input;
		cin >> input;
		memcpy(&MEM[POS], &input, sizeof(char));

	} else if (TYPE == "String") {
		string input;
		getline(cin, input);
		if (POS + input.size() > SIZE) {
			cout << ERROR_MSM << endl;
		}

		memcpy(&MEM[POS], (input.substr(1, input.length())).c_str(), input.length());
	}
}

void Memory::get(const int POS) {
	string TYPE;
	cin >> TYPE;


	if (TYPE == "String") {
		if (POS > SIZE) {
			cout << ERROR_MSM << endl;
			return;
		}
		for (int ptr = POS; ptr < SIZE; ptr++) {
			if (MEM[ptr] == 0) {
				break;
			}
			cout << MEM[ptr];
		}
		cout << endl;

	} else if (TYPE == "char") {
		if (POS + 1 > SIZE) {
			cout << ERROR_MSM << endl;
			return;
		}
		unsigned short output = 0;
		memcpy(&output, &MEM[POS], sizeof(char)); // copy a to s
		cout << output << endl;

	} else if (TYPE == "short") {
		if (POS + 2 > SIZE) {
			cout << ERROR_MSM << endl;
			return;
		}
		unsigned short output = 0;
		memcpy(&output, &MEM[POS], sizeof(unsigned short)); // copy a to s
		cout << output << endl;

	} else if (TYPE == "int") {
		if (POS + 4 > SIZE) {
			cout << ERROR_MSM << endl;
			return;
		}
		unsigned int output = 0;
		memcpy(&output, &MEM[POS], sizeof(unsigned int)); // copy a to s
		cout << output << endl;
	}
}
