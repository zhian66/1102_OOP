#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LDistance {
private:
	vector<vector<int>> distance;
	string source, target;
	int MIN(int a, int b, int c);
	void CountDistance();

public:
	LDistance();
	LDistance(string str1, string str2);
	int getDistance();
	void printDistance();
};

int LDistance::MIN(int a, int b, int c) {
	if (a <= b && a <= c) return a;
	else if (b <= a && b <= c) return b;
	return c;
}

LDistance::LDistance() {}
LDistance::LDistance(string str1, string str2) {
	source = str1;
	target = str2;
	distance.resize(source.size() + 1);
	for (int i = 0; i < source.size() + 1; i++) {
		distance[i].resize(target.size() + 1);
	}
}

void LDistance::CountDistance() {
	for (int i = 0; i <= source.size(); i++) {
		distance[i][0] = i;
	}
	for (int j = 0; j <= target.size(); j++) {
		distance[0][j] = j;
	}

	for (int i = 1; i <= source.size(); i++) {
		for (int j = 1; j <= target.size(); j++) {
			int dele = distance[i - 1][j] + 1;
			int insert = distance[i][j - 1] + 1;
			int change = (source[i - 1] == target[j - 1]) ? distance[i - 1][j - 1] : distance[i - 1][j - 1] + 1;
			distance[i][j] = MIN(dele, insert, change);
		}
	}
}

int LDistance::getDistance() {
	CountDistance();
	return distance[source.size()][target.size()];
}


int main() {
	string str1, str2;
	while (getline(cin, str1) && getline(cin, str2)) {
		LDistance LD(str1, str2);
		cout << LD.getDistance() << endl;
	}
}
