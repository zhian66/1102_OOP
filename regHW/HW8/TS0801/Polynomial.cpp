#include "Polynomial.h"

#pragma region constructor
Polynomial::Polynomial() {
	coefficients = {};
}

Polynomial::Polynomial(double* param, int size) {
	for (int i = 0; i < size; i++) {
		coefficients.push_back(param[i]);
	}
}
#pragma endregion constructor

int Polynomial::mySize() const {
	for (int i = coefficients.size() - 1; i >= 0; i--) {
		if (coefficients[i] != 0) {
			return i + 1;
		} 
	}
	return 0;
}

#pragma region operator=
Polynomial& Polynomial::operator=(const Polynomial& poly) {
	coefficients.resize(poly.coefficients.size());
	for (int i = 0; i < poly.coefficients.size(); i++) {
		coefficients[i] = poly.coefficients[i];
	}
	return *this;
}

Polynomial& Polynomial::operator=(const double& num) {
	coefficients.clear();
	coefficients.push_back(num);
	return *this;
}
#pragma endregion operator=

#pragma region operator[]
double& Polynomial::operator[](const int& index) {
	if (index < 0) return coefficients[0];
	while (index > coefficients.size() - 1)
		coefficients.push_back(0);
	return coefficients[index];
}
#pragma endregion operator[]

#pragma region operator+
Polynomial operator+(const Polynomial& p1, const Polynomial& p2) {
	Polynomial temp;
	int p1Size = p1.coefficients.size();
	int p2Size = p2.coefficients.size();
	int maxSize = std::max(p1Size, p2Size);
	temp.coefficients.resize(maxSize, 0);
	for (int i = 0; i < maxSize; i++) {
		int add = 0;
		if (i < p1Size)
			add += p1.coefficients[i];
		if (i < p2Size)
			add += p2.coefficients[i];
		temp.coefficients[i] = add;
	}
	return temp;
}

Polynomial operator+(const Polynomial& poly, const double& num) {
	Polynomial temp = poly;
	if (temp.coefficients.size() == 0) {
		temp.coefficients.push_back(num);
	} else {
		temp.coefficients[0] += num;
	}

	return temp;
}

Polynomial operator+(const double& num, const Polynomial& poly) {
	Polynomial temp = poly;
	if (temp.coefficients.size() == 0)
		temp.coefficients.push_back(num);
	else
		temp.coefficients[0] += num;
	return temp;
}
#pragma endregion operator+

#pragma region operator-

Polynomial operator-(const Polynomial& p1, const Polynomial& p2) {
	Polynomial temp;
	int p1Size = p1.coefficients.size();
	int p2Size = p2.coefficients.size();
	int maxSize = std::max(p1Size, p2Size);
	temp.coefficients.resize(maxSize, 0);
	for (int i = 0; i < maxSize; i++) {
		int sub = 0;
		if (i < p1Size)
			sub += p1.coefficients[i];
		if (i < p2Size)
			sub -= p2.coefficients[i];
		temp.coefficients[i] = sub;
	}
	return temp;
}

Polynomial operator-(const Polynomial& poly, const double& num) {
	Polynomial temp = poly;
	if (poly.coefficients.size() == 0)
		temp.coefficients.push_back(-num);
	else
		temp.coefficients[0] -= num;
	return temp;
}

Polynomial operator-(const double& num, const Polynomial& poly) {
	Polynomial temp = poly;
	if (poly.coefficients.size() == 0)
		temp.coefficients.push_back(num);
	else {
		for (auto& n : temp.coefficients) {
			n *= -1;
		}
		temp.coefficients[0] += num;
	}
	return temp;
}

#pragma endregion operator-

#pragma region operator*
Polynomial operator*(const Polynomial& p1, const Polynomial& p2) {
	Polynomial temp;
	int p1Size = p1.coefficients.size();
	int p2Size = p2.coefficients.size();
	int Size = p1Size + p2Size;
	temp.coefficients.resize(Size, 0);
	for (int i = 0; i < p1Size; i++) {
		for (int j = 0; j < p2Size; j++) {
			temp.coefficients[i + j] += p1.coefficients[i] * p2.coefficients[j];
		}
	}
	return temp;
}

Polynomial operator*(const Polynomial& poly, const double& num) {
	Polynomial temp = poly;
	for (auto& i:temp.coefficients) {
		i *= num;
	}
	return temp;
}

Polynomial operator*(const double& num, const Polynomial& poly) {
	Polynomial temp = poly;
	for (auto& i : temp.coefficients) {
		i *= num;
	}
	return temp;
}
#pragma endregion operator*

#pragma region function
double evaluate(const Polynomial& poly, const double& var) {
	double result = 0;
	double x = 1;
	for (int i = 0; i < poly.coefficients.size(); i++) {
		if(i) x *= var;
		result += (poly.coefficients[i] * x);
	}
	return result;
}
#pragma endregion function

/*
Polynomial q(quad, 3); // q is 3 + 2*x + x*x
Polynomial c(cubic, 4);// c is 1 + 2*x + 0*x*x + 3*x*x*x
q*c
77 - q
74 -2 -1(-2)
74 
1 + 2*x + 0*x*x + 3*x*x*x
(1, 2, 0, 3) * (1, 2, 0, 3) * (1, 2, 0, 3)
0  1  2  3  4  5  6  7
----------------------
1  2  0  3
   2  4  0  6
         3  6  0  9
		 ----------
1  4  4  6 12  0  9
1  2  0  3

0  1  2  3  4  5  6  7  8  9  10
--------------------------------
1  4  4  6 12  0  9
   2  8  8 12 24  0 18
         3 12 12 18 36  0 27
		 -------------------
1  6 12 17 36 36 27 54  0 27

*/