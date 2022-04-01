#include "Memory.h"

int main() {
	int SIZE, COMMAND;
	string command;
	int postion;

	cin >> SIZE >> COMMAND;
	Memory mem(SIZE);

	for (int line = 0; line < COMMAND; line++) {
		cin >> command >> postion;
		if (command == "Set") {
			mem.set(postion);
		} else if (command == "Get") {
			mem.get(postion);
		}
	}
}
