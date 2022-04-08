#pragma once
#include <iostream>
#include <vector>

class Polynomial {
private:
	std::vector <double> coefficients;
public:
	Polynomial();
	Polynomial(double* param, int size);
	int mySize() const;
	friend double evaluate(const Polynomial& poly, const double& var);

	Polynomial& operator=(const Polynomial& poly);
	Polynomial& operator=(const double& num);
	double& operator[](const int & index);

	friend Polynomial operator+(const Polynomial& p1, const Polynomial& p2);
	friend Polynomial operator+(const Polynomial& p1, const double& num);
	friend Polynomial operator+(const double & num, const Polynomial& poly);

	friend Polynomial operator-(const Polynomial& p1, const Polynomial& p2);
	friend Polynomial operator-(const Polynomial& poly, const double& num);
	friend Polynomial operator-(const double& num, const Polynomial& poly);

	friend Polynomial operator*(const Polynomial& p1, const Polynomial& p2);
	friend Polynomial operator*(const Polynomial& poly, const double& num);
	friend Polynomial operator*(const double& num, const Polynomial& poly);
};
