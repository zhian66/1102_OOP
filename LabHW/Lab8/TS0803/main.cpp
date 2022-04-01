#include <iostream>
#include <vector>
#include <string>
#define ERROR_MSM "Violation Access."
using namespace std;

class Memory {
private:
	int SIZE;
	char* MEM;
public:
	Memory(int size);
	~Memory();
	void set(int pos);
	void get(int pos);
};

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
	// TYPE: char(1 Byte), short(2 Bytes), int(4 Bytes), String(Until '\0')
	string TYPE;
	cin >> TYPE;
	// NOTICE: If the size of value exceeds the size of type, the excess part will be ignored.
	// NOTICE: If overflow occurs (position + type size > N), please output "Violation Access".
	// NOTICE: If access postion add type size is bigger than the memory size, we still need to set the data to memory.
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
		memcpy(&output, &MEM[POS], sizeof(char)); // copy sizeof(char) address of MEM[POS] to output's address
		cout << output << endl;

	} else if (TYPE == "short") {
		if (POS + 2 > SIZE) {
			cout << ERROR_MSM << endl;
			return;
		}
		unsigned short output = 0;
		memcpy(&output, &MEM[POS], sizeof(unsigned short));
		cout << output << endl;

	} else if (TYPE == "int") {
		if (POS + 4 > SIZE) {
			cout << ERROR_MSM << endl;
			return;
		}
		unsigned int output = 0;
		memcpy(&output, &MEM[POS], sizeof(unsigned int));
		cout << output << endl;
	}
}


int main() {
	int SIZE, COMMAND;
	string command;
	int postion;

	cin >> SIZE >> COMMAND;
	Memory mem(SIZE);

	for (int line = 0; line < COMMAND; line++) {
		cin >> command >> postion;
		if (command == "Set") {
			// COMMAND: Set <position> <type> <value>
			mem.set(postion);
		} else if (command == "Get") {
			// COMMAND: GET <position> <type>
			mem.get(postion);
		}
	}
}
