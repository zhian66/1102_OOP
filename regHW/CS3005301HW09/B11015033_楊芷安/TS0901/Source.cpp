#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool translate(vector<vector<bool>> &trans, vector<bool> &visit, int origin, int target) {
	if (trans[origin][target] == 1) {
		return true;
	}
	visit[origin] = 1;
	bool result = false;
	for (int i = 0; i < 26; i++) {
		if (trans[origin][i] == 1 && visit[i] == 0) {
			result = translate(trans, visit, i, target);
			if (result == 1) break;
		}
	}
	return result;
}

int main() {
	int m, n;
	while (cin >> m >> n) {
		if (m == 0 && n == 0) break;
		vector<vector<bool>> trans(26, vector<bool>(26, 0));
		
		char first, second;
		for (int i = 0; i < m; i++) {
			cin >> first >> second;
			trans[(first - 'a')][(second - 'a')] = true;
		}
		
		string origin, target;
		for (int i = 0; i < n; i++) {
			cin >> origin >> target;
			bool matched = true;
			if (target.size() != origin.size()) {
				matched = false;
			} else {
				for (int j = 0; j < origin.size(); j++) {
					if (origin[j] == target[j]) {
						continue;
					}
					vector<bool> visit(26, 0);
					if (!translate(trans, visit, origin[j] - 'a', target[j] - 'a')) {
						matched = false;
						break;
					}
				}
			}

			if (matched) {
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
		}
		

	}
}



/*
44 7
a b
a c
a d
a e
a f
a g
a h
a i
a j
a k
a l
a m
a n
a o
a p
a q
a r
a s
a t
a u
a v
a w
a x
a y
a z
n t
t p
i s
p t
t u
l e
e h
h i
r t
h t
f p
u q
u e
e a
f j
t e
o f
s w
b e
apple ntust
exercise emphasize
befor begin
nhalsey taylornbillie
eilish youshouldseemeinacrown
aaaaaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaa
aaaaaa somethingjustlikethis
*/