#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;

typedef struct BigInt {
    int size;
    string str;
    vector<int> num;
} BigInt;

void Str2Vector(BigInt& result) {
    result.size = result.str.size();
    result.num.resize(result.size);
    for (int i = 0; i < result.size; i++) {
        result.num[i] = result.str[result.size - i - 1] - '0';
    }
}

BigInt Add(const BigInt& lhs, const BigInt& rhs) {
    // Calculation
    int max_size = lhs.size;
    if (max_size < rhs.size)
        max_size = rhs.size;
    BigInt result;
    result.num.resize(max_size + 1);
    result.size = max_size;
    int i, c = 0;
    for (i = 0; i < max_size; i++) {
        int add = 0;
        if (i < lhs.size)
            add += lhs.num[i];
        if (i < rhs.size)
            add += rhs.num[i];
        if (c)
            add += c;
        if (add >= 10) {
            add -= 10;
            c = 1;
        }
        else {
            c = 0;
        }
        result.num[i] = add;
    }
    if (c) {
        result.num[i] = c;
        result.size++;
    }
    return result;
}

bool isNumber(const string str) {
    for (auto x : str) {
        if (!isdigit(x)) return false;
    }
    return true;
}

int main() {
    BigInt a, b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a.str >> b.str;
        if (isNumber(a.str) && isNumber(b.str)) {
            Str2Vector(a);
            Str2Vector(b);
            BigInt result = Add(a, b);
            for (int i = result.size - 1; i >= 0; i--) {
                cout << result.num[i];
            }
            cout << endl;
        }
        else {
            cout << "Not a valid number, please try again." << endl;
        }
    }
}
