#include "Martix.h"

int main() {
	int ar, ac, br, bc;
	cin >> ar >> ac >> br >> bc;
	Matrix A(ar, ac), B(br, bc);
	A.getMatrix();
	B.getMatrix();
	A* B;
}
