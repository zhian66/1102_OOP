#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Cowculation {
private:
	string Num1, Num2, result;
	int num1, num2;
	char op[3];
	int convert(string);

public:
	Cowculation();
	void Cowculate();
};

Cowculation::Cowculation() {
	cin >> Num1 >> Num2;
	cin >> op[0];// >> op[1] >> op[2];
	cin >> result;
}

int Cowculation::convert(string str) {
	int convertInt = 0;
	for (char x : str) {
		switch (x) {
		case 'V': convertInt = convertInt * 4 + 0; break;
		case 'U': convertInt = convertInt * 4 + 1; break;
		case 'C': convertInt = convertInt * 4 + 2; break;
		case 'D': convertInt = convertInt * 4 + 3; break;
		}
	}
	return convertInt;
}


void Cowculation::Cowculate() {
	num1 = convert(Num1);
	num2 = convert(Num2);
	for (int i = 0; i < 1; i++) {
		if (op[i] == 'A') {
			num2 = num1 + num2;
		} else if (op[i] == 'R') {
			num2 /= 4;
		} else if (op[i] == 'L') {
			num2 *= 4;
		} else {}
	}
	cout << num2 << " " << convert(result) << endl;
	if (num2 == convert(result)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}



int  main() {
	int line;

	cin >> line;
	cout << "COWCULATIONS OUTPUT" << endl;
	for (int l = 0; l < line; l++) {
		Cowculation Cow;
		Cow.Cowculate();
	}
	cout << "END OF OUTPUT" << endl;
}
